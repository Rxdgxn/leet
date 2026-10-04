#include "../include.h"

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        const int n = friends.size();

        queue<pair<int, int>> q; // (person, level)
        vector<bool> visited(n, false);
        unordered_map<string, int> freq;

        q.push({id, 0});
        visited[id] = true;

        while (!q.empty()) {
            auto [node, l] = q.front();
            q.pop();

            if (l == level) {
                for (string& v : watchedVideos[node]) {
                    freq[v]++;
                }

                continue;
            }

            for (int neigh : friends[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push({neigh, l + 1});
                }
            }
        }

        // Fancy use of std::move, even though the video names are at most 8 chars long
        vector<pair<int, string>> ordered;

        for (auto& [v, f] : freq) {
            ordered.push_back({f, std::move(v)});
        }

        sort(ordered.begin(), ordered.end());

        vector<string> ret;
        ret.reserve(ordered.size());

        for (auto& [_, v] : ordered) {
            ret.push_back(std::move(v));
        }

        return ret;
    }
};