#ifndef IMONEY_INPUT_H
#define IMONEY_INPUT_H

#include <stdint.h>

class IMoneyInput
{
    public:
        /*Blocking wait user inputting coins (discrete options)*/
        virtual void waitMoneyInput() = 0;

        /*return the total of inserted money*/
        virtual uint32_t countMoney() = 0;
        virtual void substractMoney(uint32_t value) = 0;
        virtual void reset() = 0;
};

#endif // COINCOUNTER_H
