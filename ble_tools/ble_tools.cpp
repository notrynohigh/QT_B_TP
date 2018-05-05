#include "ble_tools.h"
#include "ui_ble_tools.h"
#include <qcombobox.h>
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>
#include "b_tp/inc/b_tp.h"
#include <qtimer.h>
#include <qthread.h>
#include "uartclass.h"

extern "C" void b_tp_port_uart_send(uint8_t *pbuf, uint32_t len);
extern "C" void b_tp_callback(uint8_t *pbuf, uint32_t len);

uartClass uartMode;

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
    uartMode.uartB_TP_Send((uint8_t *)"hello world", 11);
}

void BLE_TOOLS::on_timer_timeout()
{
    uint32_t len;
    len = uartMode.uartReadBuff(&recTable[recDataLen]);
    if(len > 0)
    {
        recDataLen += len;
    }
    else if(recDataLen > 0)
    {
        textShowData(recTable, recDataLen);
        if(recDataLen <= 20)
        {
            b_tp_receive_data(recTable, recDataLen);
        }
        recDataLen = 0;
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
    QThread::msleep(100);
}


void b_tp_callback(uint8_t *pbuf, uint32_t len)
{
    tmpClass->textShowData(pbuf, len);
}


