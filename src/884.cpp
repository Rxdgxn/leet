#include "../include.h"

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ret;

        unordered_map<string, int> m1, m2;

        auto cs1 = (char*) s1.c_str(), cs2 = (char*) s2.c_str();

        char *p = strtok(cs1, " ");

        while (p) {
            m1[p]++;
            p = strtok(NULL, " ");
        }

        p = strtok(cs2, " ");

        while (p) {
            m2[p]++;
            p = strtok(NULL, " ");
        }

        for (auto& [k, v] : m1) {
            if (v == 1 && !m2[k]) ret.push_back(k);
        }
        for (auto& [k, v] : m2) {
            if (v == 1 && !m1[k]) ret.push_back(k);
        }

        return ret;
    }
};