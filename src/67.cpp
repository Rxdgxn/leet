#include "../include.h"

class Solution {
public:
    string addBinary(string a, string b) {
        while (a.size() < b.size())
            a.insert(a.begin(), '0');

        while (b.size() < a.size())
            b.insert(b.begin(), '0');

        string s;
        int carry = 0;

        for (int i = a.size() - 1; i >= 0; i--) {
            int add = a[i] + b[i] - 2 * '0' + carry;

            if (carry > 0)
                carry--;

            if (add > 1) {
                carry = 1;
                add %= 2;
            }

            s.push_back(add + '0');
        }

        if (carry > 0)
            s.push_back('1');

        reverse(s.begin(), s.end());

        return s;
    }
};