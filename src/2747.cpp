#include "../include.h"

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        const int sz = queries.size();

        vector<pair<int, int>> marked;
        for (int i = 0; i < sz; i++)
            marked.push_back({queries[i], i});

        sort(marked.begin(), marked.end());

        vector<int> ret(sz);
        unordered_map<int, int> servers;
        int it = 0, jt = 0;
        int used = 0;

        for (int i = 0; i < sz; i++) {
            while (it < logs.size() && logs[it][1] < marked[i].first - x) {
                servers[logs[it][0]]--;

                if (servers[logs[it][0]] == 0)
                    used--;

                it++;
            }

            while (jt < logs.size() && logs[jt][1] <= marked[i].first) {
                if (servers[logs[jt][0]] == 0)
                    used++;

                servers[logs[jt][0]]++;

                jt++;
            }
            
            ret[marked[i].second] = n - used;
        }

        return ret;
    }
};