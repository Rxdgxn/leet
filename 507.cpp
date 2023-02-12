class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;

        int s = 1;
        for (int d = 2; d * d < num; d++)
            if (num % d == 0) {
                s += d + num / d;
            }
        return s == num;
    }
};