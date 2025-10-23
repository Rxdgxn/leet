#include "../include.h"

class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ret;
        unordered_set<string> segments;

        string segm;

        for (char c : s) {
            segm += c;

            if (segments.find(segm) == segments.end()) {
                segments.insert(segm);
                ret.push_back(segm);

                segm.clear();
            }
        }

        return ret;
    }
};