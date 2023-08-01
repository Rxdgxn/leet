#include "../include.h"

class Solution {
public:
    int x[21];

    bool valid(int k) {
        for (int i = 1; i < k; i++)
            if (x[k] == x[i]) return false;

        if (k > 1 && x[k] <= x[k - 1]) return false;

        return true;
    }

    bool ok(int k, int p) {
        return k == p;
    }

    void add(vector<vector<int>> &ret, int k) {
        vector<int> v;
        for (int i = 1; i <= k; i++) v.push_back(x[i]);
        ret.push_back(v);
    }

    void back(int n, int p, int k, vector<vector<int>> &ret) {
        for (int i = 1; i <= n; i++) {
            x[k] = i;
            if (valid(k)) {
                if (ok(k, p)) add(ret, k);
                else back(n, p, k + 1, ret);
            }
        }
    }

    vector<vector<int>> combine(int n, int p) {
        vector<vector<int>> ret;
        back(n, p, 1, ret);
        return ret;
    }
};