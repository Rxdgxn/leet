#include "../include.h"

class NumberContainers {
public:
    unordered_map<int, int> values; // (index, number)
    unordered_map<int, set<int>> indices;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (values.count(index)) {
            indices[values[index]].erase(index);
        }

        values[index] = number;
        indices[number].insert(index);
    }
    
    int find(int number) {
        if (indices[number].empty())
            return -1;

        return *(indices[number].begin());
    }
};