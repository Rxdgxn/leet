#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ret = 0;

        priority_queue<int> max;
        priority_queue<int, vector<int>, greater<int>> min;

        const int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            const int n = nums[i];
            max.push(n);
            min.push(n);
        }

        for (int i = 0; i < sz / 2; i++) {
            ret = std::max(ret, max.top() + min.top());
            max.pop();
            min.pop();
        }

        return ret;
    }
};