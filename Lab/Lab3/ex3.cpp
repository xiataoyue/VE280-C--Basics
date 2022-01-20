#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int add(int arr[], int count);                          //the function calls --add command
int small(int arr[], int count, int num);

int main(int argc, char *argv[]){
    // judge for the four command initialization
    int helpJudge = 0;
    int addJudge = 0;
    int smallJudge = 0;
    int verboseJudge = 0;
    
    int i, smallnum;
    for(i = 0; i < argc; i++){
    	if(strcmp(argv[i], "--help") == 0) helpJudge = 1;
    	if(strcmp(argv[i], "--add") == 0) addJudge = 1;
    	if(strcmp(argv[i], "--small") == 0){
    	    smallJudge = 1;
    	    smallnum = atoi(argv[i + 1]);
    	}
    	if(strcmp(argv[i], "--verbose") == 0) verboseJudge = 1;
    }
    
    if(helpJudge == 1){
        cout << "Hey, I love Integers." << endl;
        return 0;
    }
    
    if(addJudge == 0 && smallJudge == 0){
    	cout << "No work to do!" << endl;
    	return 0;
    }
    
    int count;
    cin >> count;
    int arr[count];
    int temp;
    for(i = 0; i < count; i++){
    	cin >> temp;
    	arr[i] = temp;
    }
    
    if(verboseJudge == 1){
    	if(addJudge == 1 && smallJudge == 1){
    	    cout << "This is add operation." << endl;
    	    cout << add(arr, count) << endl;
    	    cout << "This is small operation." << endl;
    	    cout << small(arr, count, smallnum) << endl;
    	    return 0;
    	}
    	
    	if(addJudge == 1){
    	    cout << "This is add operation." << endl;
    	    cout << add(arr, count) << endl;
    	    return 0;
    	}
    	
    	if(smallJudge == 1){
    	    cout << "This is small operation." << endl;
    	    cout << small(arr, count, smallnum) << endl;
    	    return 0;
    	}
    }
    else{
    	if(addJudge == 1 && smallJudge == 1){
    	    cout << add(arr, count) << endl;
    	    cout << small(arr, count, smallnum) << endl;
    	    return 0;
    	}
    	
    	if(addJudge == 1){
    	    cout << add(arr, count) << endl;
    	    return 0;
    	}
    	
    	if(smallJudge == 1){
    	    cout << small(arr, count, smallnum) << endl;
    	    return 0;
    	}
    }
}

int add(int arr[], int count){
    int i;
    int n = 0;
    for(i = 0; i < count; i++){
    	n = n + arr[i];
    }
    return n;
}

int small(int arr[], int count, int num){
    int i;
    int min = arr[0];
    for(i = 0; i < count; i++){
    	if(min <= arr[i]) continue;
    	else min = arr[i];
    }
    return min + num;
}
