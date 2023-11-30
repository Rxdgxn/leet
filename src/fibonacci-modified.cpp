#include "../include.h"

// TODO: speed up multiplication
class BigNum {
public:
    vector<short> inner;

    BigNum(int x) {
        inner = vector<short>(50001, -69);
        int digits = floor(log10(x));
        
        while (digits >= 0) {
            inner[digits--] = x % 10;
            x /= 10;
        }
    }

    void display() {
        for (int c : inner) {
            if (c == -69) break;

            cout << c;
        }
        cout << endl;
    }

    BigNum operator+(BigNum& other) {
        auto it1 = find(inner.begin(), inner.end(), -69) - inner.begin() - 1;
        auto it2 = find(other.inner.begin(), other.inner.end(), -69) - other.inner.begin() - 1;

        int off = abs(it1 - it2), ok = 0;
        if (it1 < it2) {
            swap(inner, other.inner);
            swap(it1, it2);
            ok = 1;
        }

        for (int k = 0; k < off; k++) other.inner.insert(other.inner.begin(), 0);

        auto sum = vector<short>(50001, -69);

        int r = 0;
        for (int it = it1; it >= 0; it--) {
            sum[it] = inner[it] + other.inner[it] + r;

            if (sum[it] > 9) {
                sum[it] %= 10;
                r = 1;
            }
            else r = 0;
        }

        if (r) sum.insert(sum.begin(), r);

        auto ret = BigNum(0);
        ret.inner = sum;

        if (ok) swap(inner, other.inner);

        return ret;
    }

    BigNum operator*(BigNum& other) {
        if (inner[0] == 0 || other.inner[0] == 0) return BigNum(0);

        auto it1 = find(inner.begin(), inner.end(), -69) - inner.begin() - 1;
        auto it2 = find(other.inner.begin(), other.inner.end(), -69) - other.inner.begin() - 1;

        int ok = 0;
        if (it1 < it2) {
            swap(inner, other.inner);
            swap(it1, it2);
            ok = 1;
        }

        BigNum ret = BigNum(0);

        for (int j = it2; j >= 0; j--) {
            auto tmp = vector<short>(50001, -69);

            int r = 0;
            for (int i = it1; i >= 0; i--) {
                tmp[i] = other.inner[j] * inner[i] + r;

                if (tmp[i] > 9) {
                    r = tmp[i] / 10;
                    tmp[i] %= 10;
                }
                else r = 0;
            }

            if (r) tmp.insert(tmp.begin(), r);

            BigNum n = BigNum(0);
            n.inner = tmp;

            auto itn = find(n.inner.begin(), n.inner.end(), -69) - n.inner.begin();
            for (int i = 0; i < it2 - j; i++) n.inner[itn + i] = 0;
            ret = ret + n;
        }

        if (ok) swap(inner, other.inner);

        return ret;
    }
};

BigNum fibonacciModified(int t1, int t2, int n) {
    auto f = BigNum(0);
    auto f1 = BigNum(t1);
    auto f2 = BigNum(t2);

    if (n == 1) return f1;
    if (n == 2) return f2;

    for (int i = 3; i <= n; i++) {
        f = f1 + f2 * f2;
        f1 = f2;
        f2 = f;
    }

    return f;
}

int main(void) {

    int t1, t2, n;
    cin >> t1 >> t2 >> n;

    auto x = fibonacciModified(t1, t2, n);

    x.display();

    return 0;
}