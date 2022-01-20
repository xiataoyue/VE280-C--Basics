#ifndef CASHINGMACHINE_H
#define CASHINGMACHINE_H

#include <vector>
using namespace std;

class CashingMachine
{
public:
    // Default Constructor
    CashingMachine() {};
    /**
     * EFFECTS : print the status of the machine
     *           including the amount of each bill, and the sum of money
     *           refer to sample output for the specific format
     */
    void printStatus();

    /**
     * REQUIRES: value, the nominal value of the bills to be added
     *           can only be 100,50,20,10,1
     * REQUIRES: amount, positive, the amount of bills to be added
     * EFFECTS : add an amount of bills to the cashing machine
     */
    void add(int value, int amount);

    /**
     * REQUIRES: receive, elements can obly be 100,50,20,10,1
     * REQUIRES: receivable, the money should be received
     * EFFECTS : make the change and print "SUCCESS".
     *           if change can't be made, print "ERROR" in the newline.
     */
    void change(vector<int> receive, int receivable);
};
#endif