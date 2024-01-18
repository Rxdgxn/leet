class Solution {
public:
    int climbStairs(int n) {
        int s1 = 0, s2 = 1, s;

        for (int i = 0; i < n; i++) {
            s = s1 + s2;
            s1 = s2;
            s2 = s;
        }

        return s;
    }
};