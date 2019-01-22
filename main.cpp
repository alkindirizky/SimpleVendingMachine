#include <iostream>
#include <VendingMachine.h>

using namespace std;

VendingMachine vending;

int main()
{
    while(true)
    {
        vending.execute();
    }

    return 0;
}
