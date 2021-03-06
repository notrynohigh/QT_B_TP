#ifndef BLEDEV_H
#define BLEDEV_H

#include "stdint.h"
#include "qstring.h"

typedef struct
{
    uint8_t addr[6];
    int8_t  rssi;
    uint8_t name[16];
}bleDevInfo_t;

typedef struct bleDevList
{
    bleDevInfo_t devInfo;
    bleDevList   *pnext;
    bleDevList   *prev;
}bleDevList_t;

class bleDev
{
public:
    bleDev();
    void bleAddDev(bleDevInfo_t dev);
    void bleDelDev(bleDevInfo_t dev);

    int bleFindDevIndex(bleDevInfo_t dev);
    bleDevList_t * bleFindFromList(bleDevInfo_t dev);

    uint32_t getBleDevNumber();
    bleDevInfo_t * getBleDev(uint32_t index);
    bool clear();

    QString getBleDevInfoStr(bleDevInfo_t dev);

private:
    bool lockFlag = false;
    bleDevList_t devListHead;
    uint32_t bleDevNumber;
};

#endif // BLEDEV_H
