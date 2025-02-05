#include <stdbool.h>

bool areAlmostEqual(char* s1, char* s2) {
    int disc = 0;
    const int sz = strlen(s1);

    char c1, c2;

    for (int i = 0; i < sz; i++) {
        if (s1[i] != s2[i]) {
            disc++;

            if (disc == 1) {
                disc = 1;
                c1 = s1[i];
                c2 = s2[i];
            }
            else if (disc > 2 || s1[i] != c2 || s2[i] != c1)
                return false;
        }
    }

    return disc != 1;
}