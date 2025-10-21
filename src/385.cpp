#include "../include.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger dfs(string& s, int& i) {
        NestedInteger ret = NestedInteger();
        int value = INT_MIN, sign = 1;

        while (i < s.size()) {
            if (s[i] == '[') {
                auto join = dfs(s, ++i);
                ret.add(join);
            }
            else if (s[i] == ']') {
                if (value != INT_MIN) {
                    ret.add(NestedInteger(value * sign));
                }

                return ret;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == ',') {
                if (value != INT_MIN) {
                    ret.add(NestedInteger(value * sign));
                    sign = 1;
                    value = INT_MIN;
                }
            }
            else {
                if (value == INT_MIN) {
                    value = s[i] - '0';
                }
                else {
                    value = value * 10 + s[i] - '0';
                }
            }

            i++;
        }

        if (value != INT_MIN) {
            ret.setInteger(value * sign);
        }

        return ret;
    }

    NestedInteger deserialize(string s) {
        // facem dfs() de fiecare data cand dam de un [
        // cand dam de un ], returnam ni curent

        int i = 0;
        auto root = dfs(s, i);

        if (root.isInteger())
            return root;

        return root.getList()[0];
    }
};