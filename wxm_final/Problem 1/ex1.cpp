#include "myPow.h"
#include <iomanip>

int main(){
    Solution1 sol;
    double x;
    int n;
    char c;
    cin >> x >> c >> n;
    //printf("%.5f\n",sol.myPow(x,n));
    cout << fixed << setprecision(5) << sol.myPow(x, n) << endl;
    return 0;
}