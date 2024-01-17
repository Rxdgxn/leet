#include "../include.h"

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq, exists;

        for (int n : arr) freq[n]++;

        for (auto& [_, f] : freq) {
            if (exists[f]) return false;

            exists[f] = 1;
        }

        return true;
    }
};