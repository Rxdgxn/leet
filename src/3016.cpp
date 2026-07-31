#include "../include.h"

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> cnt;

        for (char c : word)
            cnt[c]++;

        priority_queue<int> pq;

        for (auto& [_, v] : cnt)
            pq.push(v);

        int key = 0;
        int ret = 0;

        while (!pq.empty()) {
            ret += (1 + key / 8) * pq.top();
            pq.pop();
            key++;
        }

        return ret;
    }
};