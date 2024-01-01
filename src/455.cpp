#include "../include.h"

#define sort_v(v) sort((v).begin(), (v).end())

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;

        sort_v(g);
        sort_v(s);

        int s_it = 0, g_it = 0;

        while (s_it < s.size() && g_it < g.size()) {
            if (s[s_it] >= g[g_it]) g_it++;
            s_it++;
        }

        return g_it;
    }
};