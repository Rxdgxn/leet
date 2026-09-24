#include "../include.h"

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto& e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int min_cities = n;
        int best_city = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int cities = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    cities++;
                }
            }

            if (cities < min_cities) {
                min_cities = cities;
                best_city = i;
            }
        }

        return best_city;
    }
};