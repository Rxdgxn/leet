#include "../include.h"

class Solution {
public:
    string ret;
    vector<char> chars = {'a', 'b', 'c'};

    void helper(string s, int len, int n, int& k) {
        if (k <= 0) return;

        if (len < n) {
            for (char ch : chars) {
                if (len == 0) {
                    s.push_back(ch);
                    helper(s, len + 1, n, k);
                    s.pop_back();
                }
                else if (s[len - 1] != ch) {
                    s.push_back(ch);
                    helper(s, len + 1, n, k);
                    s.pop_back();
                }
            }
        }
        else if (len == n) {
            k--;
            if (k == 0) {
                ret = s;
                return;
            }
        }
        else {
            return;
        }
    }

    string getHappyString(int n, int k) {
        helper("", 0, n, k);
        return ret;
    }
};