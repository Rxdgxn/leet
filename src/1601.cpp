#include "../include.h"

class Solution {
public:
    int ret = 0;

    void back(int n, int index, vector<vector<int>>& requests, vector<int>& in_degree, int count) {
        if (index == requests.size()) {
            for (int i = 0; i < n; i++)
                if (in_degree[i])
                    return;

            ret = max(ret, count);
            return;
        }

        in_degree[requests[index][0]]--;
        in_degree[requests[index][1]]++;

        back(n, index + 1, requests, in_degree, count + 1);

        in_degree[requests[index][0]]++;
        in_degree[requests[index][1]]--;

        back(n, index + 1, requests, in_degree, count);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> in_degree(n, 0);

        back(n, 0, requests, in_degree, 0);

        return ret;
    }
};