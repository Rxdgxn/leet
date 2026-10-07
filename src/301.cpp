#include "../include.h"

class Solution {
public:
    vector<pair<string, int>> possible;
    int min_removals = INT_MAX;

    void take(const string& original, int index, string& curr, int open, int removals) {
        if (open < 0 || removals > min_removals)
            return;

        if (index == original.size()) {
            if (open == 0) {
                min_removals = removals;
                possible.push_back({curr, removals});
            }
            return;
        }

        if (isalpha(original[index])) {
            curr.push_back(original[index]);
            take(original, index + 1, curr, open, removals);
            curr.pop_back();
            return;
        }

        int add = original[index] == '(' ? 1 : -1;
        curr.push_back(original[index]);
        take(original, index + 1, curr, open + add, removals);

        curr.pop_back();
        take(original, index + 1, curr, open, removals + 1);
    }

    vector<string> removeInvalidParentheses(string s) {
        string curr = "";
        take(s, 0, curr, 0, 0);

        unordered_set<string> ret;

        for (auto& [s, r] : possible) {
            if (r == min_removals) {
                ret.insert(s);
            }
        }

        return vector<string>(ret.begin(), ret.end());
    }
};