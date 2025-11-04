#include "../include.h"

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> freq(51, 0);
        map<int, set<int>> max_frequencies;
        vector<int> xsums;

        for (int i = 0; i < k; i++)
            freq[nums[i]]++;

        for (int i = 0; i < k; i++)
            max_frequencies[freq[nums[i]]].insert(nums[i]);
        
        int xsum = 0;

        int ops = 0;
        for (auto it = max_frequencies.rbegin(); it != max_frequencies.rend() && ops < x; it++) {
            for (auto it2 = it->second.rbegin(); it2 != it->second.rend() && ops < x; it2++) {
                xsum += *it2 * it->first;
                ops++;
            }
        }

        xsums.push_back(xsum);

        for (int i = k; i < nums.size(); i++) {
            max_frequencies[freq[nums[i - k]]--].erase(nums[i - k]);
            max_frequencies[freq[nums[i - k]]].insert(nums[i - k]);

            max_frequencies[freq[nums[i]]++].erase(nums[i]);
            max_frequencies[freq[nums[i]]].insert(nums[i]);

            xsum = 0;
            ops = 0;

            for (auto it = max_frequencies.rbegin(); it != max_frequencies.rend() && ops < x; it++) {
                for (auto it2 = it->second.rbegin(); it2 != it->second.rend() && ops < x; it2++) {
                    xsum += *it2 * it->first;
                    ops++;
                }
            }

            xsums.push_back(xsum);
        }

        return xsums;
    }
};