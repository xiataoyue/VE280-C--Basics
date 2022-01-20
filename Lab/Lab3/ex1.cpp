/*
 * VE280 Lab 3, SU2020.
 * Written by Guoxin Yin
 */

#include <iostream>

using namespace std;

const int MAXSIZE = 10;

bool canWin(int count, int arr[], int position) {
    // EFFECTS: return whether the player can win given the start position
    // and the card sequence
    
    // TODO: implement this function
    
    bool left, right;
    if(arr[position] == 280) return true;
    if(arr[position] == 0) return false;
    
    int v = arr[position];
    arr[position] = 0;           //reset the value of arr[position] avoiding double pick;
    
    if(position - v >= 0 && position + v < count){
    	left = canWin(count, arr, position - v);
    	right = canWin(count, arr, position + v);
    }
    
    if(position - v >= 0) left = canWin(count, arr, position - v);
    if(position - v < count) right = canWin(count, arr, position + v);
    if(position - v < 0 && position + v >= count) return false;
    
    if(left || right) return true;
    else return false;
    
    
}

int main() {
    int count;
    cin >> count;
    int arr[MAXSIZE];
    for (int i = 0; i < count; ++i) {
        cin >> arr[i];
    }
    int position;
    cin >> position;
    cout << canWin(count, arr, position);
}
