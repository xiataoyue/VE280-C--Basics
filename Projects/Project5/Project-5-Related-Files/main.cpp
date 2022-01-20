#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

int main() {
    stringstream s;
    string ss;
    getline(cin, ss);
    s << ss;
    string in[5];
    int i = 0;
    while(s) {
        s >> in[i];
        if(in[i].empty()) break;
        i ++;
    }
    for(int j = 0; j < i; j ++){
        cout << in[j] << " ";
    }
    cout << "ssss" << endl;
    return 0;
}
