#include "../include.h"

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        int iterations = 1 << n;
        int valid_sets = 1; // the empty set

        // we skip the empty set
        for (int indices = 1; indices < iterations; indices++) {
            // first select indices from the vertex vector
            set<int> chosen_branches;

            for (int i = 0; i < n; i++)
                if ((1 << i) & indices)
                    chosen_branches.insert(n - i - 1);

            // then apply roy-floyd to the set
            vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));

            for (int i : chosen_branches)
                dist[i][i] = 0;

            for (int i : chosen_branches)
                for (auto [j, w] : graph[i])
                    dist[i][j] = min(dist[i][j], (long long) w);

            for (int k : chosen_branches)
                for (int i : chosen_branches)
                    for (int j : chosen_branches)
                        if (dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];

            bool ok = true;

            for (int i : chosen_branches) {
                for (int j : chosen_branches) {
                    if (dist[i][j] > (long long) maxDistance) {
                        ok = false;
                        break;
                    }
                }

                if (!ok)
                    break;
            }

            if (ok)
                valid_sets++;
        }

        return valid_sets;
    }
};