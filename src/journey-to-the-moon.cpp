#include "../include.h"

unordered_map<int, vector<int>> graph;
int visited[100001];

void dfs(int i, int& count) {
    visited[i] = 1;
    count++;

    for (int n : graph[i])
        if (!visited[n]) dfs(n, count);
}

long long journeyToMoon(int n, vector<vector<int>>& astronauts) {
    long long k = 0, s = 0;

    for (const auto& p : astronauts) {
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int nodes = 0;
            dfs(i, nodes);

            s += nodes;
            k += nodes * nodes;
        }
    }

    // This idea was pretty much stolen
    return (s * s - k) / 2;
}

int main(void) {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> astronauts;

    for (int i = 0; i < p; i++) {
        vector<int> tmp(2);
        cin >> tmp[0] >> tmp[1];

        astronauts.push_back(tmp);
    }

    cout << journeyToMoon(n, astronauts);

    return 0;
}