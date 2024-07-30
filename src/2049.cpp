#include "../include.h"

class Solution {
public:
    int helper(int node, vector<vector<int>>& children, vector<int>& sizes) {
        int s = 1;

        for (int child : children[node]) {
            s += helper(child, children, sizes);
        }

        return sizes[node] = s;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        const int n = parents.size();

        vector<vector<int>> children(n);
        vector<int> sizes(n);

        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }
        
        long long m = 0;
        int mi = 0;

        helper(0, children, sizes);

        for (int remove = 0; remove < n; remove++) {
            long long y = max(1, n - sizes[remove]);

            for (int child : children[remove]) {
                y *= sizes[child];
            }

            if (y > m) {
                m = y;
                mi = 1;
            }
            else if (y == m) mi++;
        }

        return mi;
    }
};