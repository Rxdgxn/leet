#include "../include.h"

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        
        for (int a : asteroids) {
            if (a > 0) {
                ret.push_back(a);
            }
            else {
                bool skip = false;
                while (!ret.empty() && abs(a) >= ret.back() && ret.back() > 0) {
                    if (abs(a) == ret.back()) {
                        skip = true;
                        ret.pop_back();
                        break;
                    }
                    ret.pop_back();
                }

                if (skip) continue;
                if ((ret.empty() && !skip) || (!ret.empty() && ret.back() < 0)) ret.push_back(a);
            }
        }

        return ret;
    }
};