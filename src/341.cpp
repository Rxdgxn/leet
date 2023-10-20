#include "../include.h"

class NestedInteger {
public:
    bool isInteger() const;

    int getInteger() const;

    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> flattened;
    int it = 0, size;

    void aux(const vector<NestedInteger>& list) {
        for (auto i : list) {
            if (i.isInteger()) flattened.push_back(i.getInteger());
            else aux(i.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        aux(nestedList);
        size = flattened.size();
    }
    
    int next() {
        return flattened[it++];
    }
    
    bool hasNext() {
        return it < size;
    }
};