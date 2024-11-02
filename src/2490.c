#include <string.h>
#include <stdbool.h>

bool isCircularSentence(char* sentence) {
    char *p = strtok(sentence, " ");

    char last = p[strlen(p) - 1];
    p = strtok(NULL, " ");

    while (p) {
        if (*p != last) return false;

        last = p[strlen(p) - 1];
        p = strtok(NULL, " ");
    }

    return *sentence == last;
}