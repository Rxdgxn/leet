#include "../include.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<char> node_set(n, 0); // A or B

        for (int i = 0; i < n; i++) {
            if (node_set[i]) continue;

            // First node of each component gets assigned to the first set
            node_set[i] = 'A';

            queue<pair<int, char>> q; // (node, set)
            q.push({i, 'A'});

            while (!q.empty()) {
                auto p = q.front();
                q.pop();

                for (int neighbor : graph[p.first]) {
                    if (p.second == 'A') {
                        if (node_set[neighbor] == 'A') {
                            return false;
                        }
                        else if (!node_set[neighbor]) {
                            node_set[neighbor] = 'B';
                            q.push({neighbor, 'B'});
                        }
                    }
                    else {
                        if (node_set[neighbor] == 'B') {
                            return false;
                        }
                        else if (!node_set[neighbor]) {
                            node_set[neighbor] = 'A';
                            q.push({neighbor, 'A'});
                        }
                    }
                }
            }
        }

        return true;
    }
};