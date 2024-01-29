#include "../include.h"

class MyQueue {
public:
    stack<int> s1, s2;
    int sz;

    MyQueue() {
        sz = 0;
    }

    void push(int x) {
        s1.push(x);
        sz++;
    }

    int pop() {
        int x;

        while (!s1.empty()) {
            x = s1.top();
            s2.push(x);
            s1.pop();
        }

        s2.pop();

        while (!s2.empty()) {
            int t = s2.top();
            s2.pop();
            s1.push(t);
        }

        sz--;
        return x;
    }

    int peek() {
        int x;

        while (!s1.empty()) {
            x = s1.top();
            s2.push(x);
            s1.pop();
        }

        while (!s2.empty()) {
            int t = s2.top();
            s2.pop();
            s1.push(t);
        }

        return x;
    }

    bool empty() {
        return sz == 0;
    }
};