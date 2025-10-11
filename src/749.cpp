#include "../include.h"

class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& isInfected, int& possible, set<pair<int, int>>& visited, set<pair<int, int>>& at_risk) {
        visited.insert({i, j});

        if (i > 0) {
            if (isInfected[i - 1][j] == 1 && visited.find({i - 1, j}) == visited.end()) {
                dfs(i - 1, j, isInfected, possible, visited, at_risk);
            }
            else if (isInfected[i - 1][j] == 0) {
                possible++;
                at_risk.insert({i - 1, j});
            }
        }
        if (j > 0) {
            if (isInfected[i][j - 1] == 1 && visited.find({i, j - 1}) == visited.end()) {
                dfs(i, j - 1, isInfected, possible, visited, at_risk);
            }
            else if (isInfected[i][j - 1] == 0) {
                possible++;
                at_risk.insert({i, j - 1});
            }
        }
        if (i < m - 1) {
            if (isInfected[i + 1][j] == 1 && visited.find({i + 1, j}) == visited.end()) {
                dfs(i + 1, j, isInfected, possible, visited, at_risk);
            }
            else if (isInfected[i + 1][j] == 0) {
                possible++;
                at_risk.insert({i + 1, j});
            }
        }
        if (j < n - 1) {
            if (isInfected[i][j + 1] == 1 && visited.find({i, j + 1}) == visited.end()) {
                dfs(i, j + 1, isInfected, possible, visited, at_risk);
            }
            else if (isInfected[i][j + 1] == 0) {
                possible++;
                at_risk.insert({i, j + 1});
            }
        }
    }

    void contain(int i, int j, vector<vector<int>>& isInfected) {
        isInfected[i][j] = 2;

        if (i > 0 && isInfected[i - 1][j] == 1) contain(i - 1, j, isInfected);
        if (j > 0 && isInfected[i][j - 1] == 1) contain(i, j - 1, isInfected);
        if (i < m - 1 && isInfected[i + 1][j] == 1) contain(i + 1, j, isInfected);
        if (j < n - 1 && isInfected[i][j + 1] == 1) contain(i, j + 1, isInfected);
    }

    void contaminate(int i, int j, vector<vector<int>>& isInfected, set<pair<int, int>>& vis, vector<pair<int, int>>& newly_infected) {
        vis.insert({i, j});

        if (i > 0) {
            if (isInfected[i - 1][j] == 1 && vis.find({i - 1, j}) == vis.end()) {
                contaminate(i - 1, j, isInfected, vis, newly_infected);
            }
            else if (isInfected[i - 1][j] == 0) {
                newly_infected.push_back({i - 1, j});
                vis.insert({i - 1, j});
            }
        }
        if (j > 0) {
            if (isInfected[i][j - 1] == 1 && vis.find({i, j - 1}) == vis.end()) {
                contaminate(i, j - 1, isInfected, vis, newly_infected);
            }
            else if (isInfected[i][j - 1] == 0) {
                newly_infected.push_back({i, j - 1});
                vis.insert({i, j - 1});
            }
        }
        if (i < m - 1) {
            if (isInfected[i + 1][j] == 1 && vis.find({i + 1, j}) == vis.end()) {
                contaminate(i + 1, j, isInfected, vis, newly_infected);
            }
            else if (isInfected[i + 1][j] == 0) {
                newly_infected.push_back({i + 1, j});
                vis.insert({i + 1, j});
            }
        }
        if (j < n - 1) {
            if (isInfected[i][j + 1] == 1 && vis.find({i, j + 1}) == vis.end()) {
                contaminate(i, j + 1, isInfected, vis, newly_infected);
            }
            else if (isInfected[i][j + 1] == 0) {
                newly_infected.push_back({i, j + 1});
                vis.insert({i, j + 1});
            }
        }
    }

    int containVirus(vector<vector<int>>& isInfected) {
        m = isInfected.size();
        n = isInfected[0].size();

        int walls = 0;

        for (;;) {
            vector<pair<int, int>> outbreaks;
            pair<int, int> contained;
            set<pair<int, int>> visited;

            int max_to_infect = 0, max_walls = 0;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && visited.find({i, j}) == visited.end()) {
                        int possible = 0;
                        set<pair<int, int>> at_risk;

                        dfs(i, j, isInfected, possible, visited, at_risk);
                        outbreaks.push_back({i, j});

                        if (at_risk.size() > max_to_infect) {
                            max_to_infect = at_risk.size();
                            contained = {i, j};
                            max_walls = possible;
                        }
                    }
                }
            }

            if (max_to_infect == 0) break;

            walls += max_walls;

            contain(contained.first, contained.second, isInfected);

            visited.clear();

            for (auto& p : outbreaks) {
                if (p == contained) continue;

                vector<pair<int, int>> to_infect;
                contaminate(p.first, p.second, isInfected, visited, to_infect);

                for (auto& p : to_infect)
                    isInfected[p.first][p.second] = 1;
            }
        }

        return walls;
    }
};