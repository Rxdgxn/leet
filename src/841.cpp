#include "../include.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> unlocked;
        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int k = q.front();
            q.pop();

            unlocked.insert(k);

            for (int new_key : rooms[k])
                if (unlocked.find(new_key) == unlocked.end())
                    q.push(new_key);
        }

        return unlocked.size() == rooms.size();
    }
};