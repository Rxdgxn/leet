#include <string.h>

int longestPalindrome(char* s) {
    int map[128] = {0}, len = 0, odd = 0;

    for (int i = 0; i < strlen(s); i++) {
        map[s[i]]++;
    }

    for (char c = 'A'; c <= 'z'; c++) {
        if (map[c] % 2 == 0) len += map[c];
        else {
            len += map[c] - 1;
            odd = 1;
        }
    }

    return len + odd;
}