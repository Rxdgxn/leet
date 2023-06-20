#include "../include.h"
using namespace std;

const int MOD = 1000000007;

int multiply(int a, int b) {
    return ((long long)a * b) % MOD;
}

int fact(int beg, int end) {
    int prod = 1;
    for (int i = beg; i <= end; i++) {
        prod = multiply(prod, i);
    }
    return prod;
}

int power(int base, int exponent) {
    if (exponent == 0)
        return 1;

    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = multiply(result, base);
        base = multiply(base, base);
        exponent /= 2;
    }

    return result;
}

int solve(int n, int m) {
    if (m + n - 1 <= m)
        return m;

    int f1 = fact(n + 1, n + m - 1);
    int f2 = fact(1, m - 1);
    int inverse_f2 = power(f2, MOD - 2);

    return multiply(f1, inverse_f2);
    // comb(n + m - 1, n) = (n + m - 1)! / (n! * (m - 1)!)
}

// Apparently I had to use something called 'modular inverse'. Thanks, GPT.

int main(void) {
    int t;
    cin >> t;

    int ret[201];
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        ret[i] = solve(n, m);
    }

    for (int i = 0; i < t; i++) {
        cout << ret[i] << endl;
    }

    return 0;
}
