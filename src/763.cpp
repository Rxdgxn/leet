#include "../include.h"

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        vector<int> ret;

        for (int i = 0; i < s.size(); i++)
            last[s[i]] = i;

        char ch = s[0];
        int it = 0, prev = 0;

        do {
            int mx = 0;
            while (it <= last[ch]) {
                if (last[s[it]] > mx) {
                    mx = last[s[it]];
                    ch = s[it];
                }
                it++;
            }

            if (it < s.size())
                ch = s[it];

            ret.push_back(it - prev);
            prev = it;
        } while (it < s.size());

        return ret;
    }
};