#include "../include.h"

// TODO: speed up multiplication
class BigNum {
public:
    vector<short> inner;
    int len;

    BigNum(int x) {
        inner = vector<short>(50001, -69);

        int digits = (x == 0 ? 0 : floor(log10(x)));
        len = digits + 1;
        
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
        int it1 = len - 1;
        int it2 = other.len - 1;

        int off = abs(it1 - it2), ok = 0;
        if (it1 < it2) {
            swap(inner, other.inner);
            swap(it1, it2);
            swap(len, other.len);
            ok = 1;
        }

        for (int k = 0; k < off; k++) other.inner.emplace(other.inner.begin(), 0);

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

        if (r) sum.emplace(sum.begin(), r);

        auto ret = BigNum(0);
        ret.inner = sum;
        ret.len = len + (r != 0);

        if (ok) {
            swap(inner, other.inner);
            swap(len, other.len);
        }

        return ret;
    }

    BigNum operator*(BigNum& other) {
        if (inner[0] == 0 || other.inner[0] == 0) return BigNum(0);

        int it1 = len - 1;
        int it2 = other.len - 1;

        int ok = 0;
        if (it1 < it2) {
            swap(inner, other.inner);
            swap(it1, it2);
            swap(len, other.len);
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

            if (r) tmp.emplace(tmp.begin(), r);

            BigNum n = BigNum(0);
            n.inner = tmp;
            n.len = len + (r != 0);

            for (int i = 0; i < it2 - j; i++) n.inner[n.len + i] = 0;
            n.len += (it2 - j);

            ret = ret + n;
        }

        if (ok) {
            swap(inner, other.inner);
            swap(len, other.len);
        }

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