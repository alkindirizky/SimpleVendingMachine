#include "ItemInfoLUT.h"

ItemInfoLUT ItemInfoLUT::m_instance;

ItemInfoLUT::ItemInfoLUT()
{
    m_itemInfo[0].name = "Coca Cola";
    m_itemInfo[0].price = 2500;

    m_itemInfo[1].name = "Fresh Tea";
    m_itemInfo[1].price = 1300;

    m_itemInfo[2].name = "Beng Beng";
    m_itemInfo[2].price = 700;
}

ItemInfo ItemInfoLUT::getItemInfo(uint8_t itemTypeId)
{
    if(itemTypeId > NUM_ITEM_TYPE)
    {
        ItemInfo emptyItemInfo = {0};
        return emptyItemInfo;
    }

    return m_itemInfo[itemTypeId];
}
