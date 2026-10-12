#include "../include.h"

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        }

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[a] = b;
            rank[b]++;
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& qs) {
        vector<vector<int>> queries(qs.size());

        for (int i = 0; i < qs.size(); i++) {
            queries[i] = qs[i];
            queries[i].push_back(i);
        }

        auto sort_lambda = [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        };

        sort(edgeList.begin(), edgeList.end(), sort_lambda);
        sort(queries.begin(), queries.end(), sort_lambda);

        auto dsu = DSU(n);
        auto edges_it = edgeList.begin();

        vector<bool> ret(queries.size());

        for (auto& q : queries) {
            auto lb = lower_bound(edges_it, edgeList.end(), q[2], [](vector<int>& a, int val) {
                return a[2] < val;
            });

            while (edges_it != lb) {
                auto& e = *edges_it;
                dsu.merge(e[0], e[1]);

                edges_it = next(edges_it);
            }

            ret[q[3]] = (dsu.find(q[0]) == dsu.find(q[1]));
        }

        return ret;
    }
};