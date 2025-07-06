#include "../include.h"

class FindSumPairs {
public:
    vector<int> inner1, inner2;
    unordered_map<int, int> occs2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        inner1 = nums1;
        inner2 = nums2;

        for (int n : nums2)
            occs2[n]++;
    }
    
    void add(int index, int val) {
        occs2[inner2[index]]--;
        inner2[index] += val;
        occs2[inner2[index]]++;
    }
    
    int count(int tot) {
        int r = 0;

        for (int n : inner1)
            r += occs2[tot - n];

        return r;
    }
};