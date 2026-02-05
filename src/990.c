#include <stdbool.h>
#include <stdlib.h>

bool equationsPossible(char** equations, int n) {
    int values[26] = {0};
    int nextValue = 1;

    for (int i = 0; i < n; i++) {
        if (equations[i][1] == '!')
            continue;

        const int a = values[equations[i][0] - 'a'];
        const int b = values[equations[i][3] - 'a'];

        if (a != 0 && b == 0) {
            values[equations[i][3] - 'a'] = a;
        }
        else if (a == 0 && b != 0) {
            values[equations[i][0] - 'a'] = b;
        }
        else if (a != 0 && b != 0) {
            for (int j = 0; j < 26; j++) {
                if (values[j] == b) {
                    values[j] = a;
                }
            }
        }
        else {
            values[equations[i][0] - 'a'] = nextValue;
            values[equations[i][3] - 'a'] = nextValue;
            nextValue++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (equations[i][1] == '=')
            continue;

        const int a = values[equations[i][0] - 'a'];
        const int b = values[equations[i][3] - 'a'];

        // a!=a => false
        if (equations[i][0] == equations[i][3]) {
            return false;
        }

        // if both variables can be reduced to the same value
        if (a == b && a != 0) {
            return false;
        }
    }

    return true;
}