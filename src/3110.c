#include <string.h>
#include <math.h>

int scoreOfString(char* s) {
    int score = 0;

    for (int i = 0; i < strlen(s) - 1; i++)
        score += abs(s[i] - s[i + 1]);

    return score;
}