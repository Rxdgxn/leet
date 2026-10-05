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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ret;
        ret.reserve(requests.size());

        auto dsu = DSU(n);

        for (auto& r : requests) {
            int x = dsu.find(r[0]);
            int y = dsu.find(r[1]);
            bool ok = true;

            if (x != y) {
                for (auto& rest : restrictions) {
                    int z = dsu.find(rest[0]);
                    int w = dsu.find(rest[1]);

                    if ((z == x && w == y) || (z == y && w == x)) {
                        ok = false;
                        break;
                    }
                }
            }

            ret.push_back(ok);
            if (ok) {
                dsu.merge(x, y);
            }
        }

        return ret;
    }
};