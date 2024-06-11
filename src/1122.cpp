#include "../include.h"

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> occs;
        vector<int> sorted;

        for (int num : arr1) occs[num]++;

        for (int num : arr2) {
            for (int i = 0; i < occs[num]; i++)
                sorted.push_back(num);

            occs[num] = 0;
        }

        for (auto it = occs.begin(); it != occs.end(); it++)
            for (int i = 0; i < it->second; i++)
                sorted.push_back(it->first);

        return sorted;
    }
};