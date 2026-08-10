#include "../include.h"

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), greater<vector<int>>());

        unordered_map<int, int> distinct_categories;
        priority_queue<int, vector<int>, greater<int>> pq;

        long long ret = 0;
        long long profit = 0;

        for (int i = 0; i < k; i++) {
            int p = items[i][0];
            int c = items[i][1];

            distinct_categories[c]++;
            if (distinct_categories[c] > 1)
                pq.push(p);

            profit += p;
        }

        ret = profit + distinct_categories.size() * distinct_categories.size();

        for (int i = k; i < items.size(); i++) {
            if (pq.empty())
                break;

            if (distinct_categories.find(items[i][1]) == distinct_categories.end()) {
                int p = pq.top();
                pq.pop();

                profit -= p;
                profit += items[i][0];
                distinct_categories[items[i][1]]++;

                ret = max(ret, (long long)(profit + distinct_categories.size() * distinct_categories.size()));
            }
        }

        return ret;
    }
};