#include "../include.h"

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;

        int open = 1;
        string next;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;

                if (open > 1) next += '(';
            }
            else {
                open--;

                if (open == 0) {
                    score += (next.empty() ? 1 : 2 * scoreOfParentheses(next));
                    next = "";
                }
                else next += ')';
            }
        }

        return score;
    }
};