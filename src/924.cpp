#include "../include.h"

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& matrix, vector<int>& initial) {
        const int n = matrix.size();

        // size of each infected component -> nodes which caused the outbreak
        map<int, vector<int>> infect_count;
        unordered_map<int, int> is_initial;

        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j])
                    graph[i].push_back(j);

        sort(initial.begin(), initial.end());

        for (int i : initial)
            is_initial[i] = 1;

        for (int outbreak_node : initial) {
            if (!is_initial[outbreak_node]) continue;

            vector<int> visited(n, 0);

            queue<int> q;
            q.push(outbreak_node);
            visited[outbreak_node] = 1;

            int infected = 0;
            bool obsolete = false;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                infected++;

                if (is_initial[node] && node != outbreak_node) {
                    is_initial[node] = 0;
                    obsolete = true; // more initial nodes infect same component
                }

                for (int neighbor : graph[node])
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = 1;
                    }
            }

            if (!obsolete)
                infect_count[infected].push_back(outbreak_node);
        }

        // get the biggest "casualty" number
        if (infect_count.empty()) return initial[0];

        return infect_count.rbegin()->second[0];
    }
};