#include "../include.h"

class Solution {
public:
    long long smallestNumber(long long n) {
        if (n / 10 == 0) return n;

        vector<short> digs;
        const int sgn = (n < 0 ? -1 : 1);
    
        while (n) {
            digs.push_back(abs(n % 10));
            n /= 10;
        }

        if (sgn == 1) sort(digs.begin(), digs.end());
        else sort(digs.begin(), digs.end(), greater<int>());
        
        int z = 0;
        long long k = 1;
        while (digs[z] == 0) {
            z++;
            k *= 10;
        }

        k *= digs[z];

        for (int i = z + 1; i < digs.size(); i++)
            k = k * 10 + digs[i];

        return sgn * k;
    }
};