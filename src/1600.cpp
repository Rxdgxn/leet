#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> tree;
    unordered_map<string, bool> dead;
    string king;

    void dfs(string& root, vector<string>& order) {
        if (!dead[root])
            order.push_back(root);
        
        for (string& node : tree[root])
            dfs(node, order);
    }

    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        tree[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);

        return order;
    }
};