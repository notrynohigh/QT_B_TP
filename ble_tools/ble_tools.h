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
    void uiUpdateList(QString str);
    void uiUpdateList(int index, QString str);
private slots:
    void on_opencom_clicked();
    void on_scan_clicked();
    void on_timer_timeout();
    void on_clear_list_clicked();

private:
    Ui::BLE_TOOLS *ui;
    QTimer *quartTimer;

};

#endif // BLE_TOOLS_H
