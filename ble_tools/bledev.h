#ifndef BLEDEV_H
#define BLEDEV_H

#include "stdint.h"

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
    bool bleAddDev(bleDevInfo_t dev);
    void bleDelDev(bleDevInfo_t dev);
    bleDevList_t *bleFindDev(bleDevInfo_t dev);
    uint32_t getBleDevNumber();
    bleDevInfo_t * getBleDev(uint32_t index);
    bool clear();
private:
    bool lockFlag = false;
    bleDevList_t devListHead;
    uint32_t bleDevNumber;
};

#endif // BLEDEV_H
