#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

struct Apple{
    string name;
    double price;
    double weight;
    double average;
};
int main(int argc, char* argv[]){
    string file = argv[1];
    Apple apple;
    int length, length1, length2;
    int i = 0;
    int count = 0;
    string str, temp;
    double min_average;
    double temp1, temp2, temp3;

    ifstream File(file);

    if(!File.is_open()) return 0;

    while(getline(File, str)){
        length = str.length();

        while(str[i] != ' '){
            i++;
        }
        length1 = i;
        i++;

        while(str[i] != ' '){
            i++;
        }
        length2 = i;

        istringstream iStream1, iStream2;
        iStream1.str(str.substr(length1 + 1, length2));
        iStream2.str(str.substr(length2 + 1, length - 1));

        if(count == 0){
            apple.name = str.substr(0, length1);
            iStream1 >> apple.price;
            iStream2 >> apple.weight;
            apple.average = apple.price / apple.weight;
            min_average = apple.average;
        }
        else{
            temp = str.substr(0, length1);
            iStream1 >> temp1;
            iStream2 >> temp2;
            temp3 = temp1 / temp2;
            if(temp3 < min_average){
                apple.name = temp;
                apple.price = temp1;
                apple.weight = temp2;
                apple.average = temp3;
                min_average = temp3;
            }
        }
        i = 0;
        count++;
    }
    cout << apple.name << " ";
    cout << fixed << setprecision(2) << apple.price << " ";
    cout << fixed << setprecision(2) << apple.weight << endl;
    return 0;

}