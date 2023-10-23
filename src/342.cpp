class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return true;

        long long k = 4;
        while (k < n) k *= 4;

        return k == n;
    }
};