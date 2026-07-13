#include "../include.h"

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        map<int, set<int>> spaces; // (free distance, begin indices)
        map<int, int> index_space;

        vector<bool> ret;
        ret.reserve(queries.size());

        // TODO: apparently segment tree was the way to go
        // Somehow this "O(n^2)" solution passes

        for (auto& q : queries) {
            if (q[0] == 1) {
                // Adding block
                if (spaces.empty()) {
                    spaces[q[1]].insert(0);
                    index_space[0] = q[1];

                    spaces[INT_MAX].insert(q[1]);
                    index_space[q[1]] = INT_MAX;

                    continue;
                }

                auto it = prev(index_space.lower_bound(q[1]));

                int h1, h2;
                h1 = q[1] - it->first;

                if (it->second == INT_MAX)
                    h2 = INT_MAX;
                else
                    h2 = it->first + it->second - q[1];

                spaces[it->second].erase(it->first);

                it->second = h1;
                index_space[q[1]] = h2;

                spaces[h1].insert(it->first);
                spaces[h2].insert(q[1]);
            }
            else {
                // Checking
                bool ok = true;

                if (q[2] > q[1]) {
                    ret.push_back(false);
                    continue;
                }

                for (auto it = spaces.rbegin(); it != spaces.rend(); it++) {
                    int free_dist = it->first;
                    auto& places = it->second;

                    if (free_dist < q[2]) {
                        ok = false;
                        break;
                    }

                    if (!places.empty() && *places.begin() + q[2] <= q[1]) {
                        break;
                    }
                }

                ret.push_back(ok);
            }
        }

        return ret;
    }
};