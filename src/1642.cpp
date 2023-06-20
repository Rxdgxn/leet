#include "../include.h"

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // "Inspired" by other solutions

        priority_queue<int> q;
        int i, d;
        for (i = 0; i < heights.size() - 1; i++) {
            d = heights[i+1] - heights[i];
            if (d > 0) {
                bricks -= d;
                q.push(d);
                if (bricks < 0) {
                    bricks += q.top();
                    q.pop();
                    ladders--;
                }
                if (ladders < 0) break;
            }
        }
        return i;
    }
};