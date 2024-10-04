#include "../include.h"

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        long long ret = 0;
        int st = 0, dr = skill.size() - 1;
        unordered_set<int> s;

        while (st <= dr) {
            s.insert(skill[st] + skill[dr]);
            if (s.size() > 1) return -1;

            ret += skill[st++] * skill[dr--];
        }

        return ret;
    }
};