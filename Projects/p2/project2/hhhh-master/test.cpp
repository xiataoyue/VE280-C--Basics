#include <iostream>
#include <cstdlib>

using namespace std;

/*void increment(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        (*(arr + i))++; // correct
//*(arr + i)++; // wrong
    }
}*/

int main() {
    // Which lines cannot compile?
    int a = 1;
    const int& b = a;
    const int c = a;
    int &d = a;
    const int& e = a+1;
    const int f = a+1;
    int &g = a+1; // x
    b = 5; // x
    c = 5; // x
    d = 5;
}
