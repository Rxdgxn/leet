#include "../include.h"

class Solution {
public:
    void dfs(int n, vector<int>& edges, vector<int>& vis, vector<int>& d) {
        vis[n] = 1;
        int nxt = edges[n];

        if (nxt != -1 && !vis[nxt]) {
            d[nxt] = d[n] + 1;
            dfs(nxt, edges, vis, d);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2) return node1;

        const int n = edges.size();
        vector<int> vis1(n, 0), vis2(n, 0);
        vector<int> d1(n, INT_MAX), d2(n, INT_MAX);
        d1[node1] = d2[node2] = 0;
        
        dfs(node1, edges, vis1, d1);
        dfs(node2, edges, vis2, d2);
        
        int x = -1, m = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (max(d1[i], d2[i]) < m) {
                m = max(d1[i], d2[i]);
                x = i;
            }
        }

        return x;
    }
};