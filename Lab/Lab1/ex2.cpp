/*
 * This is an exercise of VE280 Lab 1, SU2020.
 * Written by Martin Ma.
 * Latest Update: 5/10/2020.
 * Copyright © 2020 Mars-tin. All rights reserved.
 */

#include <iostream>
#include <cstring>
using namespace std;


// EFFECTS: return true if the password is a valid one
bool isValidPassword(char password[]){
    // TODO: Implement this function.
    int i;
    int a = 0, b = 0, c = 0;
    int length = strlen(password);
    for(i = 0; i < length; i++){
    	if(isdigit(password[i])) a++;
    	if(isalpha(password[i])) b++;
    	if(ispunct(password[i])) c++;
    }
    if(a > 0 && b > 0 && c > 0){
    	return true;
    }
    else{
    	return false;
    }
}


int main(){
    char password[50] = {};
    cin >> password;
    cout << isValidPassword(password) << endl;
}
