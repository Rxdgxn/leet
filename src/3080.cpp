#include "../include.h"

class Compare {
public:
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        if (a.first > b.first) {
            return true;
        }
        else if (a.first == b.first && a.second > b.second) {
            return true;
        }

        return false;
    }
};

class Solution {
public:
    typedef long long ll;

    vector<ll> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size(), m = queries.size();

        vector<ll> ret(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        ll sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pq.push({nums[i], i});
        }

        for (int i = 0; i < m; i++) {
            sum -= nums[queries[i][0]];
            nums[queries[i][0]] = 0;

            int k = queries[i][1];

            while (!pq.empty() && k--) {
                auto p = pq.top();
                int quot = 1;

                if (nums[p.second] == 0) {
                    k++;
                    quot = 0;
                }

                sum -= p.first * quot;
                nums[p.second] = 0;

                pq.pop();
            }

            ret[i] = sum;
        }

        return ret;
    }
};