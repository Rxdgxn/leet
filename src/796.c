#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal) {
    int indices[100], k = 0;
    const int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == goal[0]) {
            indices[k++] = i;
        }
    }

    if (k == 0 || strlen(goal) != n) return false;

    for (int it = 0; it < k; it++) {
        bool ok = true;
        int j = 0;

        for (int i = indices[it]; j < n; i++, j++) {
            if (s[i % n] != goal[j]) {
                ok = false;
                break;
            }
        }

        if (ok) return true;
    }

    return false;
}