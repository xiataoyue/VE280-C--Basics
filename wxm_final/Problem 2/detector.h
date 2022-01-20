#ifndef DETECTOR_H
#define DETECTOR_H
#include <vector>
#include <iostream>
using namespace std;

class Detector
{
public:
    /**
     * REQUIRES: inputArray
     * EFFECTS : print the largest number in the inputArray that is adjacent to a zero.
     */
    void maxDetector(vector<int> inputArray);
};

void Detector::maxDetector(vector<int> inputArray) {
    if(inputArray.empty()) cout << "0" << endl;
    int size = inputArray.size();
    int arr[10000];
    for(int i = 0; i < size; i++){
        arr[i] = inputArray[i];
    }

    int max = INT8_MIN;
    for(int i = 0; i < size; i++){
        if(arr[i] == 0){
            if(i > 0){
                if(arr[i - 1] >= max) max = arr[i - 1];
            }
            if(i < size - 1){
                if(arr[i + 1] >= max) max = arr[i + 1];
            }
            if(i == 0 && i + 1 <= size - 1) max = arr[i + 1];
            if(i == size - 1 && i - 1 >= 0){
                if(arr[i - 1] >= max) max = arr[i - 1];
            }
        }
        else continue;
    }
    cout << max << endl;
}

#endif