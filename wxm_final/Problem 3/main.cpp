#include "cashingmachine.h"

int main()
{
    CashingMachine CM;
    CM.add(100, 1);
    CM.add(20, 1);
    CM.add(10, 1);
    CM.printStatus();
    CM.change({ 100, 1, 20 }, 111);
    CM.printStatus();
    CM.change({ 100 }, 50);
    CM.printStatus();
    return 0;
}