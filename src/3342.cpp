#include "../include.h"

class Solution {
public:
    struct State {
        int i, j;
        int time, parity;
    };

    struct Compare {
        bool operator()(State& a, State& b) {
            return a.time > b.time;
        }
    };

    const int dirs[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<State, vector<State>, Compare> pq;
        pq.push({0, 0, 0, 0});

        const int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));

        while (!pq.empty()) {
            State s = pq.top();
            pq.pop();

            visited[s.i][s.j] = s.time;

            if (s.i == n - 1 && s.j == m - 1)
                return s.time;

            for (int i = 0; i < 4; i++) {
                int ni = s.i + dirs[i][0];
                int nj = s.j + dirs[i][1];

                if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                int new_time = max(s.time, moveTime[ni][nj]) + 1 + s.parity;

                if (visited[ni][nj] > new_time) {
                    pq.push({ni, nj, new_time, !s.parity});
                    visited[ni][nj] = new_time;
                }
            }
        }

        return -1;
    }
};