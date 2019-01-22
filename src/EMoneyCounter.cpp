#include "EMoneyCounter.h"
#include <iostream>
#include <string>

EMoneyCounter::EMoneyCounter()
{
    m_money = 0;
}

void EMoneyCounter::waitMoneyInput()
{
    unsigned int selection = 0;

    while(true)
    {
        std::cout << "Please Input Money in Rupiah : ";
        std::cin >> selection;

        if (!std::cin.good()) {
            std::cin.clear();
            std::string ignore;
            std::cin >> ignore;
            std::cout<<"Please input numeric value"<<std::endl;
            continue;
        }

        m_money += selection;
        break;
    }
}

uint32_t EMoneyCounter::countMoney()
{
    return m_money;
}

void EMoneyCounter::substractMoney(uint32_t value)
{
    m_money -= value;
}

void EMoneyCounter::reset()
{
    m_money = 0;
}
