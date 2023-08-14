#include "../include.h"

class MinStack {
public:
    stack<int> st, mins;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if (mins.empty() || val <= mins.top()) mins.push(val);
    }
    
    void pop() {
        if (st.top() == mins.top()) mins.pop();

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};