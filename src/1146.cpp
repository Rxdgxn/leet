#include "../include.h"

class SnapshotArray {
public:
    int id;
    vector<vector<pair<int, int>>> records;

    SnapshotArray(int length) {
        id = 0;
        records.resize(length);
        for (int i = 0; i < length; ++i) {
            records[i].push_back(make_pair(id, 0));
        }
    }
    
    void set(int index, int val) {
        records[index].push_back(make_pair(id, val));
    }
    
    int snap() {
        return id++;
    }
    
    // Stolen from leetcode
    int get(int index, int snap_id) {
        auto it = upper_bound(records[index].begin(), records[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};