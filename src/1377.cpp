#include "../include.h"

class Solution {
public:
    struct Item {
        int node, time;
        double prob;
    };

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> tree(n + 1);

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n + 1, false);
        queue<Item> q;

        q.push({1, 0, 1});
        visited[1] = true;

        while (!q.empty()) {
            auto [node, time, prob] = q.front();
            q.pop();

            if (time > t)
                break;

            if (node == target) {
                if (time == t)
                    return prob;

                for (int neigh : tree[node])
                    if (!visited[neigh])
                        return 0; // can jump to another vertex

                return prob; // jumps forever in place
            }

            double next_prob;

            if (node == 1)
                next_prob = prob / tree[node].size();
            else
                next_prob = prob / (tree[node].size() - 1); // its parent

            for (int neigh : tree[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push({neigh, time + 1, next_prob});
                }
            }
        }

        return 0;
    }
};