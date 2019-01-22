#ifndef ITEMDISPENSER_H
#define ITEMDISPENSER_H

#include <string>
#include <stdint.h>
#include <ItemInfoLUT.h>

class ItemDispenser
{
    public:
        ItemDispenser();
        uint32_t getTotalCost();
        bool queueItemDispense(uint8_t itemTypeId);
        void clearQueue();
        void dispense();
        void getItemCountList(uint32_t* itemCountList); //return selected item counts, make sure itemCountList is sized to ItemInfoLUT::NUM_ITEM_TYPE

    private:
        uint32_t m_itemCount[ItemInfoLUT::NUM_ITEM_TYPE];

};

#endif // ITEMDISPENSER_H
