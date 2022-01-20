#include<vector>
#include "detector.h"
using namespace std;
int main()
{
    Detector().maxDetector({ 1, 2, 3, 0, 4, 5, 0 });
    Detector().maxDetector({ 1, 5, 3, 0, 2, 7, 0, 8, 9, 1, 0 });
    Detector().maxDetector({ -4, -6, -2, 0, -9 });
    Detector().maxDetector({ -1, 0, 0 });
}