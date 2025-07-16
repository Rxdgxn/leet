#include "../include.h"

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odds = 0, evens = 0;

        for (int n : nums) {
            odds += (n % 2 == 1);
            evens += (n % 2 == 0);
        }

        int ret = max(odds, evens);

        int f_odd_index = 0, f_even_index = 0;

        while (f_odd_index < nums.size() && nums[f_odd_index] % 2 == 0)
            f_odd_index++;

        while (f_even_index < nums.size() && nums[f_even_index] % 2 == 1)
            f_even_index++;

        bool odd = true;

        int x = 1;
        for (int i = f_odd_index; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && odd) {
                odd = false;
                x++;
            }
            else if (nums[i] % 2 == 1 && !odd) {
                odd = true;
                x++;
            }
        }

        ret = max(ret, x);

        odd = false;
        x = 1;
        for (int i = f_even_index; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && odd) {
                odd = false;
                x++;
            }
            else if (nums[i] % 2 == 1 && !odd) {
                odd = true;
                x++;
            }
        }

        ret = max(ret, x);

        return ret;
    }
};