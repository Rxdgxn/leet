#include "../include.h"

class Solution {
public:
    struct fraction {
        // a / b;
        int a, b;
    };

    friend fraction operator+ (fraction& f1, fraction& f2) {
        fraction f;
        f.a = f1.a * f2.b + f2.a * f1.b;
        f.b = f1.b * f2.b;

        if (f.a == 0) return {0, 1};

        int n = min(f.a, f.b), m = max(f.a, f.b);

        for (int d = 2; d * d <= abs(n) && abs(n) != 1 && m != 1; d++) {
            while (n % d == 0 && m % d == 0) {
                n /= d;
                m /= d;
            }
        }

        if (f.a < f.b) {
            f.a = n;
            f.b = m;
        }
        else {
            f.a = m;
            f.b = n;
        }

        return f;
    }

    string fractionAddition(string expression) {
        auto s = (char*) expression.c_str();
        char t[1001];
        strcpy(t, s);

        char *p = strtok(t, "/+-");
        int k = 0;

        fraction F = {0, 1};
        fraction f;

        while (p != NULL) {

            if (k % 2 == 0) {
                if (p - t > 0 && s[p - t - 1] == '-') f.a = -1 * atoi(p);
                else f.a = atoi(p);
            }
            else {
                f.b = atoi(p);
                F = F + f;
            }
            
            p = strtok(NULL, "/+-");
            k++;
        }

        return to_string(F.a) + "/" + to_string(F.b);
    }
};