#include "../include.h"

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int f = fruits[0], s = -1;
        int it = 1;

        int mf = 0, cnt = 1;
        int prev_fruit = fruits[0], last_cont = 1;

        while (it < fruits.size()) {
            if (fruits[it] != f && s == -1) {
                s = fruits[it];
            }
            else if (fruits[it] != f && fruits[it] != s) {
                f = prev_fruit;
                s = fruits[it];

                mf = max(mf, cnt);
                cnt = last_cont;
            }

            if (fruits[it] == prev_fruit) {
                last_cont++;
            }
            else {
                last_cont = 1;
                prev_fruit = fruits[it];
            }

            it++;
            cnt++;
        }

        mf = max(mf, cnt);

        return mf;
    }
};