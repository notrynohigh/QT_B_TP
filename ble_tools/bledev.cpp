#include "bledev.h"
#include "string.h"


bleDev::bleDev()
{
    devListHead.pnext = nullptr;
    devListHead.prev = nullptr;
    bleDevNumber = 0;
}

bleDevList_t * bleDev::bleFindDev(bleDevInfo_t dev)
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

bool bleDev::bleAddDev(bleDevInfo_t dev)
{
    bleDevList_t *ptmp = nullptr;
    bleDevList_t *p = &devListHead;
    bool retval = false;
    if(lockFlag)
    {
        return false;
    }
    lockFlag = true;
    ptmp = bleFindDev(dev);
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
        retval = true;
    }
    lockFlag = false;
    return retval;
}

void bleDev::bleDelDev(bleDevInfo_t dev)
{
    bleDevList_t *ptmp = nullptr;
    if(lockFlag)
    {
        return;
    }
    lockFlag = true;
    ptmp = bleFindDev(dev);
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
        for(i = 0;i < index;i++)
        {
            p = p->pnext;
        }
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





