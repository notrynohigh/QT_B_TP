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
#include "utc2000/calendar.h"
#include <QFileInfo>

static uint32_t ok_number_count = 0;
static uint32_t err_number_count = 0;

extern "C" void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);
extern "C" void b_tp_callback(uint8_t *pbuf, uint32_t len);

uartClass uartModule;
bleDev  bleDevModule;
BLE_TOOLS *tmpClass;
bleDevInfo_t g_tmp_dev;

bool collect_flag = false;
char collect_status = 0;

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
    QString str = QString("%1").arg(ok_number_count);
    ui->ok_number_txt->setText(str);
    QString str_err = QString("%1").arg(err_number_count);
    ui->err_number_txt->setText(str_err);

}


BLE_TOOLS::~BLE_TOOLS()
{
    if(uartModule.uartGetOpenStatus())
    {
        uartModule.uartClosePort();
    }
    save_mac();
    bleDevModule.clear();
    delete ui;
}

void BLE_TOOLS::on_opencom_clicked()
{
    if(uartModule.uartGetOpenStatus())
    {
        uartModule.uartClosePort();
        ui->COMx->setEnabled(true);
        ui->opencom->setText("打开串口");
    }
    else
    {
        if(uartModule.uartOpenPort(ui->COMx->currentText()))
        {
            ui->COMx->setEnabled(false);
            ui->opencom->setText("关闭串口");
            tc_get_connect_status();
        }
    }
}

void BLE_TOOLS::on_scan_clicked()
{
    if(uartModule.uartGetOpenStatus())
    {
        if(ui->scan->text() == "开始扫描")
        {
            ui->scan->setText("停止扫描");
            tc_scan_start();
            collect_flag = true;
            collect_status = 1;

        }
        else
        {
            ui->scan->setText("开始扫描");
            tc_scan_stop();
            collect_flag = false;
            collect_status = 0;
        }
    }
}

char _100ms_delay = 0;

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
        tc_send_hb();
        updateBleDevList();
    }


    if(collect_status == 2)
    {
        _100ms_delay++;
        if(_100ms_delay > 10)
        {
            pro_connect_info_t connect_info;
            memcpy(connect_info.addr, g_tmp_dev.addr, 6);
            tc_send(CMD_TOOL_CONNECT, 0, (uint8_t *)&connect_info, sizeof(pro_connect_info_t));
            collect_status = 3;
            _100ms_delay = 0;
        }
    }


    dispatch_cmd(t_buf, t_buf_len);
    t_buf_len = 0;
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
        //ui->uartRecText->clear();
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
    //ui->uartRecText->append(str);
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

static pro_rt_detail_response_t s_deteil = {

    .flag = 0,
};

void BLE_TOOLS::dispatch_cmd(uint8_t *pbuf, uint32_t len)
{
    bleDevList_t *ptmp = nullptr;
    uint8_t proTable[256];
    int pro_len;
    uint8_t off = STRUCT_OFF(tcmd_struct_t, buf);
    uint8_t off_2;
    if(len < off)
    {
        return;
    }
    tcmd_struct_t *result = (tcmd_struct_t *)pbuf;

    switch (result->cmd) {
    case CMD_TOOL_CONN_STA:
        {
            pro_conn_sta_t *resp = (pro_conn_sta_t *)(result->buf);
            if(resp->status == 0x1)
            {
                //ui->conn_label->setText("连接成功......");
            }
            else if(resp->status == 0x2)
            {
                if(collect_status == 3)
                {
                    collect_status = 4;
                    tc_get_breakdown();
                }
            }
            else
            {
                //ui->conn_label->setText("连接断开......");
                if(collect_status == 5 && collect_flag)
                {
                    tc_scan_start();
                    collect_status = 1;
                }
            }
        }
        break;
    case CMD_TOOL_SCAN:
        {
            pro_scan_response_t *resp = (pro_scan_response_t *)(result->buf);
            if(collect_flag && collect_status == 1)
            {
                if(0 == strncmp((char *)resp->name, "Odun_xxxx", 9))
                {
                    g_tmp_dev.rssi = resp->rssi;
                    memcpy(g_tmp_dev.name, resp->name, 16);
                    memcpy(g_tmp_dev.addr, resp->addr, 6);
                    ptmp = bleDevModule.bleFindFromList(g_tmp_dev);
                    if(ptmp != nullptr)
                    {
                        break;
                    }
                    collect_status = 2;
                    tc_scan_stop();
                }
                else
                {
                    break;
                }
            }
            else if(!collect_flag)
            {
                memcpy(g_tmp_dev.addr, resp->addr, 6);
                g_tmp_dev.rssi = resp->rssi;
                memcpy(g_tmp_dev.name, resp->name, 16);
                bleDevModule.bleAddDev(g_tmp_dev);
            }
        }
        break;
    case CMD_GET_BREAKDOWN:
        {
            pro_breakdown_info_t *pdeteil = (pro_breakdown_info_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "flash ok?:\t%d\tmems ok?\t%d\t",pdeteil->flash_breakdown, pdeteil->mems_breakdown);
            textShowString(proTable, pro_len);
            if(collect_status == 4)
            {
                if(pdeteil->flash_breakdown == 0 && pdeteil->mems_breakdown == 0)
                {
                    char tmp_table[6];
                    for(char i = 0;i < 6;i++)
                    {
                        tmp_table[i] = g_tmp_dev.addr[5 - i];
                    }
                    QString str1 = QByteArray::fromRawData((const char *)(tmp_table), 6).toHex().data();
                    ui->mac_list->addItem(str1);
                    tc_set_normal_mode();
                    ok_number_count++;
                    QString str = QString("%1").arg(ok_number_count);
                    ui->ok_number_txt->setText(str);
                }
                else
                {
                    bleDevModule.bleAddDev(g_tmp_dev);
                    tc_set_reboot();
                    err_number_count++;
                    QString str_err = QString("%1").arg(err_number_count);
                    ui->err_number_txt->setText(str_err);
                }
                collect_status = 5;
            }
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
        textShowData(pbuf, len);
    }
}



void b_tp_callback(uint8_t *pbuf, uint32_t len)
{
    uint8_t off = STRUCT_OFF(tcmd_struct_t, buf);
    if(len < off)
    {
        return;
    }
    memcpy(tmpClass->t_buf, pbuf, len);
    tmpClass->t_buf_len = len;
}



void BLE_TOOLS::on_clear_list_clicked()
{
    if(bleDevModule.clear())
    {
        ui->listWidget->clear();
    }
}

void BLE_TOOLS::save_mac()
{
    QFile file("C:\\Odun_mac.txt");
    if(! file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        textShowString((uint8_t *)"failed to open file", 19);
        return;
    }
    int len = ui->mac_list->count();
    QString item_text;
    for(int i = 0;i < len;i++)
    {
        item_text = ui->mac_list->item(i)->text();
        item_text += "\r\n";
        file.write((const char *)item_text.toLocal8Bit());
    }
    file.close();
    textShowString((uint8_t *)"save successfully", 17);
}


void BLE_TOOLS::on_listWidget_doubleClicked(const QModelIndex &index)
{
    pro_connect_info_t connect_info;
    bleDevInfo_t *pdev;
    if(ui->scan->text() == "Stop")
    {
       return;
    }
     return;
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
    //ui->uartRecText->clear();
}

void BLE_TOOLS::on_refresh_com_clicked()
{
    ui->COMx->clear();
    uartModule.uartRefreshCOM();
    ui->COMx->addItems(uartModule.uartComAvailable);
}


void BLE_TOOLS::on_clear_proto_result_clicked()
{
    ui->protocol_result->clear();
}

void BLE_TOOLS::on_savemac_clicked()
{
    save_mac();
    ui->mac_list->clear();
    ok_number_count = 0;
    err_number_count = 0;
    QString str = QString("%1").arg(ok_number_count);
    ui->ok_number_txt->setText(str);
    QString str_err = QString("%1").arg(err_number_count);
    ui->err_number_txt->setText(str_err);

}

