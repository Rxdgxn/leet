#include "../include.h"

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        auto target = times[targetFriend];

        sort(times.begin(), times.end());

        const int n = times.size();
        vector<int> chairTime(n, -1);

        for (auto& t : times) {
            for (int chair = 0; chair < n; chair++) {
                if (chairTime[chair] <= t[0]) {
                    chairTime[chair] = t[1];
                    
                    if (t == target) return chair;
                    break;
                }
            }
        }

        return 0;
    }
};