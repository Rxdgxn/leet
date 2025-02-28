#include "../include.h"

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ret = 0;
        const int n = arr.size();

        unordered_set<int> s(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prev = arr[j];
                int curr = arr[i] + arr[j];
                int len = 2;

                while (s.find(curr) != s.end()) {
                    int temp = curr;
                    curr += prev;
                    prev = temp;

                    ret = max(ret, ++len);
                }
            }
        }

        return ret;
    }
};