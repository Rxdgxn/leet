#include "../include.h"

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, 0), ret(n + 1);

        for (auto& p : paths) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                queue<int> q;
                visited[i] = 1;
                q.push(i);
                ret[i] = 1;

                while (!q.empty()) {
                    int x = q.front();
                    q.pop();

                    for (int n : graph[x]) {
                        if (!visited[n]) {
                            visited[n] = 1;
                            q.push(n);

                            vector<int> cols(5);

                            for (int j : graph[n])
                                cols[ret[j]] = 1;
                            
                            for (int c = 1; c <= 4; c++)
                                if (cols[c] == 0)
                                    ret[n] = c;
                        }
                    }
                }
            }
        }

        return vector<int>(ret.begin() + 1, ret.end());
    }
};