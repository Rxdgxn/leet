#include "include.h"

class Solution {
public:
    // Pretty slow
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ret;
        map<string, int> m;

        for (string name : names) {
            if (!m[name]) {
                m[name]++;
                ret.push_back(name);
            }
            else {
                string n = name + "(" + to_string(m[name]) + ")";
                while (m[n]) {
                    n = name + "(" + to_string(++m[name]) + ")";
                }
                m[n]++;
                ret.push_back(n);
            }
        }

        return ret;
    }
};