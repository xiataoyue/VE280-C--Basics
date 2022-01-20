#include "dlist.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

template <class T>
class Stack {
    Dlist<T> dlist;

public:
    bool empty();
    T *top();
    void push(T *op);
    void pop();
};

template <class T>
bool Stack<T>::empty() {
    return dlist.isEmpty();
}

template <class T>
T *Stack<T>::top() {
    T *op = dlist.removeFront();
    dlist.insertFront(op);
    return op;
}

template <class T>
void Stack<T>::push(T *op) {
    dlist.insertFront(op);
}

template <class T>
void Stack<T>::pop() {
    dlist.removeFront();
}

int main() {
    istringstream Istream;
    string input[1000];
    int count = 0;
    string str;
    getline(cin, str);
    if(str.empty()){
    	cout << "No input!" << endl;
		return 0;
	} 
    Istream.str(str);

    while(Istream){
        Istream >> input[count];
        count ++;
    }
    if(input[count - 1] == "\0") count --;

    Stack<char> stack;
    string output;

    try {
        for(int i = 0; i < count; i++) {
            if(input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/"){
                while((!stack.empty()) && ((*stack.top() == '*' || *stack.top() == '/') || (input[i] == "+" || input[i] == "-")) && (*stack.top() != '(')){
                    output += *stack.top();
                    output += " ";
                    char *p = stack.top();
                    stack.pop();
                    delete p;
                }
                string x = input[i];
                char *cc = new char(x[0]);
                stack.push(cc);
            }
            else if(input[i] == "(") {
                string x = input[i];
                char *cc = new char(x[0]);
                stack.push(cc);
            }
            else if(input[i] == ")") {
                if(stack.empty()){
                    string err = "ERROR: Parenthesis mismatch";
                    throw err;
                }
                while(*stack.top() != '(') {
                    output += *stack.top();
                    output += " ";
                    char *p = stack.top();
                    stack.pop();
                    delete p;
                    if(stack.empty()) {
                        string error = "ERROR: Parenthesis mismatch";
                        throw error;
                    }
                }
                char *pp = stack.top();
                stack.pop();
                delete pp;
            }
            else{
                output += input[i];
                output += " ";
            }
        }
        while(!stack.empty()) {
            if(*stack.top() == '(' || *stack.top() == ')') {
                string mis = "ERROR: Parenthesis mismatch";
                throw mis;
            }
            output += *stack.top();
            output += " ";
            char *p = stack.top();
            stack.pop();
            delete p;
        }
        cout << output << endl;

        Istream.clear();
        Istream.str(output);
        Stack<long long int> cal;

        while(Istream) {
            string ch;
            Istream >> ch;
            if(ch == "\0") break;
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                if(ch.empty()) continue;
                if(cal.empty()) {
                    string neo = "ERROR: Not enough operands";
                    throw neo;
                }
                long long int *back = cal.top();
                cal.pop();
                if(cal.empty()){
                    string neo = "ERROR: Not enough operands";
                    delete back;
                    throw neo;
                }
                long long int *front = cal.top();
                cal.pop();
                if(ch == "+") {
                    auto *temp_result = new long long int(*front + *back);
                    cal.push(temp_result);
                }
                else if(ch == "-") {
                    auto *temp_result = new long long int(*front - *back);
                    cal.push(temp_result);
                }
                else if(ch == "*") {
                    auto *temp_result = new long long int(*front * *back);
                    cal.push(temp_result);
                }
                else if(ch == "/") {
                    if(*back == 0) {
                        string dbz = "ERROR: Divide by zero";
                        delete front;
                        delete back;
                        throw dbz;
                    }
                    auto *temp_result = new long long int(*front / *back);
                    cal.push(temp_result);
                }
                delete front;
                delete back;
            }
            else{
                long int x = atoi(ch.c_str());
                auto *val = new long long int(x);
                cal.push(val);
            }
        }
        long long int *result = cal.top();
        cal.pop();
        if(!cal.empty()) {
            string tmo = "ERROR: Too many operands";
            delete result;
            throw tmo;
        }
        cout << *result << endl;
        delete result;
    }
    catch (string exception) {
        cout << exception << endl;
    }

    return 0;
}
