#include "../include.h"

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> ret(n);

    unordered_map<int, vector<int>> graph;
    for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    int visited[1001] = { 0 };
    visited[s] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(s, 1));

    while (!q.empty()) {
        int sz = q.size();

        while (sz > 0) {
            auto p = q.front();
            q.pop();

            int x = p.first, cnt = p.second;

            for (int node : graph[x]) {
                if (!visited[node]) {
                    visited[node] = 1;
                    q.push(make_pair(node, cnt + 1));

                    ret[node - 1] = cnt * 6;
                }
            }

            sz--;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) ret[i - 1] = -1;
    }

    ret.erase(ret.begin() + s - 1);

    return ret;
}

int main(void) {

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n, m, s;
        cin >> n >> m;

        vector<vector<int>> edges;
        for (int j = 0; j < m; j++) {
            vector<int> tmp(2);
            cin >> tmp[0] >> tmp[1];
            edges.push_back(tmp);
        }

        cin >> s;

        auto ret = bfs(n, m, edges, s);

        vout(ret, " ");
    }

    return 0;
}