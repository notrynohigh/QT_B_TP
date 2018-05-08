#include "bledev.h"
#include "string.h"


bleDev::bleDev()
{
    devListHead.pnext = nullptr;
    devListHead.prev = nullptr;
    bleDevNumber = 0;
}

int bleDev::bleFindDevIndex(bleDevInfo_t dev)
{
    bleDevList_t *p = &devListHead;
    int i = 0;
    while(p->pnext != nullptr)
    {
        p = p->pnext;
        if(0 == strncmp((const char *)(p->devInfo.addr), (const char *)(dev.addr), 6))
        {
            return i;
        }
        i++;
    }
    return -1;
}


bleDevList_t * bleDev::bleFindFromList(bleDevInfo_t dev)
{
    bleDevList_t *p = &devListHead;
    while(p->pnext != nullptr)
    {
        p = p->pnext;
        if(0 == strncmp((const char *)(p->devInfo.addr), (const char *)(dev.addr), 6))
        {
            return p;
        }
    }
    return nullptr;
}


void bleDev::bleAddDev(bleDevInfo_t dev)
{
    bleDevList_t *ptmp = nullptr;
    bleDevList_t *p = &devListHead;
    if(lockFlag)
    {
        return;
    }
    lockFlag = true;
    ptmp = bleFindFromList(dev);
    if(ptmp != nullptr)
    {
        memcpy(&(ptmp->devInfo), &dev, sizeof(bleDevInfo_t));
    }
    else
    {
        while(p->pnext != nullptr)
        {
            p = p->pnext;
        }
        ptmp = new bleDevList_t;
        if(ptmp != nullptr)
        {
            p->pnext = ptmp;
            ptmp->pnext = nullptr;
            ptmp->prev = p;
            memcpy(&(ptmp->devInfo), &dev, sizeof(bleDevInfo_t));
            bleDevNumber++;
        }
    }
    lockFlag = false;
}

void bleDev::bleDelDev(bleDevInfo_t dev)
{
    bleDevList_t *ptmp = nullptr;
    if(lockFlag)
    {
        return;
    }
    lockFlag = true;
    ptmp = bleFindFromList(dev);
    if(ptmp != nullptr)
    {
        ptmp->prev->pnext = ptmp->pnext;
        if(ptmp->pnext != nullptr)
        {
            ptmp->pnext->prev = ptmp->prev;
        }
        delete ptmp;
        bleDevNumber--;
    }
    lockFlag = false;
}


uint32_t bleDev::getBleDevNumber()
{
    return bleDevNumber;
}


bleDevInfo_t * bleDev::getBleDev(uint32_t index)
{
    uint32_t i = 0;
    bleDevList_t *p = &devListHead;
    if(lockFlag)
    {
       return nullptr;
    }
    lockFlag = true;
    if(index < bleDevNumber)
    {
        for(i = 0;i <= index;i++)
        {
            p = p->pnext;
        }
        lockFlag = false;
        return &(p->devInfo);
    }
    lockFlag = false;
    return nullptr;
}


bool bleDev::clear()
{
    if(lockFlag)
    {
       return false;
    }
    lockFlag = true;

    bleDevNumber = 0;
    bleDevList_t *p = &devListHead;
    while(p->pnext != nullptr)
    {
        p = p->pnext;
    }

    while(p->prev != nullptr)
    {
        p = p->prev;
        delete p->pnext;
        p->pnext = nullptr;
    }
    lockFlag = false;
    return true;
}

QString bleDev::getBleDevInfoStr(bleDevInfo_t dev)
{
    QString str, str1, str2, str3;
    str = QString::fromLocal8Bit((const char *)dev.name, -1) + "    ";
    str += "[rssi: " + QString("%1").arg(dev.rssi) + "]  ";
    str1 = QByteArray::fromRawData((const char *)(dev.addr), 6).toHex().data();
    for(int i = 0;i < str1.length();i += 2)
    {
        str2 = str1.mid(i, 2) + ':';
        str3 += str2;
    }
    str += "[mac: " + str3 + "]  ";
    return str;
}


