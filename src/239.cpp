#include "../include.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        deque<int> dq;
        map<int, int> numbers;
        vector<int> ret;

        for (int i = 0; i < k; i++) {
            dq.push_back(nums[i]);
            numbers[nums[i]]++;
        }

        ret.push_back(numbers.rbegin()->first);
        
        for (int i = k; i < n; i++) {
            const int f = dq.front();
            numbers[f]--;

            if (numbers[f] == 0)
                numbers.erase(f);

            dq.pop_front();

            numbers[nums[i]]++;
            dq.push_back(nums[i]);

            ret.push_back(numbers.rbegin()->first);
        }

        return ret;
    }
};