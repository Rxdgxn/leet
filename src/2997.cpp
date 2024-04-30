#include "../include.h"

class Solution {
public:
    byte matrix[100001][32];
    byte result[32];

    int minOperations(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie();

        int len = 0, ret = 0;

        for (int n : nums) {
            int i = 31;

            while (n) {
                matrix[len][i--] = static_cast<byte>(n % 2);
                n >>= 1;
            }

            len++;
        }
        
        int i = 31;
        while (k) {
            result[i--] = static_cast<byte>(k % 2);
            k >>= 1;
        }

        for (int j = 31; j >= 0; j--) {
            byte x = matrix[0][j];

            for (int i = 1; i < len; i++)
                x ^= matrix[i][j];
            
            if (x != result[j]) ret++;
        }

        return ret;
    }
};