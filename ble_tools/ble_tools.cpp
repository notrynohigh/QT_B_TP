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

    ui->total_step_time->setDateTime(QDateTime::currentDateTime());
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
            tc_get_connect_status();
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
            if(ui->namefilter->isChecked())
            {
                collect_flag = true;
                collect_status = 1;
            }
            else
            {
                collect_flag = false;
            }
        }
        else
        {
            ui->scan->setText("Scan");
            tc_scan_stop();
            if(ui->namefilter->isChecked())
            {
                collect_flag = false;
                collect_status = 0;
            }
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
                if(collect_status == 3)
                {
                    collect_status = 4;
                    tc_get_breakdown();
                }

                ui->conn_label->setText("Connected");
            }
            else
            {
                ui->conn_label->setText("Disconnected");
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
    case CMD_GET_TIME:
        {
            pro_time_t *resptime = (pro_time_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "time: %02d-%02d-%02d %02d:%02d:%02d ", resptime->year, resptime->month, resptime->day,
                              resptime->hour, resptime->minute, resptime->second);
            textShowString(proTable, pro_len);
        }
        break;
    case CMD_VERSION:
        {
            pro_version_t *respversion = (pro_version_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "version: code %d version: hw %d fw %d algo: %d protocol: %d",respversion->internal_code,
                              respversion->hw_version, respversion->fw_version, respversion->algo_version, respversion->protocol_version);
            textShowString(proTable, pro_len);
        }
        break;
    case CMD_DRAW_WAVE_START:
        {
            pro_xyz_t *respversion = (pro_xyz_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "xyz: %4d  %4d %4d ; xyz: %4d  %4d %4d",
                              respversion->xyz_info[0].x >> 8, respversion->xyz_info[0].y >> 8, respversion->xyz_info[0].z >> 8,
                              respversion->xyz_info[1].x >> 8, respversion->xyz_info[1].y >> 8, respversion->xyz_info[1].z >> 8);
            textShowString(proTable, pro_len);
        }
        break;
    case CMD_CHIP_ADJUST:
        {
            pro_adjust_t *respversion = (pro_adjust_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "s: %d",respversion->status);
            textShowString(proTable, pro_len);
        }
        break;
    case CMD_GET_TOTAL_STEP:
        {
            pro_total_step_response_t *respversion = (pro_total_step_response_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "%02d-%02d\ttotal:%d\trun:%d\trace:%d\twalk:%d",respversion->month, respversion->day, respversion->total_step, respversion->run
                              , respversion->race, respversion->walk);
            textShowString(proTable, pro_len);
        }
        break;
    case CMD_SYN_WALK_DATA:
        {
            if(result->status == CMD_STATUS_SUCCESS || result->status == CMD_STATUS_LAST_ONE)
            {
                pro_syn_walk_response_t *respversion = (pro_syn_walk_response_t *)(result->buf);
                off_2 = STRUCT_OFF(pro_syn_walk_response_t, walk_info);
                uint8_t j = 0, i = (len - off - off_2) / sizeof(pro_walk_info_t);
                for(j = 0;j < i;j++)
                {
                    pro_len = sprintf((char *)proTable, "%02d-%02d\t%02d:%02d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
                                      respversion->month, respversion->day,
                                      respversion->walk_info[j].hour, respversion->walk_info[j].minute, respversion->walk_info[j].total_step, respversion->walk_info[j].slow_walk_step,
                                      respversion->walk_info[j].fast_walk_step, respversion->walk_info[j].run_step, respversion->walk_info[j].inside_step, respversion->walk_info[j].outside_step,
                                      respversion->walk_info[j].normal_step);
                    textShowString(proTable, pro_len);
                }
                tc_syn_walk_go_on();
            }
        }
        break;
    case CMD_SYN_RUN_DATA:
        {
            if(result->status == CMD_STATUS_SUCCESS || result->status == CMD_STATUS_LAST_ONE)
            {
                pro_syn_run_response_t *respversion = (pro_syn_run_response_t *)(result->buf);
                off_2 = STRUCT_OFF(pro_syn_run_response_t, run_info);
                uint8_t j = 0, i = (len - off - off_2) / sizeof(pro_run_info_t);
                for(j = 0;j < i;j++)
                {
                    pro_len = sprintf((char *)proTable, "%02d-%02d\t%02d:%02d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
                                      respversion->month, respversion->day,
                                      respversion->run_info[j].hour, respversion->run_info[j].minute, respversion->run_info[j].run_step, respversion->run_info[j].outside_step,
                                      respversion->run_info[j].inside_step, respversion->run_info[j].normal_step, respversion->run_info[j].forefoot_step, respversion->run_info[j].midfoot_step,
                                      respversion->run_info[j].backfoot_step, respversion->run_info[j].force_g, respversion->run_info[j].height_cm, respversion->run_info[j].float_time_ms,
                                      respversion->run_info[j].land_time_ms);
                    textShowString(proTable, pro_len);
                }
                tc_syn_run_go_on();
            }
        }
        break;

    case CMD_RT_RUN_START:
        {
            if(result->status == CMD_STATUS_SUCCESS)
            {
                pro_rt_detail_response_t *pdeteil;
                pro_rt_simple_response_t *psimple;
                psimple = (pro_rt_simple_response_t *)(result->buf);
                if(psimple->flag == 0x2)
                {
                    pdeteil = (pro_rt_detail_response_t *)(result->buf);
                    if(s_deteil.flag == 0x0)
                    {
                        memcpy(&s_deteil, pdeteil, sizeof(pro_rt_detail_response_t));
                    }
                    pro_len = sprintf((char *)proTable, "total:%d\trun:%d\tfast:%d\tslow:%d\tw_inside:%d\tw_outside:%d\tw_normal:%d",
                                      pdeteil->rt_info.total_step - s_deteil.rt_info.total_step, pdeteil->rt_info.run_step - s_deteil.rt_info.run_step, pdeteil->rt_info.fast_walk_step - s_deteil.rt_info.fast_walk_step, pdeteil->rt_info.slow_walk_step - s_deteil.rt_info.slow_walk_step,
                                      pdeteil->rt_info.walk_inside_step - s_deteil.rt_info.walk_inside_step, pdeteil->rt_info.walk_outside_step - s_deteil.rt_info.walk_outside_step, pdeteil->rt_info.walk_normal_step - s_deteil.rt_info.walk_normal_step
                                      );
                    textShowString(proTable, pro_len);
                    pro_len = sprintf((char *)proTable, "r_outside:%d\tr_normal:%d\tr_inside:%d\tr_fore:%d\tf_mid:%d\tf_back:%d",
                                      pdeteil->rt_info.run_outside_step - s_deteil.rt_info.run_outside_step, pdeteil->rt_info.run_normal_step - s_deteil.rt_info.run_normal_step, pdeteil->rt_info.run_inside_step - s_deteil.rt_info.run_inside_step,
                                      pdeteil->rt_info.run_forefoot_step - s_deteil.rt_info.run_forefoot_step, pdeteil->rt_info.run_midfoot_step - s_deteil.rt_info.run_midfoot_step, pdeteil->rt_info.run_backfoot_step - s_deteil.rt_info.run_backfoot_step
                                      );
                }
                else
                {
                    psimple = (pro_rt_simple_response_t *)(result->buf);
                    pro_len = sprintf((char *)proTable, "total:%4d",
                                      psimple->total_step - s_deteil.rt_info.total_step
                                      );
                }
                textShowString(proTable, pro_len);
            }
        }
        break;

    case CMD_RT_RUN_STOP:
        {
            pro_rt_detail_response_t *pdeteil = (pro_rt_detail_response_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "total:%d\trun:%d\tfast:%d\tslow:%d\tw_inside:%d\tw_outside:%d\tw_normal:%d",
                              pdeteil->rt_info.total_step - s_deteil.rt_info.total_step, pdeteil->rt_info.run_step - s_deteil.rt_info.run_step, pdeteil->rt_info.fast_walk_step - s_deteil.rt_info.fast_walk_step, pdeteil->rt_info.slow_walk_step - s_deteil.rt_info.slow_walk_step,
                              pdeteil->rt_info.walk_inside_step - s_deteil.rt_info.walk_inside_step, pdeteil->rt_info.walk_outside_step - s_deteil.rt_info.walk_outside_step, pdeteil->rt_info.walk_normal_step - s_deteil.rt_info.walk_normal_step
                              );
            textShowString(proTable, pro_len);
            pro_len = sprintf((char *)proTable, "r_outside:%d\tr_normal:%d\tr_inside:%d\tr_fore:%d\tf_mid:%d\tf_back:%d",
                              pdeteil->rt_info.run_outside_step - s_deteil.rt_info.run_outside_step, pdeteil->rt_info.run_normal_step - s_deteil.rt_info.run_normal_step, pdeteil->rt_info.run_inside_step - s_deteil.rt_info.run_inside_step,
                              pdeteil->rt_info.run_forefoot_step - s_deteil.rt_info.run_forefoot_step, pdeteil->rt_info.run_midfoot_step - s_deteil.rt_info.run_midfoot_step, pdeteil->rt_info.run_backfoot_step - s_deteil.rt_info.run_backfoot_step
                              );
            textShowString(proTable, pro_len);
            s_deteil.flag = 0;
        }
        break;
    case CMD_BATTERY:
        {
            pro_battery_t *pdeteil = (pro_battery_t *)(result->buf);
            pro_len = sprintf((char *)proTable, "battery:\t%dmv",pdeteil->voltage_mv);
            textShowString(proTable, pro_len);
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
                    QString str1 = QByteArray::fromRawData((const char *)(g_tmp_dev.addr), 6).toHex().data();
                    QString str2 = "";
                    for(int i = 0;i < str1.length();i += 2)
                    {
                        str2 += str1.mid(i, 2) + ':';
                    }
                    ui->mac_list->addItem(str2);
                    tc_set_normal_mode();
                }
                else
                {
                    bleDevModule.bleAddDev(g_tmp_dev);
                    tc_set_reboot();
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
    int year, month, day;
    ui->total_step_time->date().getDate(&year, &month, &day);
    tc_get_total_step((uint8_t)month, (uint8_t)day);
}

void BLE_TOOLS::on_wave_clicked()
{
    tc_draw_wave_start();
}

void BLE_TOOLS::on_StopDrawWave_clicked()
{
    tc_draw_wave_stop();
}

void BLE_TOOLS::on_AdjustChip_clicked()
{
    tc_chip_adjust();
}

void BLE_TOOLS::on_clear_proto_result_clicked()
{
    ui->protocol_result->clear();
}

void BLE_TOOLS::on_updateRun_clicked()
{
    int year, month, day;
    uint8_t tmp_table[128];
    uint32_t tmp_len = 0;
    tmp_len = sprintf((char *)tmp_table, "date\ttime\trun\toutside\tinside\tnormal\tfore\tmid\tback\tforce\theight\tfloat\tland");
    textShowString(tmp_table, tmp_len);

    ui->total_step_time->date().getDate(&year, &month, &day);
    tc_syn_run_step(month, day, 0, 0, 23, 59);
}

void BLE_TOOLS::on_updateWalk_clicked()
{
    int year, month, day;
    uint8_t tmp_table[128];
    uint32_t tmp_len = 0;
    tmp_len = sprintf((char *)tmp_table, "date\ttime\ttotal\tslow\tfast\trun\tinside\toutside\tnormal");
    textShowString(tmp_table, tmp_len);

    ui->total_step_time->date().getDate(&year, &month, &day);
    tc_syn_walk_step(month, day, 0, 0, 23, 59);
}


void BLE_TOOLS::on_RT_START_clicked()
{
    tc_realtime_start();
}

void BLE_TOOLS::on_RT_END_clicked()
{
    tc_realtime_end();
}

void BLE_TOOLS::on_battery_clicked()
{
    tc_get_battery();
}

void BLE_TOOLS::on_breakdown_clicked()
{
    tc_get_breakdown();
}

void BLE_TOOLS::on_restart_clicked()
{
    tc_set_reboot();
}

void BLE_TOOLS::on_erase_chip_clicked()
{
    tc_erase_chip();
}
