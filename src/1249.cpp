#include "../include.h"

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, k = 0;
        string ret;
        vector<int> extras;

        for (int i = 0; i < s.size(); i++) {
            const char ch = s[i];

            if (ch == ')') {
                if (open > 0) {
                    open--;
                    extras.pop_back();
                    ret.push_back(ch);
                    k++;
                }
            }
            else if (ch == '(') {
                open++;
                extras.push_back(k);
                ret.push_back(ch);
                k++;
            }
            else {
                ret.push_back(ch);
                k++;
            }
        }

        int removed = 0;
        for (int i : extras) {
            ret.erase(ret.begin() + i - removed++);
        }

        return ret;
    }
};