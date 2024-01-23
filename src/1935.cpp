#include "../include.h"

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ret = 0;

        auto txt = (char*)text.c_str();

        char *p = new char[1000];
        p = strtok(txt, " ");

        while (p != NULL) {
            int ok = 1;

            for (char c : brokenLetters) {
                if (strchr(p, c) != NULL) {
                    ok = 0;
                    break;
                }
            }

            ret += ok;

            p = strtok(NULL, " ");
        }

        return ret;
    }
};