bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;

        while (l <= r) {
            long long p = (l + r) / 2;

            if (isBadVersion(p)) {
                r = p - 1;
                if (!isBadVersion(r)) return p;
            }
            else l = p + 1;
        }

        return n;
    }
};