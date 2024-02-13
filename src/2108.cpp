#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string& w : words) {
            const int n = w.size();
            bool ok = 1;

            for (int i = 0; i < n / 2 && ok; i++)
                if (w[i] != w[n - i - 1]) ok = 0;

            if (ok) return w;
        }

        return "";
    }
};