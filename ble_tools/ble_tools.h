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

    quint32 recDataLen = 0;
    quint8  recTable[256];

    void textShowData(uint8_t *pbuf, uint32_t len);
    void updateBleDevList();
private slots:
    void on_opencom_clicked();
    void on_scan_clicked();
    void timer_timeout();
    void on_clear_list_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::BLE_TOOLS *ui;
    QTimer *quartTimer;

};

#endif // BLE_TOOLS_H
