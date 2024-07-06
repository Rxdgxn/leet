class Solution {
public:
    int passThePillow(int n, int time) {
        int q = time / (n - 1), r = time % (n - 1);

        if (q % 2) return n - r;
        return r + 1;
    }
};