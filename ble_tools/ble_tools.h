#ifndef BLE_TOOLS_H
#define BLE_TOOLS_H

#include <QMainWindow>


namespace Ui {
class BLE_TOOLS;
}

class BLE_TOOLS : public QMainWindow
{
    Q_OBJECT

public:
    explicit BLE_TOOLS(QWidget *parent = 0);
    ~BLE_TOOLS();

    uint8_t t_buf[256];
    uint32_t t_buf_len = 0;


    void textShowData(uint8_t *pbuf, uint32_t len);
    void textShowString(uint8_t *pbuf, uint32_t len);
    void updateBleDevList();
    void dispatch_cmd(uint8_t *pbuf, uint32_t len);

    void save_mac();

private slots:
    void on_opencom_clicked();
    void on_scan_clicked();
    void timer_timeout();
    void on_clear_list_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_clear_log_clicked();

    void on_refresh_com_clicked();

    void on_setDate_clicked();

    void on_getdata_clicked();

    void on_version_clicked();

    void on_total_steps_clicked();

    void on_wave_clicked();

    void on_StopDrawWave_clicked();

    void on_AdjustChip_clicked();

    void on_clear_proto_result_clicked();

    void on_updateRun_clicked();

    void on_updateWalk_clicked();

    void on_RT_START_clicked();

    void on_RT_END_clicked();

    void on_battery_clicked();

    void on_breakdown_clicked();

    void on_restart_clicked();

    void on_erase_chip_clicked();

    void on_savemac_clicked();

    void on_setID_clicked();

    void on_resetid_clicked();

    void on_restart_record_clicked();

    void on_getalgoparam_clicked();

private:
    Ui::BLE_TOOLS *ui;
    QTimer *quartTimer;


};

#endif // BLE_TOOLS_H
