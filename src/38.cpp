#include "../include.h"

class Solution {
public:
    string func(int k, int n, string prev) {
        char c = prev[0];
        int cnt = 1;
        string curr = "";

        const int sz = prev.size();
        for (int i = 1; i < sz; i++) {
            if (prev[i] == c) cnt++;
            else {
                curr += to_string(cnt);
                cnt = 1;
                curr += c;
                c = prev[i];
            }
        }

        curr += to_string(cnt);
        curr += prev[sz - 1];

        if (k < n) return func(k + 1, n, curr);
        return curr;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";
        return func(2, n, "1");
    }
};