#include "ItemDispenser.h"
#include <iostream>
#include <ItemInfoLUT.h>
#include <string.h>

ItemDispenser::ItemDispenser()
{
    clearQueue();
}

uint32_t ItemDispenser::getTotalCost()
{
    uint32_t totalCost = 0;
    ItemInfo itemInfo;

    for(uint8_t i = 0; i<ItemInfoLUT::NUM_ITEM_TYPE; i++)
    {
        itemInfo = ItemInfoLUT::instance()->getItemInfo(i);
        totalCost += itemInfo.price * m_itemCount[i];
    }

    return totalCost;
}

bool ItemDispenser::queueItemDispense(uint8_t itemTypeId)
{
    if(itemTypeId >= ItemInfoLUT::NUM_ITEM_TYPE)
    {
        std::cout<<"Failed Selecting Item : Unknown itemType ID"<<std::endl;
        return false;
    }

    m_itemCount[itemTypeId] +=1;
    return true;
}

void ItemDispenser::clearQueue()
{
    memset(m_itemCount, 0, sizeof(m_itemCount));
}

void ItemDispenser::dispense()
{
    ItemInfo itemInfo;

    for(uint8_t i; i<ItemInfoLUT::NUM_ITEM_TYPE; i++)
    {
        itemInfo = ItemInfoLUT::instance()->getItemInfo(i);
        if(m_itemCount[i])
        {
            std::cout<<"Dispensing "<<(unsigned int) m_itemCount[i]<<" items of "<<itemInfo.name<<std::endl;
        }

    }
}

void ItemDispenser::getItemCountList(uint32_t* itemCountList)
{
    memcpy(itemCountList, m_itemCount, sizeof(m_itemCount));
}
