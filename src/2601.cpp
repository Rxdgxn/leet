#include "../include.h"

class Solution {
public:
    #define MAX 1001

    bool primeSubOperation(vector<int>& nums) {
        vector<int> sieve(MAX, 0);

        sieve[0] = sieve[1] = 1;

        for (int i = 2; i < MAX / 2; i++) {
            if (sieve[i] == 0) {
                int k = 2;

                while (i * k < MAX) {
                    sieve[i * k] = 1;
                    k++;
                }
            }
        }

        const int n = nums.size();

        int i = n - 2, prev = nums[n - 1];

        while (i >= 0) {
            
            if (nums[i] >= prev) {
                bool f = 0;

                for (int j = 2; j < nums[i]; j++) {
                    if (sieve[j] == 0 && nums[i] - j < prev) {
                        nums[i] -= j;
                        f = 1;
                        break;
                    }
                }

                if (!f) return false;
            }

            prev = nums[i];
            i--;
        }

        return true;
    }
};