#ifndef COINCOUNTER_H
#define COINCOUNTER_H

#include <stdint.h>

class CoinCounter
{
    public:
        CoinCounter();

        /*Blocking wait user inputting coins (discrete options)*/
        void waitMoneyInput();

        /*return the total of inserted money*/
        uint32_t countMoney();
        void substractMoney(uint32_t value);
        void reset();

    private:
        uint32_t m_money;
};

#endif // COINCOUNTER_H
