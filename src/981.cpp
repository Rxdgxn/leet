#include "../include.h"

class TimeMap {
public:
    unordered_map<string, map<int, string>> timemap;

    TimeMap() {
        ios::sync_with_stdio(false);
        cin.tie();
        cout.tie();
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (timemap[key].begin() == timemap[key].end())
            return "";

        reverse_iterator<map<int, string>::iterator> it;
        for (it = timemap[key].rbegin(); it != timemap[key].rend() && it->first > timestamp; it++);
        
        if (it == timemap[key].rend())
            return "";
        
        return it->second;
    }
};