#include "../include.h"

class DinnerPlates {
public:
    int cap;
    vector<stack<int>> plates_list;
    set<int> lefts, rights;

    DinnerPlates(int capacity) {
        cap = capacity;
        plates_list.push_back(stack<int>());
        lefts.insert(0);
    }
    
    void push(int val) {
        int lm = *lefts.begin();
        rights.insert(lm);

        plates_list[lm].push(val);

        if (plates_list[lm].size() == cap) {
            lefts.erase(lefts.begin());

            if (lefts.empty()) {
                plates_list.push_back(stack<int>());
                lefts.insert(plates_list.size() - 1);
            }
        }
    }
    
    int pop() {
        if (rights.empty())
            return -1;

        int rm = *rights.rbegin();
        lefts.insert(rm);
        int val = plates_list[rm].top();
        plates_list[rm].pop();

        if (plates_list[rm].empty())
            rights.erase(rm);

        return val;
    }
    
    int popAtStack(int index) {
        if (index >= plates_list.size() || plates_list[index].empty())
            return -1;

        lefts.insert(index);

        int val = plates_list[index].top();
        plates_list[index].pop();

        if (plates_list[index].empty())
            rights.erase(index);

        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */