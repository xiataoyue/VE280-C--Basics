#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    string input;
    getline(cin, input);

    int length = input.length();
    int arr[length];

    int i;
    int count = 0;

    stringstream Stream;
    string temp, output;

    for(i = 0; i < length; i++) {
        if (input[i] == ',') {
            arr[count] = i;
            count++;
        }
    }

    if(count == 0){
        Stream << input;
        Stream >> output;
        cout << output << endl;
        cout << 1 << endl;
        return 0;
    }

    temp = input.substr(0, arr[0] - 1);

    for(i = 0; i < count - 1; i++){
        temp += " ";
        temp += input.substr(arr[i] + 1, arr[i + 1] - arr[i] - 1);
    }

    temp = temp + " " + input.substr(arr[i] + 1, length - 1);
    Stream << temp;

    for(i = 0; i <= count; i++){
        Stream >> output;
        cout << output << endl;
    }
    cout << count + 1 << endl;
    return 0;
}

