#ifndef CASHINGMACHINE_H
#define CASHINGMACHINE_H

#include <vector>
#include <iostream>
using namespace std;

class CashingMachine
{
private:
    int num_100;
    int num_50;
    int num_20;
    int num_10;
    int num_5;
    int num_1;
public:
    // Default Constructor
    CashingMachine(): num_1(0), num_5(0), num_10(0), num_20(0), num_50(0), num_100(0) {};
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

void CashingMachine::printStatus() {
    cout << "100: " << num_100 << endl;
    cout << "50: " << num_50 << endl;
    cout << "20: " << num_20 << endl;
    cout << "10: " << num_10 << endl;
    cout << "5 : " << num_5 << endl;
    cout << "1 : " <<num_1 << endl;
    int total = 100*num_100 + 50*num_50 + 20*num_20 + 10*num_10 + 5*num_5 + num_1;
    cout << "Sum: " << total << endl;
}

void CashingMachine::add(int value, int amount) {
    if(value == 100) num_100 += amount;
    if(value == 50) num_50 += amount;
    if(value == 20) num_20 += amount;
    if(value == 10) num_10 += amount;
    if(value == 5) num_5 += amount;
    if(value == 1) num_1 += amount;
}

void CashingMachine::change(vector<int> receive, int receivable) {
    int size = receive.size();
    int arr[1000];
    int total = 0;
    for(int i = 0; i < size; i++){
        arr[i] = receive[i];
    }
    for(int i = 0; i <size; i++){
        if(arr[i] == 100) total += 100;
        if(arr[i] == 50) total += 50;
        if(arr[i] == 20) total += 20;
        if(arr[i] == 10) total += 10;
        if(arr[i] == 5) total += 5;
        if(arr[i] == 1) total += 1;
    }
    int change = total - receivable;
    int cnt_100 = num_100, cnt_50 = num_50, cnt_20 = num_20, cnt_10 = num_10, cnt_5 = num_5, cnt_1 = num_1;
    int flag = 0;
    while(change != 0){
        if(change >= 100){
            if(cnt_100 > 0){
                cnt_100 --;
                change -= 100;
                continue;
            }
            if(cnt_50 > 0){
                cnt_50 --;
                change -= 50;
                continue;
            }
            if(cnt_20 > 0){
                cnt_20 --;
                change -= 20;
                continue;
            }
            if(cnt_10 > 0){
                cnt_10 --;
                change -= 10;
                continue;
            }
            if(cnt_5 > 0){
                cnt_5 --;
                change -= 5;
                continue;
            }
            if(cnt_1 > 0){
                cnt_1 --;
                change -= 1;
                continue;
            }
        }
        if(change >= 50){
            if(cnt_50 > 0){
                cnt_50 --;
                change -= 50;
                continue;
            }
            if(cnt_20 > 0){
                cnt_20 --;
                change -= 20;
                continue;
            }
            if(cnt_10 > 0){
                cnt_10 --;
                change -= 10;
                continue;
            }
            if(cnt_5 > 0){
                cnt_5 --;
                change -= 5;
                continue;
            }
            if(cnt_1 > 0){
                cnt_1 --;
                change -= 1;
                continue;
            }
        }
        if(change >= 20){
            if(cnt_20 > 0){
                cnt_20 --;
                change -= 20;
                continue;
            }
            if(cnt_10 > 0){
                cnt_10 --;
                change -= 10;
                continue;
            }
            if(cnt_5 > 0){
                cnt_5 --;
                change -= 5;
                continue;
            }
            if(cnt_1 > 0){
                cnt_1 --;
                change -= 1;
                continue;
            }
        }
        if(change >= 10){
            if(cnt_10 > 0){
                cnt_10 --;
                change -= 10;
                continue;
            }
            if(cnt_5 > 0){
                cnt_5 --;
                change -= 5;
                continue;
            }
            if(cnt_1 > 0){
                cnt_1 --;
                change -= 1;
                continue;
            }
        }
        if(change >= 5){
            if(cnt_5 > 0){
                cnt_5 --;
                change -= 5;
                continue;
            }
            if(cnt_1 > 0){
                cnt_1 --;
                change -= 1;
                continue;
            }
        }
        if(change >= 1){
            if(cnt_1 > 0){
                cnt_1 --;
                change -= 1;
                continue;
            }
        }

        if(change < 100 && change >= 50) {
            if(cnt_50 == 0 && cnt_20 == 0 && cnt_10 == 0 && cnt_5 == 0 && cnt_1 == 0) break;
        }
        if(change < 50 && change >= 20){
            if(cnt_20 == 0 && cnt_10 == 0 && cnt_5 == 0 && cnt_1 == 0) break;
        }
        if(change < 20 && change >= 10){
            if(cnt_10 == 0 && cnt_5 == 0 && cnt_1 == 0) break;
        }
        if(change < 10 && change >= 5){
            if(cnt_5 == 0 && cnt_1 == 0) break;
        }
        if(change < 5 && change >= 1){
            if(cnt_1 == 0) break;
        }
    }
    if(change == 0) flag = 1;
    if(flag == 1) {
        num_100 -= (num_100 - cnt_100);
        num_50 -= (num_50 - cnt_50);
        num_20 -= (num_20 - cnt_20);
        num_10 -= (num_10 - cnt_10);
        num_5 -= (num_5 - cnt_5);
        num_1 -= (num_1 - cnt_1);
        for(int i = 0; i < size; i ++){
            if(arr[i] == 100) num_100 += 1;
            if(arr[i] == 50) num_50 += 1;
            if(arr[i] == 20) num_20 += 1;
            if(arr[i] == 10) num_10 += 1;
            if(arr[i] == 5) num_5 += 1;
            if(arr[i] == 1) num_1 += 1;
        }
        cout << "SUCCESS" << endl;
    }
    else{
        cout << "ERROR" << endl;
    }
}
#endif