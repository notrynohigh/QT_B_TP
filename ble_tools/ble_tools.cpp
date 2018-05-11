#include "ble_tools.h"
#include "ui_ble_tools.h"
#include <qcombobox.h>
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>
#include "b_tp/inc/b_tp.h"
#include <qtimer.h>
#include <qthread.h>
#include "uartclass.h"
#include "tcmd/tool_cmd.h"
#include "bledev.h"
#include <qlistwidget.h>
#include <qdatetime.h>

extern "C" void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);
extern "C" void b_tp_callback(uint8_t *pbuf, uint32_t len);

uartClass uartModule;
bleDev  bleDevModule;
BLE_TOOLS *tmpClass;

BLE_TOOLS::BLE_TOOLS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BLE_TOOLS)
{
    ui->setupUi(this);

    quartTimer = new QTimer(this);
    quartTimer->setSingleShot(true);
    connect(quartTimer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    quartTimer->start(20);

    ui->COMx->addItems(uartModule.uartComAvailable);
    tmpClass = this;

    b_tp_reg_callback(b_tp_callback);
}


BLE_TOOLS::~BLE_TOOLS()
{

    if(uartModule.uartGetOpenStatus())
    {
        uartModule.uartClosePort();
    }
    bleDevModule.clear();
    delete ui;
}

void BLE_TOOLS::on_opencom_clicked()
{
    if(uartModule.uartGetOpenStatus())
    {
        uartModule.uartClosePort();
        ui->COMx->setEnabled(true);
        ui->opencom->setText("Open");
    }
    else
    {
        if(uartModule.uartOpenPort(ui->COMx->currentText()))
        {
            ui->COMx->setEnabled(false);
            ui->opencom->setText("Close");
        }
    }
}

void BLE_TOOLS::on_scan_clicked()
{
    if(uartModule.uartGetOpenStatus())
    {
        if(ui->scan->text() == "Scan")
        {
            ui->scan->setText("Stop");
            tc_scan_start();
        }
        else
        {
            ui->scan->setText("Scan");
            tc_scan_stop();
        }
    }
}

void BLE_TOOLS::timer_timeout()
{
    uint32_t len;
    uint8_t tmp_buf[1024];
    len = uartModule.uartReadBuff(tmp_buf);

    if(len > 0)
    {
        if(len <= 20)
        {
            tmpClass->textShowData(tmp_buf, len);
        }
        b_tp_receive_data(tmp_buf, len);
    }

    static uint32_t time20ms_count = 0;
    time20ms_count++;
    if(time20ms_count > 50)
    {
        time20ms_count = 0;
        updateBleDevList();
    }
    quartTimer->start(20);
}

void BLE_TOOLS::textShowData(uint8_t *pbuf, uint32_t len)
{
    QByteArray buf_tmp;
    QString str, str1;
    static uint8_t show_count = 0;
    if(show_count > 15)
    {
        show_count = 0;
        ui->uartRecText->clear();
    }
    buf_tmp = QByteArray::fromRawData((const char *)pbuf, len);
    str1 = buf_tmp.toHex().data();
    str1 = str1.toUpper();
    for(int i = 0;i < str1.length (); i += 2)
    {
        QString st = str1.mid (i,2);
        str += st;
        str += " ";
    }
    ui->uartRecText->append(str);
    show_count++;
}

void BLE_TOOLS::textShowString(uint8_t *pbuf, uint32_t len)
{
    ui->protocol_result->append(QString::fromLocal8Bit((const char *)pbuf, len));
}

void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len)
{
    uartModule.uartSendBuff(pbuf, len);
    QThread::msleep(100);
}



void BLE_TOOLS::updateBleDevList()
{
    bleDevInfo_t dev, *pdev;
    ui->listWidget->clear();
    uint32_t number = bleDevModule.getBleDevNumber();
    uint32_t i = 0;

    for(i = 0;i < number;i++)
    {
        pdev = bleDevModule.getBleDev(i);
        if(pdev != nullptr)
        {
            memcpy(&dev, pdev, sizeof(bleDevInfo_t));
            QString str = bleDevModule.getBleDevInfoStr(dev);
            ui->listWidget->addItem(str);
        }
    }
}


void b_tp_callback(uint8_t *pbuf, uint32_t len)
{
    bleDevInfo_t dev;
    uint8_t proTable[256];
    int pro_len;
    uint8_t off = STRUCT_OFF(tcmd_struct_t, buf);
    if(len < off)
    {
        return;
    }
    tcmd_struct_t *result = (tcmd_struct_t *)pbuf;

    switch (result->cmd) {
    case CMD_TOOL_SCAN:
        {
            pro_scan_response_t *resp = (pro_scan_response_t *)(result->buf);
            memcpy(dev.addr, resp->addr, 6);
            dev.rssi = resp->rssi;
            memcpy(dev.name, resp->name, 16);
            bleDevModule.bleAddDev(dev);
        }
        break;
    case CMD_GET_TIME:
        {
            pro_time_t *resptime = (pro_time_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "dev: %02d-%02d-%02d %02d:%02d:%02d ", resptime->year, resptime->month, resptime->day, resptime->hour, resptime->minute, resptime->second);
            tmpClass->textShowString(proTable, pro_len);
        }
        break;
    case CMD_VERSION:
        {
            pro_version_t *respversion = (pro_version_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "code %d version: hw %d fw %d algo: %d protocol: %d",respversion->internal_code,  respversion->hw_version, respversion->fw_version, respversion->algo_version, respversion->protocol_version);
            tmpClass->textShowString(proTable, pro_len);
        }
        break;
    default:
        {
            tc_send(CMD_TOOL_SCAN, CMD_STATUS_UNKNOWN, NULL, 0);
        }
        break;
    }
    if(result->cmd != CMD_TOOL_SCAN)
    {
        tmpClass->textShowData(pbuf, len);
    }
}



void BLE_TOOLS::on_clear_list_clicked()
{
    if(bleDevModule.clear())
    {
        ui->listWidget->clear();
    }
}




void BLE_TOOLS::on_listWidget_doubleClicked(const QModelIndex &index)
{
    pro_connect_info_t connect_info;
    bleDevInfo_t *pdev;
    if(ui->scan->text() == "Stop")
    {
       return;
    }
    uint32_t i = index.row();
    pdev = bleDevModule.getBleDev(i);
    if(pdev != nullptr)
    {
        memcpy(connect_info.addr, pdev->addr, 6);
        tc_send(CMD_TOOL_CONNECT, 0, (uint8_t *)&connect_info, sizeof(pro_connect_info_t));
    }
}

void BLE_TOOLS::on_clear_log_clicked()
{
    ui->uartRecText->clear();
}

void BLE_TOOLS::on_refresh_com_clicked()
{
    ui->COMx->clear();
    uartModule.uartRefreshCOM();
    ui->COMx->addItems(uartModule.uartComAvailable);
}

void BLE_TOOLS::on_setDate_clicked()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    tc_set_date(current_date_time.date().year(), current_date_time.date().month(), current_date_time.date().day(),
                current_date_time.time().hour(), current_date_time.time().minute(), current_date_time.time().second());
}

void BLE_TOOLS::on_getdata_clicked()
{
    tc_get_date();
}

void BLE_TOOLS::on_version_clicked()
{
    tc_get_version();
}

void BLE_TOOLS::on_total_steps_clicked()
{
    tc_get_total_step();
}
