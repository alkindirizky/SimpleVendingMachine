#include "CoinCounter.h"
#include <iostream>
#include <string>

CoinCounter::CoinCounter()
{
    m_money = 0;
}

void CoinCounter::waitMoneyInput()
{
    int selection = 0;
    bool finished = false;

    while(!finished)
    {
        std::cout << "Please Select Type of Coin Inserted"<<std::endl;
        std::cout << "1. Rp.1000"<<std::endl;
        std::cout << "2. Rp.500"<<std::endl;
        std::cout << "3. Rp.100"<<std::endl;
        std::cin >> selection;

        switch(selection)
        {
        case 1:
            std::cout << "Added Rp.1000"<<std::endl;
            m_money += 1000;
            finished = true;
            break;

        case 2:
            std::cout << "Added Rp.500"<<std::endl;
            m_money += 500;
            finished = true;
            break;

        case 3:
            std::cout << "Added Rp.100"<<std::endl;
            m_money += 100;
            finished = true;
            break;

        default:
            std::cout << "Wrong selection"<<std::endl;
            if (!std::cin.good()) {
                std::cin.clear();
                std::string ignore;
                std::cin >> ignore;
            }
            break;
        }
    }
}

uint32_t CoinCounter::countMoney()
{
    return m_money;
}

void CoinCounter::substractMoney(uint32_t value)
{
    m_money -= value;
}

void CoinCounter::reset()
{
    m_money = 0;
}
