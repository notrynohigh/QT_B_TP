#include "ble_tools.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BLE_TOOLS w;
    w.show();

    return a.exec();
}
