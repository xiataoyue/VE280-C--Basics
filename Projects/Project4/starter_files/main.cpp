#include <iostream>
#include <string>
using namespace std;

int main() {
    char c;
    c = 4 + 'a';
    string s = string(1, c);
    cout << s << endl;
}
