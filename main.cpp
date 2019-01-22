#include <iostream>
#include <VendingMachine.h>
#include <EMoneyCounter.h>

using namespace std;


EMoneyCounter emoneyCounter;
VendingMachine vending(&emoneyCounter);

int main()
{
    while(true)
    {
        vending.execute();
    }

    return 0;
}
