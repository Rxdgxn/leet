#include "../include.h"

#define sort_v(v) sort((v).begin(), (v).end())

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort_v(target);
        sort_v(arr);

        return target == arr;
    }
};