#include "../include.h"

class Solution {
public:
    typedef long long ll;
    typedef priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        const int n = servers.size(), m = tasks.size();
        vector<int> ret(m);

        PQ task_queue; // (time_when_free, server_id)
        PQ free_servers;
        
        for (int i = 0; i < n; i++)
            free_servers.push({servers[i], i});

        ll time = 0;

        for (int j = 0; j < m; j++) {
            time = max(time, (ll)j);

            while (!task_queue.empty() && task_queue.top().first <= time) {
                int s = task_queue.top().second;
                task_queue.pop();

                free_servers.push({servers[s], s});
            } 

            if (!free_servers.empty()) {
                auto [_, s] = free_servers.top();
                free_servers.pop();

                ret[j] = s;
                task_queue.push({time + tasks[j], s});

                continue;
            }

            auto [free_time, s] = task_queue.top();
            task_queue.pop();

            time = free_time;

            free_servers.push({servers[s], s});

            while (!task_queue.empty() && task_queue.top().first == free_time) {
                int s = task_queue.top().second;
                task_queue.pop();

                free_servers.push({servers[s], s});
            }

            s = free_servers.top().second;
            free_servers.pop();

            ret[j] = s;
            task_queue.push({time + tasks[j], s});
        }

        return ret;
    }
};