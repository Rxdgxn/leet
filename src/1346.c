#include <stdbool.h>

#define OFFSET 2000
bool checkIfExist(int* arr, int arrSize) {
    int map[4001] = {0};

    for (int i = 0; i < arrSize; i++) {
        if (map[2 * arr[i] + OFFSET] || (arr[i] % 2 == 0 && map[arr[i] / 2 + OFFSET]))
            return true;

        map[arr[i] + OFFSET] = 1;
    }

    return false;
}