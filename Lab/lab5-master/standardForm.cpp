//
// Created by Zhuoer Zhu on 10/06/2020.
//

#include <cmath>
#include "standardForm.h"

quadraticFunction::quadraticFunction(float a_in, float b_in, float c_in)
:a(a_in), b(b_in), c(c_in){}
// TODO: implement this constructor

float quadraticFunction::getA() const {
    return a;
}

float quadraticFunction::getB() const {
    return b;
}

float quadraticFunction::getC() const {
    return c;
}

float quadraticFunction::evaluate(float x) {
    // TODO: implement this function
    return a*x*x + b*x + c;
}

root quadraticFunction::getRoot() {
    // TODO: implement this function
    root rts;
    float delta = b*b - 4*a*c;
    
    if(delta > 0){
    	rts.realRootNum = 2;
    	if(a > 0){
    	    rts.roots[0].real = (-b - sqrt(delta))/(2*a);    	  
    	    rts.roots[1].real = (-b + sqrt(delta))/(2*a);    	    
    	}
    	else{
    	    rts.roots[0].real = (-b + sqrt(delta))/(2*a);
    	    rts.roots[1].real = (-b - sqrt(delta))/(2*a);
    	}
    	rts.roots[0].imaginary = 0;
    	rts.roots[1].imaginary = 0;
    }
    else if(delta == 0){
        rts.realRootNum = 1;
        rts.roots[0].real = (-b)/(2*a);
        rts.roots[0].imaginary = 0;
        rts.roots[1].real = (-b)/(2*a);
        rts.roots[1].imaginary = 0;
    }
    else{
    	rts.realRootNum = 0;
    	rts.roots[0].real = (-b)/(2*a);
    	rts.roots[1].real = (-b)/(2*a);
    	
    	if(a > 0){
    	    rts.roots[0].imaginary = (-sqrt(-delta))/(2*a);
    	    rts.roots[1].imaginary = (sqrt(-delta))/(2*a);
    	}
    	else{
    	    rts.roots[0].imaginary = (sqrt(-delta))/(2*a);
    	    rts.roots[1].imaginary = (-sqrt(-delta))/(2*a);
    	}
    }
    return rts;
}

int quadraticFunction::intersect(quadraticFunction g){
    // TODO: implement this function
    if(a == g.getA()){
    	if(b == g.getB() && c != g.getC()) return 0;
    	else return 1;
    }
    else{
    	quadraticFunction h(a - g.getA(), b - g.getB(), c - g.getC());
    	if(h.getRoot().realRootNum > 0) return 1;
    	else return 0;
    }
}
