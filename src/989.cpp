#include "../include.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int it, r = 0, c = k, cl = 1;

        while (c > 9) {
            cl++;
            c /= 10;
        }

        const int d = cl - (int)num.size();
        for (int i = 0; i < d; i++) num.insert(num.begin(), 0);
        
        it = num.size() - 1;
        while (it >= 0 && k) {
            const int aux = num[it] + k % 10 + r;
            num[it] = aux % 10;
            r = aux / 10;
            
            it--;
            k /= 10;
        }

        while (it >= 0) {
            const int aux = num[it] + r;
            num[it] = aux % 10;
            r = aux / 10;

            it--;
        }

        if (r) num.insert(num.begin(), r);

        return num;
    }
};