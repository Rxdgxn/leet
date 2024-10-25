#include "../include.h"

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ret;
        ret.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string last = ret.back();
            last += '/';
            
            const int n = last.size();

            if (folder[i].substr(0, n) != last) {
                ret.push_back(folder[i]);
            }
        }

        return ret;
    }
};