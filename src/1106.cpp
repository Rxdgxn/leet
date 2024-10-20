#include <stdbool.h>
#include <string.h>

int max_size;

bool eval(char* expression, int* i) {
    if (*i >= max_size) return false;

    char c = expression[(*i)++];

    if (c == 't') return true;
    if (c == 'f') return false;

    if (c == '!') {
        (*i)++;
        bool res = !eval(expression, i);
        (*i)++;
        return res;
    }

    bool vals[1024];
    int len = 0;

    (*i)++;

    while (*i < max_size && expression[*i] != ')') {
        if (expression[*i] != ',') {
            vals[len++] = eval(expression, i);
        }
        else {
            (*i)++;
        }
    }
    (*i)++;

    if (c == '&') {
        for (int j = 0; j < len; j++) {
            if (vals[j] == false) {
                return false;
            }
        }

        return true;
    }
    if (c == '|') {
        for (int j = 0; j < len; j++) {
            if (vals[j] == true) {
                return true;
            }
        }
        
        return false;
    }

    return false;
}

bool parseBoolExpr(char* expression) {
    int i = 0;
    max_size = strlen(expression);

    return eval(expression, &i);
}
