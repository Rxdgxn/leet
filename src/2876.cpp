#include "../include.h"

class Solution {
public:
    unordered_map<int, int> cycle_length, memo;
    unordered_set<int> vis;
    int n;

    void find_cycles(int node, vector<int>& edges, vector<int>& curr_path) {
        if (vis.find(node) != vis.end()) {
            const int sz = curr_path.size();

            if (cycle_length.find(node) != cycle_length.end()) {
                int next_length = cycle_length[node] + 1;

                for (int i = sz - 1; i >= 0; i--) {
                    memo[curr_path[i]] = next_length;
                    next_length++;
                }

                return;
            }

            if (memo.find(node) != memo.end()) {
                int next_length = memo[node] + 1;

                for (int i = sz - 1; i >= 0; i--) {
                    memo[curr_path[i]] = next_length;
                    next_length++;
                }

                return;
            }

            int start;

            for (int i = 0; i < sz; i++) {
                if (curr_path[i] == node) {
                    start = i;
                    break;
                }
            }

            int cycle_len = sz - start;

            for (int i = start; i < sz; i++)
                cycle_length[curr_path[i]] = cycle_len;

            for (int i = 0; i < start; i++)
                memo[curr_path[i]] = start - i + cycle_len;

            return;
        }

        vis.insert(node);
        curr_path.push_back(node);

        find_cycles(edges[node], edges, curr_path);
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        n = edges.size();
        vector<int> ret(n);

        for (int i = 0; i < n; i++) {
            vector<int> curr_path;

            if (vis.find(i) == vis.end())
                find_cycles(i, edges, curr_path);
        }

        for (int i = 0; i < n; i++) {
            if (cycle_length.find(i) != cycle_length.end()) {
                ret[i] = cycle_length[i];
                continue;
            }

            ret[i] = memo[i];
        }

        return ret;
    }
};