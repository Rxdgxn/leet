class Solution {
public:
    bool balanced(int x) {
        int map[10] = {0};

        do {
            map[x % 10]++;
            x /= 10;
        } while (x > 0);

        for (int d = 0; d <= 9; d++)
            if (map[d] > 0 && map[d] != d)
                return false;

        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++)
            if (balanced(i))
                return i;

        return -1;
    }
};