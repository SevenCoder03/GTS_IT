#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
        int top;
        int size;
        T *arrElement;
    public:
        Stack(int = 10);
        bool isEmpty();
        bool isFull();
        void push(T);
        void pop();
        int getSize();
        int getTop();
        //T getTop();
        ~Stack();
};


