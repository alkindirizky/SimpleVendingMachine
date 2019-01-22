#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include "ItemDispenser.h"

class MenuInterface
{
    public:
        enum CommandType
        {
            CMD_INSERT_MONEY = 1,
            CMD_SELECT_ITEM,
            CMD_CLEAR_ITEM,
            CMD_VIEW_ITEM,
            CMD_FINISHED,
            CMD_CANCEL
        };

        CommandType waitCommand();
        void waitStart();
        uint8_t waitItemSelection(); //return selected itemID
        void printSelectedItems(uint32_t* itemCountList); //itemCountList is mapped to item type ID
};

#endif // MENUINTERFACE_H
