#include "../include.h"

class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> indexes; // value -> indexes of its appearences
    vector<int> list;

    RandomizedCollection() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        list.push_back(val);
        indexes[val].insert(list.size() - 1);

        return indexes[val].size() == 1;
    }
    
    bool remove(int val) {
        if (indexes[val].empty())
            return false;

        int remove_idx = *indexes[val].begin();
        indexes[val].erase(remove_idx);

        int last = list.back();
        list[remove_idx] = last;
        
        indexes[last].insert(remove_idx);
        indexes[last].erase(list.size() - 1);

        list.pop_back();

        return true;
    }
    
    int getRandom() {
        return list[rand() % list.size()];
    }
};