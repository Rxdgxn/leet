#include "../include.h"

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int total_occurences[26] = {0};

        for (string& w : words2) {
            int tmp[26] = {0};

            for (char& c : w)
                tmp[c - 'a']++;

            for (int i = 0; i < 26; i++)
                total_occurences[i] = max(total_occurences[i], tmp[i]);
        }

        vector<string> ret;

        for (string& w : words1) {
            int tmp[26] = {0};

            for (char& c : w)
                tmp[c - 'a']++;

            bool ok = true;

            for (int i = 0; i < 26; i++)
                if (total_occurences[i] > tmp[i]) {
                    ok = false;
                    break;
                }

            if (ok) ret.push_back(w);
        }

        return ret;
    }
};