#include "MenuInterface.h"
#include "ItemInfoLUT.h"
#include <iostream>

MenuInterface::CommandType MenuInterface::waitCommand()
{
    unsigned int selection;
    while(true)
    {

        std::cout << "Please Select Option"<<std::endl;
        std::cout << "1. Insert Money"<<std::endl;
        std::cout << "2. Select Item"<<std::endl;
        std::cout << "3. Clear Item"<<std::endl;
        std::cout << "4. View Selected Items"<<std::endl;
        std::cout << "5. Finish "<<std::endl;
        std::cout << "6. Cancel"<<std::endl;
        std::cin >> selection;

        if (!std::cin.good()) {
            std::cin.clear();
            std::string ignore;
            std::cin >> ignore;
            std::cout << "Please Input Numeric Value"<<std::endl;
            continue;
        }

        if(selection > CMD_CANCEL)
        {
            std::cout << "Incorrect Selection of"<< (unsigned int) selection + 1
                << "Please Input Value within Range"<<std::endl;
            continue;
        }

        break;
    }

    return (CommandType) selection;
}

void MenuInterface::waitStart()
{
    unsigned int selection;
    while(true)
    {
        std::cout << "Please Input 0 to start"<<std::endl;
        std::cin >> selection;

        if(selection != 0 || !std::cin.good())
        {
            std::cout << "Incorrect Value"<<std::endl;
            if (!std::cin.good())
            {
                std::cin.clear();
                std::string ignore;
                std::cin >> ignore;
            }
            continue;
        }
        else
        {
            break;
        }
    }
}

uint8_t MenuInterface::waitItemSelection()
{
    int selection = 0;
    ItemInfo itemInfo;

    while(true)
    {
        std::cout << "Please Select The Item"<<std::endl;
        for(uint8_t i = 0; i < ItemInfoLUT::NUM_ITEM_TYPE; i++)
        {
            itemInfo = ItemInfoLUT::instance()->getItemInfo(i);
            std::cout << (unsigned int)i+1 << ". " << itemInfo.name
                << " : Rp." << itemInfo.price << std::endl;
        }
        std::cin >> selection;

        if (!std::cin.good()) {
            std::cin.clear();
            std::string ignore;
            std::cin >> ignore;
            std::cout << "Please Input Numeric Value"<<std::endl;
            continue;
        }

        if(selection > ItemInfoLUT::NUM_ITEM_TYPE)
        {
            std::cout << "Incorrect Selection of"<< (unsigned int) selection + 1
                << "Please Input Value within Range"<<std::endl;
            continue;
        }

        selection -= 1;
        break;
    }

    return selection;
}

void MenuInterface::printSelectedItems(uint32_t* itemCountList)
{
    ItemInfo itemInfo;
    std::cout<<""<<std::endl;
    std::cout<<"Selected Items"<<std::endl;
    for(uint8_t i = 0; i < ItemInfoLUT::NUM_ITEM_TYPE; i++)
    {
        if(itemCountList[i] != 0)
        {
            itemInfo = ItemInfoLUT::instance()->getItemInfo(i);
            std::cout<<itemInfo.name<<" : "<<(unsigned int) itemCountList[i]<<std::endl;
        }
    }
}
