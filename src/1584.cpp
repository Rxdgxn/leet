#include "../include.h"

class Solution {
public:
    struct Edge {
        int weight;
        int i, j;
    };

    inline int weight(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    vector<int> parent;

    int find(int point) {
        if (parent[point] == point)
            return point;

        return parent[point] = find(parent[point]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        const int n = points.size();

        int ret = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                Edge e;
                e.weight = weight(points[i][0], points[i][1],  points[j][0], points[j][1]);
                e.i = i;
                e.j = j;

                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
            return a.weight < b.weight;
        });

        // init DSU
        parent = vector<int>(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& e : edges) {
            int root_i = find(e.i);
            int root_j = find(e.j);

            if (root_i != root_j) {
                ret += e.weight;

                // perform union
                if (rank[root_i] > rank[root_j])
                    parent[root_j] = root_i;
                else if (rank[root_i] < rank[root_j])
                    parent[root_i] = root_j;
                else {
                    parent[root_j] = root_i;
                    rank[root_i]++;
                }
            }
        }

        return ret;
    }
};