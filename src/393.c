#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool validUtf8(int* data, int dataSize) {
    for (int i = 0; i < dataSize; i++) {
        int byte = data[i];
        char bits[8] = {0};
        int k = 7;

        while (byte) {
            bits[k--] = (byte & 1);
            byte >>= 1;
        }

        if (bits[0] == 0) continue;

        int n;

        for (n = 0; n < 8; n++) {
            if (bits[n] == 0) {
                break;
            }
        }

        if (n == 1 || n > 4 || n - 1 > dataSize - i) return false;

        int j;
        for (j = i + 1; j < i + n; j++) {
            int new_byte = data[j];
            char new_bits[8] = {0};
            k = 7;

            while (new_byte) {
                new_bits[k--] = (new_byte & 1);
                new_byte >>= 1;
            }

            if (new_bits[0] != 1 || new_bits[1] != 0) return false;
        }

        i = j - 1;
    }

    return true;
}