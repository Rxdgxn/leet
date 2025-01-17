#include "../include.h"

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;

        for (int& d : derived)
            x ^= d;

        return x == 0;
    }
};