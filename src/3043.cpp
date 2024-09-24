#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    inline int len(int x) {
        int l = 1;

        while (x > 9) {
            l++;
            x /= 10;
        }

        return l;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m1, m2;

        for (int n : arr1) {
            while (n) {
                m1[n]++;
                n /= 10;
            }
        }
        for (int n : arr2) {
            while (n) {
                m2[n]++;
                n /= 10;
            }
        }

        int mx = 0;

        for (auto& [k, _] : m1) {
            if (m2[k]) {
                mx = max(mx, len(k));
            }
        }

        return mx;
    }
};