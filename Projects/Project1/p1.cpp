#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int Triangle(int num);
int Palindrome(int num);
int Power(int num);
int Abundant(int num);

int main(){
    int judge = 1;
    int num, test;
    while(judge == 1){
        cout << "Please enter the integer and the test number: ";
        cin >> num >> test;
        if(num <= 0) continue;
        else if(test != 1 && test != 2 && test != 3 && test != 4) continue;
        else break;
    }
    
    if(test == 1) cout << Triangle(num) << endl;
    if(test == 2) cout << Palindrome(num) << endl;
    if(test == 3) cout << Power(num) << endl;
    if(test == 4) cout << Abundant(num) << endl;
    return 0;
}

int Triangle(int num){
    int n;
    int count = 0;
    for(n = 0;n <= num; n++){
    	if(n*(n + 1)/2 == num){
    	    count++;
    	    return 1;
    	}
    	
    	if(n*(n + 1)/2 > num && count == 0){
    	    return 0;
    	}
    }
    return -1;
}

int Palindrome(int num){
    int i;
    int n = num;
    int count = 0;
    
    while(n != 0){
    	n = n/10;
    	count++;
    }
    
    n = num;
    int arr[count];
    for(i = 0; i < count; i++){
    	arr[count - 1 - i] = n % 10;
    	n = n/10;
    }
    
    if(count % 2 == 0){
    	for(i = 0; i < count/2;i++){
    	    if(arr[i] == arr[count -1 -i]) continue;
    	    else return 0;
    	}
    }
    else{
    	for(i = 0; i < (count - 1)/2; i++){
    	    if(arr[i] == arr[count - 1 - i]) continue;
    	    else return 0;
    	}
    }
    
    return 1;
}

int Power(int num){
    int tmp = sqrt(num);
    int n = 2;
    int m;
    
    for(m = 1; m < tmp + 2; m++){
    	while(pow(m, n) <= num){
    	    if(pow(m, n) == num) return 1;
    	    if(m == 1 && n > 2) break;
    	    n++;
    	}
    	n = 2;
    }
    
    return 0;
}

int Abundant(int num){
    int i;
    int sum = 0;
    
    for(i = 1; i < num; i++){
    	if(num % i == 0) sum = sum + i;
    }
    
    if(sum > num) return 1;
    else return 0;
}
