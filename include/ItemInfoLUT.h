#ifndef ITEMINFOLUT_H
#define ITEMINFOLUT_H
#include <stdint.h>
#include <string>

struct ItemInfo
{
    std::string name;
    uint32_t price;
};

class ItemInfoLUT
{
    public:
        static const uint8_t NUM_ITEM_TYPE = 3;

        ItemInfoLUT();
        static ItemInfoLUT* instance();
        ItemInfo getItemInfo(uint8_t itemTypeId);

    private:
        static ItemInfoLUT m_instance;
        ItemInfo m_itemInfo[NUM_ITEM_TYPE];
};

inline ItemInfoLUT* ItemInfoLUT::instance()
{
    return &m_instance;
}
#endif // ITEMINFOLUT_H
