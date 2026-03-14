#include "../include.h"

class Solution {
public:
    vector<vector<string>> ret;

    bool palindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    void back(string s, vector<string> parts) {
        if (s.size() == 1) {
            parts.push_back(s);
            ret.push_back(parts);
            return;
        }

        for (int i = 1; i < s.size(); i++) {
            string first = s.substr(0, i);

            if (!palindrome(first))
                continue;

            parts.push_back(first);
            back(s.substr(i), parts);
            parts.pop_back();
        }

        if (palindrome(s)) {
            parts.push_back(s);
            ret.push_back(parts);
        }
    }

    vector<vector<string>> partition(string s) {
        back(s, {});
        return ret;
    }
};