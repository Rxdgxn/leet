#include "../include.h"

class Solution {
public:
    vector<string> ret;

    void back(string& digits, int k, string& curr, vector<string>& letters) {
        if (k == digits.size()) {
            ret.push_back(curr);
            return;
        }

        for (char c : letters[digits[k] - '0' - 2]) {
            curr.push_back(c);
            back(digits, k + 1, curr, letters);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> letters = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string curr = "";

        back(digits, 0, curr, letters);

        return ret;
    }
};