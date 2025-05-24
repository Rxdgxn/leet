#include "../include.h"

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> routesForStop;
        unordered_map<int, int> visited;
        queue<int> q;

        for (int r = 0; r < routes.size(); r++)
            for (int stop : routes[r])
                routesForStop[stop].push_back(r);

        for (int r : routesForStop[source])
            q.push(r);

        int buses = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int r = q.front();
                q.pop();

                if (visited[r]) continue;
                visited[r] = 1;

                for (int stop : routes[r]) {
                    if (stop == target)
                        return buses;

                    for (int next : routesForStop[stop])
                        q.push(next);
                }
            }

            buses++;
        }

        return -1;
    }
};