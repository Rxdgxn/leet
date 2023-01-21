#include "include.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        char *p = new char[10001];
        char last[10001];
        p = strtok((char* )(s.c_str()), " ");
        while (p) {
            strcpy(last, p);
            p = strtok(NULL, " ");
        }
        return (int)strlen(last);
    }
};