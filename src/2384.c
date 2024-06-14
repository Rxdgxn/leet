#include <string.h>

char ret[100001];

char* largestPalindromic(char* num) {
    memset(ret, 0, 100001);

    int map[10] = {0}, mid = -1, ex = -1, k = 0;

    while (*num) {
        map[*num - '0']++;
        num++;
    }

    for (int d = 9; d >= 0; d--) {
        if (map[d] % 2 == 0) {
            for (int i = 0; i < map[d] / 2; i++)
                ret[k++] = d + '0';
        }
        else {
            for (int i = 0; i < map[d] / 2; i++)
                ret[k++] = d + '0';

            if (mid < 0) mid = d;
        }
    }

    if (mid >= 0) ret[k++] = mid + '0';
    
    for (int i = k - 1 - (mid >= 0); i >= 0; i--)
        ret[k++] = ret[i];

    int z = 0;
    while (ret[z] == '0') z++;

    ret[k - z] = 0;
    strcpy(ret, ret + z);

    if (*ret == 0) return "0";

    return ret;
}