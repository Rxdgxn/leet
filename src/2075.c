#include <stdio.h>
#include <string.h>

char ret[1000001];

char* decodeCiphertext(char* encodedText, int rows) {
    memset(ret, 0, 1000001);

    const int len = strlen(encodedText);
    int cols = len / rows;
    
    int k = 0;

    for (int i = 0; i < cols; i++) {
        for (int j = i; j < len; j += (cols + 1)) {
            ret[k++] = encodedText[j];
        }
    }
    
    while (k - 1 >= 0 && ret[k - 1] == ' ') k--;
    ret[k] = 0;
    
    return ret;
}