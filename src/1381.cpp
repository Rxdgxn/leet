#include "../include.h"

class CustomStack {
public:

    int stack[1001];
    int ss = 0, cap;

    CustomStack(int maxSize) {
        cap = maxSize;
    }
    
    void push(int x) {
        if (ss < cap)
            stack[ss++] = x;
    }
    
    int pop() {
        if (ss > 0) return stack[--ss];
        return -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, ss); i++)
            stack[i] += val;
    }
};