#include "../include.h"

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int targ;

    KthLargest(int k, vector<int>& nums) {
        targ = k;
        for (int num : nums) pq.push(num);
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > targ) pq.pop();
        return pq.top();
    }
};