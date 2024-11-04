#include <string.h>
#include <stdlib.h>

char* compressedString(char* word) {
    char comp[290001] = "";
    int len = 0, repeated = 1;

    char last = *(word++);
    
    while (*word) {
        if (*word == last) {
            repeated++;

            if (repeated == 9) {
                comp[len++] = '9';
                comp[len++] = *(word++);

                repeated = 1;
            }
        }
        else {
            comp[len++] = repeated + '0';
            comp[len++] = last;

            repeated = 1;
        }

        last = *(word++);

        if (*(word - 1) == 0) break;
    }

    if (last) {
        comp[len++] = repeated + '0';
        comp[len++] = last;
    }

    comp[len] = 0;

    char *ret = (char*) malloc((len + 1) * sizeof(char));
    strcpy(ret, comp);
    
    return ret;
}