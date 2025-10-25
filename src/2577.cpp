#include "../include.h"

struct Cell {
    int i, j;
    int time;
};

class Compare {
public:
	bool operator()(Cell& a, Cell& b) {
		return b.time < a.time;
	}
};

const int dirs[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        priority_queue<Cell, vector<Cell>, Compare> q;
        q.push({0, 0, 0});

        const int m = grid.size(), n = grid[0].size();

        map<pair<int, int>, int> visited;
        visited[make_pair(0, 0)] = 1;

        while (!q.empty()) {
            Cell c = q.top();
            q.pop();

            if (c.i == m - 1 && c.j == n - 1)
                return c.time;

            for (int i = 0; i < 4; i++) {
                const int new_i = c.i + dirs[i][0];
                const int new_j = c.j + dirs[i][1];

                const auto p = make_pair(new_i, new_j);

                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[p]) {
                    const int next_time = max(grid[new_i][new_j] + ((grid[new_i][new_j] - c.time) % 2 == 0 ? 1 : 0), c.time + 1);
                    
                    visited[p] = 1;
                    q.push({new_i, new_j, next_time});
                }
            }
        }

        return -1;
    }
};