#include "../include.h"

class AllOne {
public:
    unordered_map<string, int> count;
    map<int, unordered_set<string>> keys;

    AllOne() {
        
    }
    
    void inc(string key) {
        if (keys.find(count[key]) != keys.end()) {
            keys[count[key]].erase(key);

            if (keys[count[key]].empty())
                keys.erase(count[key]);
        }
        
        count[key]++;
        keys[count[key]].insert(key);
    }
    
    void dec(string key) {
        if (keys.find(count[key]) != keys.end()) {
            keys[count[key]].erase(key);

            if (keys[count[key]].empty())
                keys.erase(count[key]);
        }

        count[key]--;

        if (count[key] == 0)
            count.erase(key);
        else
            keys[count[key]].insert(key);
    }
    
    string getMaxKey() {
        if (count.empty())
            return "";

        return *keys.rbegin()->second.begin();
    }
    
    string getMinKey() {
        if (count.empty())
            return "";

        return *keys.begin()->second.begin();
    }
};