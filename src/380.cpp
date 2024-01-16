#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class RandomizedSet {
public:
    int size = 0;
    vector<int> set;
    unordered_map<int, int> mp;

    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (mp.count(val)) return 0;

        mp[val] = size++;
        set.push_back(val);

        return 1;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) return 0;
        
        int tmp = set[size - 1];
        swap(set[mp[val]], set[size - 1]);
        mp[tmp] = mp[val];
        
        mp.erase(val);
        set.pop_back();
        size--;

        return 1;
    }
    
    int getRandom() {
        return set[rand() % size];
    }
};