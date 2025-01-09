#include "../include.h"

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        map<int, int> partitions; // interval = [a; b]
        vector<bool> ret;

        int prev = nums[0];
        int first = 0;

        const int m = nums.size();
        
        partitions[first] = 0;

        for (int i = 1; i < m; i++) {
            char b1 = prev & 1, b2 = nums[i] & 1;

            if (b1 ^ b2) {
                partitions[first] = i;
            }
            else {
                first = i;

                if (i == m - 1) partitions[i] = i;
            }

            prev = nums[i];
        }

        vector<int> keys;
        for (const auto& [k, _] : partitions) {
            keys.push_back(k);
        }

        const int n = keys.size();

        for (const auto& q : queries) {
            const int& from = q[0];
            const int& to = q[1];

            if (from == to) {
                ret.push_back(true);
                continue;
            }

            int st = 0, dr = n - 1;
            bool updated = false;

            while (st <= dr) {
                int p = (st + dr) / 2;

                if (keys[p] == from) {
                    ret.push_back(partitions[from] >= to);
                    updated = true;
                    break;
                }
                else if (keys[p] < from) {
                    if (partitions[keys[p]] >= to) {
                        ret.push_back(true);
                        updated = true;
                        break;
                    }

                    st = p + 1;
                }
                else {
                    dr = p - 1;
                }
            }

            if (updated) continue;

            ret.push_back(false);
        }

        return ret;
    }
};