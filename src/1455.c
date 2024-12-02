#include <string.h>

int isPrefixOfWord(char* sentence, char* searchWord) {
    char *p = strtok(sentence, " ");
    int i = 0;

    while (p) {
        char *f = strstr(p, searchWord);
        if (f == p)
            return i + 1;

        i++;
        p = strtok(NULL, " ");
    }

    return -1;
}