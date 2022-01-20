//
// Created by Zhuoer Zhu on 10/06/2020.
//

#include "factoredForm.h"

quadraticFunction::quadraticFunction(float a_in, float b_in, float c_in){
    a = a_in;
    float delta = b_in*b_in - 4*a_in*c_in;
    
    if(delta > 0){
    	if(a > 0){
    	    r1.real = (-b_in - sqrt(delta))/(2*a_in);
    	    r2.real = (-b_in + sqrt(delta))/(2*a_in);
    	}
    	else{
    	    r1.real = (-b_in + sqrt(delta))/(2*a_in);
    	    r2.real = (-b_in - sqrt(delta))/(2*a_in);
    	}
    	r1.imaginary = 0;
    	r2.imaginary = 0;
    }
    else if(delta == 0){
    	r1.real = (-b_in)/(2*a);
    	r2.real = (-b_in)/(2*a);
    	r1.imaginary = 0;
    	r2.imaginary = 0;
    }
    else{
    	r1.real = (-b_in)/(2*a);
    	r2.real = (-b_in)/(2*a);
    	if(a > 0){
    	    r1.imaginary = (-sqrt(-delta))/(2*a_in);
    	    r2.imaginary = (sqrt(-delta))/(2*a_in);
    	}
    	else{
    	    r1.imaginary = (sqrt(-delta))/(2*a_in);
    	    r2.imaginary = (-sqrt(-delta))/(2*a_in);
    	}
    }
}
// TODO: implement this constructor

float quadraticFunction::getA() const {
    return a;
}

float quadraticFunction::getB() const {
    // TODO: implement this function
    return -a*(r1.real + r2.real);
}

float quadraticFunction::getC() const {
    // TODO: implement this function
    return a*(r1.real*r2.real - r1.imaginary * r2.imaginary);
}

float quadraticFunction::evaluate(float x) {
    // TODO: implement this function
    return a*x*x + getB()*x + getC();
}

root quadraticFunction::getRoot() {
    // TODO: implement this function
    root rts;
    rts.roots[0] = r1;
    rts.roots[1] = r2;
    
    if(r1.imaginary != 0) rts.realRootNum = 0;
    else if(r1.real == r2.real) rts.realRootNum = 1;
    else rts.realRootNum = 2;
    
    return rts;
}

int quadraticFunction::intersect(quadraticFunction g) {
    // TODO: implement this function
    if(a == g.getA()){
    	if(getB() == g.getB() && getC() != g.getC()) return 0;
    	else return 1;
    }
    else{
    	quadraticFunction h(a - g.getA(), getB() - g.getB(), getC() - g.getC());
    	if(h.getRoot().realRootNum > 0) return 1;
    	else return 0;
    }
}
