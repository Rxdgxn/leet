#include <stdio.h>
#include <string.h>

int minimumLength(char* s) {
    int l = 0, r = strlen(s) - 1;

    while (l <= r) {
        if (s[l] != s[r]) return r - l + 1;
        int k = 0;

        char x = s[l];
        
        while (s[l] == x && l <= r) {
            l++;
            k++;
        }
        while (s[r] == x && r >= l) {
            r--;
            k++;
        }

        if (k == 1) return 1;
    }

    return 0;
}