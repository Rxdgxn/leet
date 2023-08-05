#include "../include.h"

class MyCircularQueue {
public:
    int cs = 0, cap;
    vector<int> q;

    MyCircularQueue(int k) {
        cap = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q.push_back(value);
        cs++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        q = vector<int>(q.begin() + 1, q.end());
        cs--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[0];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q.back();
    }
    
    bool isEmpty() {
        return cs == 0;
    }
    
    bool isFull() {
        return cs == cap;
    }
};