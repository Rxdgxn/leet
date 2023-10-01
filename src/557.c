#include <stdio.h>
#include <string.h>

char* reverseWords(char* s) {
    static char ret[50001];
    int len = 0;

    char* ptr = strtok(s, " ");
    while (ptr != NULL) {
        for (int i = strlen(ptr) - 1; i >= 0; i--)
            ret[len++] = ptr[i];

        ret[len++] = ' ';

        ptr = strtok(NULL, " ");
    }

    ret[len - 1] = '\0';

    return ret;
}