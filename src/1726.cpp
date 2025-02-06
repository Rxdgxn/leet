#include "../include.h"

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> products;

        const int n = nums.size();

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                products[nums[i] * nums[j]]++;

        int tuples = 0;

        // C(n, 2) * 8
        for (auto& [_k, v] : products)
            tuples += 8 * (v * (v - 1) / 2);

        return tuples;
    }
};