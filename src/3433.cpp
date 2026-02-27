#include "../include.h"

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [&](vector<string>& a, vector<string>& b) {
            const int ts1 = stoi(a[1]);
            const int ts2 = stoi(b[1]);

            if (ts1 < ts2)
                return true;

            if (ts2 < ts1)
                return false;

            // for equal timestamps, first handle offline events
            if (a[0][0] == 'O')
                return true;

            return false;
        });

        queue<pair<int, int>> offlineAt; // (timestamp, user)
        unordered_map<int, int> mentions;
        unordered_set<int> offlineUsers, onlineUsers;

        for (int uid = 0; uid < numberOfUsers; uid++)
            onlineUsers.insert(uid);

        for (auto& e : events) {
            const int ts = stoi(e[1]);

            // wake up users
            while (!offlineAt.empty()) {
                const auto& p = offlineAt.front();

                if (ts < p.first + 60)
                    break;

                const int uid = p.second;

                offlineUsers.erase(uid);
                onlineUsers.insert(uid);

                offlineAt.pop();
            }
            
            // check event type

            if (e[0][0] == 'O') {
                const int uid = stoi(e[2]);

                offlineAt.push({ts, uid});
                offlineUsers.insert(uid);
                onlineUsers.erase(uid);
            }
            else {
                if (e[2] == "HERE" || e[2] == "ALL") {
                    for (int uid : onlineUsers)
                        mentions[uid]++;

                    if (e[2] == "ALL")
                        for (int uid : offlineUsers)
                            mentions[uid]++;
                }
                else {
                    stringstream ss(e[2]);
                    string id;

                    while (getline(ss, id, ' ')) {
                        const int uid = stoi(id.substr(2));
                        mentions[uid]++;
                    }
                }
            }
        }

        vector<int> ret(numberOfUsers, 0);

        for (auto& [uid, m] : mentions)
            ret[uid] = m;

        return ret;
    }
};