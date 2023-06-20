class Solution {
public:
    int mySqrt(int x) {
        long long st = 1, dr = x, m;
        if (x == 0) return 0;
        while (st < dr) {
            m = (st + dr) / 2;
            if (m < x / m && (m + 1) > x / (m + 1)) return m;
            if (m > x / m) dr = m;
            else if (m < x / m) st = m;
            else return m;
        }
        return dr;
    }
};