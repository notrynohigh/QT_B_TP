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


extern "C" void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);
extern "C" void b_tp_callback(uint8_t *pbuf, uint32_t len);

uartClass uartMode;
bleDev  bleDevMode;
BLE_TOOLS *tmpClass;

BLE_TOOLS::BLE_TOOLS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BLE_TOOLS)
{
    ui->setupUi(this);

    quartTimer = new QTimer(this);
    connect(quartTimer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
    quartTimer->start(20);

    ui->COMx->addItems(uartMode.uartComAvailable);
    tmpClass = this;

    b_tp_reg_callback(b_tp_callback);
}


BLE_TOOLS::~BLE_TOOLS()
{
    delete ui;
    if(uartMode.uartGetOpenStatus())
    {
        uartMode.uartClosePort();
    }
}

void BLE_TOOLS::on_opencom_clicked()
{
    if(uartMode.uartGetOpenStatus())
    {
        uartMode.uartClosePort();
        ui->COMx->setEnabled(true);
        ui->opencom->setText("Open");
    }
    else
    {
        if(uartMode.uartOpenPort(ui->COMx->currentText()))
        {
            ui->COMx->setEnabled(false);
            ui->opencom->setText("Close");
        }
    }
}

void BLE_TOOLS::on_scan_clicked()
{
    if(uartMode.uartGetOpenStatus())
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

void BLE_TOOLS::on_timer_timeout()
{
    uint32_t len;
    uint32_t i;
    len = uartMode.uartReadBuff(&recTable[recDataLen]);
    if(len > 0)
    {
        recDataLen += len;
    }
    else if(recDataLen > 0)
    {
        textShowData(recTable, recDataLen);
        if(recDataLen <= B_TP_MTU)
        {
            b_tp_receive_data(recTable, recDataLen);
        }
        else
        {
            for(i = 0;i < (recDataLen / B_TP_MTU); i++)
            {
                b_tp_receive_data(&recTable[i * B_TP_MTU], B_TP_MTU);
            }
            if(recDataLen % B_TP_MTU)
            {
                b_tp_receive_data(&recTable[i * B_TP_MTU], (recDataLen % B_TP_MTU));
            }
        }
        recDataLen = 0;
    }

    static uint32_t time20ms_count = 0;
    time20ms_count++;
    if(time20ms_count > 50)
    {
        time20ms_count = 0;
        updateBleDevList();
    }

}

void BLE_TOOLS::textShowData(uint8_t *pbuf, uint32_t len)
{
    QByteArray buf_tmp;
    QString str, str1;
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
}


void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len)
{
    uartMode.uartSendBuff(pbuf, len);
}



void BLE_TOOLS::updateBleDevList()
{
    bleDevInfo_t dev, *pdev;
    ui->listWidget->clear();
    uint32_t number = bleDevMode.getBleDevNumber();
    uint32_t i = 0;

    for(i = 0;i < number;i++)
    {
        pdev = bleDevMode.getBleDev(i);
        if(pdev != nullptr)
        {
            memcpy(&dev, pdev, sizeof(bleDevInfo_t));
            QString str = bleDevMode.getBleDevInfoStr(dev);
            ui->listWidget->addItem(str);
        }
    }
}


void b_tp_callback(uint8_t *pbuf, uint32_t len)
{
    tmpClass->textShowData(pbuf, len);
    bleDevInfo_t dev;
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
            bleDevMode.bleAddDev(dev);
        }
        break;
    default:
        {
            tc_send(CMD_TOOL_SCAN, CMD_STATUS_UNKNOWN, NULL, 0);
        }
        break;
    }


}



void BLE_TOOLS::on_clear_list_clicked()
{
    if(bleDevMode.clear())
    {
        ui->listWidget->clear();
        ui->uartRecText->clear();
    }
}



