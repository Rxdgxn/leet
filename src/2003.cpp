#include "../include.h"

class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> graph;
    set<int> st;

    void removeNodes(int node, vector<int>& nums) {
        visited.insert(node);
        st.erase(nums[node]);

        for (int child : graph[node])
            if (visited.find(child) == visited.end())
                removeNodes(child, nums);
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        const int n = parents.size();

        vector<int> ret(n, 1);

        for (int i = 1; i <= 1e5 + 1; i++)
            st.insert(i);

        int node = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                node = i;

            graph[parents[i]].push_back(i);
        }

        if (node < 0)
            return ret;

        while (node != -1) {
            removeNodes(node, nums);
            ret[node] = *st.begin();
            node = parents[node];
        }
        
        return ret;
    }
};