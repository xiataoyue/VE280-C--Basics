/*
 * This is an exercise of VE280 Lab 1, SU2020.
 * Written by Martin Ma.
 * Latest Update: 5/10/2020.
 * Copyright © 2020 Mars-tin. All rights reserved.
 */

#include <iostream>
using namespace std;


// EFFECTS: return the trace of the Laplacian of the weight matrix.
int traceLaplacian(int weight[][50], int size){
    // TODO: Implement this function.
    int a, b, c;
    int tr = 0;
    int diag[size][size], lapl[size][size];
    for(a = 0; a < size; a++){
    	for(b = 0; b < size; b++){
    	    diag[a][b] = 0;
    	}
    }
    	
    
    for(a = 0; a < size; a++){
    	for(b = 0; b < size; b++){
    	    if(a == b){
    	    	for(c = 0; c < size; c++){
    	    	diag[a][b] = diag[a][b] + weight[a][c];
    	    	}
    	    }
    	    else{
    	    	diag[a][b] = 0;
    	    }
    	    
    	    lapl[a][b] = diag[a][b] - weight[a][b];
    	}
    	tr = tr + lapl[a][a];
    }
    
    return tr;
}


int main(){
    int size, trace;
    int weight[50][50] = {};
    cin >> size;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            cin >> weight[i][j];
    trace = traceLaplacian(weight, size);
    cout << trace << endl;
}
