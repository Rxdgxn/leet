#include "../include.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> st;
        vector<string> ret;
        int it = 1, idx = 0;
        const int sz = target.size();

        while (it <= n && idx < sz) {
            st.push_back(it);
            ret.push_back("Push");

            if (target[idx] > it) {
                st.pop_back();
                ret.push_back("Pop");
                idx--;
            }

            idx++;
            it++;
        }

        return ret;
    }
};