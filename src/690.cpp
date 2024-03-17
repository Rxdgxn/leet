#include "../include.h"

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int>>> mp;

        for (auto& e : employees) {
            mp[e->id] = {e->importance, e->subordinates};
        }
        
        queue<int> q;
        int sum = 0;

        q.push(id);

        while (!q.empty()) {
            const int i = q.front();
            sum += mp[i].first;
            q.pop();

            for (int x : mp[i].second) {
                q.push(x);
            }
        }

        return sum;
    }
};