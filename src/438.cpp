#include "../include.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios::sync_with_stdio(false);
        cin.tie();
        
        vector<int> ret;

        unordered_map<char, int> pmap, smap;
        int n = s.size(), m = p.size(), i = 0;

        for (char& c : p) pmap[c]++;

        while (i < m) smap[s[i++]]++;

        while (i < n) {
            int ok = 1;

            for (auto it = pmap.begin(); it != pmap.end() && ok; it++)
                if (it->second != smap[it->first])
                    ok = 0;

            if (ok) ret.push_back(i - m);

            smap[s[i - m]]--;
            smap[s[i++]]++;
        }

        int ok = 1;

        for (auto it = pmap.begin(); it != pmap.end() && ok; it++)
            if (it->second != smap[it->first])
                ok = 0;

        if (ok) ret.push_back(i - m);

        return ret;
    }
};