#include "../include.h"

class Solution {
public:
    int topo_sort(queue<int>& q, unordered_map<int, int>& in_deg, unordered_map<int, unordered_set<int>>& graph, vector<int>& topo) {
        int ordered_items = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            topo.push_back(x);
            ordered_items++;

            for (int neigh : graph[x]) {
                in_deg[neigh]--;

                if (in_deg[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return ordered_items;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, unordered_set<int>> components, graph; // graph per component, graph of all components
        unordered_map<int, int> in_deg_groups, in_deg_component; // in deg for components, in deg for nodes

        int single_comp_id = m; // each node who is not in a group becomes its own component

        unordered_set<int> used_comp_ids;
        unordered_map<int, vector<int>> mapping; // each group/component id to nodes

        for (int i = 0; i < n; i++) {
            if (group[i] < 0) {
                group[i] = single_comp_id++;
            }

            used_comp_ids.insert(group[i]);
            mapping[group[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j : beforeItems[i]) {
                int c1 = group[j], c2 = group[i]; // c1 -> c2

                if (c1 != c2) {
                    // Different components
                    if (graph[c1].find(c2) == graph[c1].end()) {
                        graph[c1].insert(c2);
                        in_deg_groups[c2]++;
                    }
                }
                else {
                    // Same components
                    components[j].insert(i);
                    in_deg_component[i]++;
                }
            }
        }

        queue<int> q;

        for (int comp_id : used_comp_ids) {
            if (in_deg_groups[comp_id] == 0) {
                q.push(comp_id);
            }
        }

        vector<int> comp_topo;
        topo_sort(q, in_deg_groups, graph, comp_topo);

        if (comp_topo.size() != used_comp_ids.size()) {
            return {}; // can't order
        }

        vector<int> final_topo;

        for (int comp_id : comp_topo) {
            queue<int> nq;

            for (int node : mapping[comp_id]) {
                if (in_deg_component[node] == 0) {
                    nq.push(node);
                }
            }

            int ordered = topo_sort(nq, in_deg_component, components, final_topo);

            if (ordered != mapping[comp_id].size()) {
                return {}; // can't order
            }
        }

        return final_topo;
    }
};