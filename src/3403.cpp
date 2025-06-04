#include "../include.h"

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;

        string ret;
        for (int i = 0; i < word.size(); i++) {
            ret = max(ret, word.substr(i, min(word.size() - i, word.size() - numFriends + 1)));
        }

        return ret;
    }
};