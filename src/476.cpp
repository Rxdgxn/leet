class Solution {
public:
    int findComplement(int num) {
        int order = 0, n = 0;

        while (num) {
            int r = num % 2;
            num >>= 1;

            if (r == 0) n += (1 << order);

            order++;
        }

        return n;
    }
};