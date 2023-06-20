#include "../include.h"

class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] == '-') {
            for (int i = 0; i < n.size(); i++)
                if (n[i] - '0' > x) {
                    n.insert(n.begin() + i, x + '0');
                    return n;
                }
        }
        else {
            for (int i = 0; i < n.size(); i++)
                if (n[i] - '0' < x) {
                    n.insert(n.begin() + i, x + '0');
                    return n;
                }
        }
        char y = x + '0';
        n.push_back(y);
        return n;
    }
};