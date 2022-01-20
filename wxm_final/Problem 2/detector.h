#ifndef DETECTOR_H
#define DETECTOR_H
#include <vector>
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

#endif