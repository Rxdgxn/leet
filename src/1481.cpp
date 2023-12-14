#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;

        for (int n : arr) mp[n]++;

        for (auto it = mp.begin(); it != mp.end(); it++)
            pq.push(it->second);

        while (k > 0) {
            k -= pq.top();
            pq.pop();
        }

        return pq.size() + (k < 0);
    }
};