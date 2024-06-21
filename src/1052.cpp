#include "../include.h"

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0, n = customers.size();
        int x = 0;

        while (i < minutes) {
            x += customers[i] * grumpy[i];

            i++;
        }

        int m = x;
        while (i < n) {
            x += customers[i] * grumpy[i];
            x -= customers[i - minutes] * grumpy[i - minutes];

            m = max(m, x);

            i++;
        }

        for (i = 0; i < n; i++)
            m += customers[i] * (1 - grumpy[i]);

        return m;
    }
};