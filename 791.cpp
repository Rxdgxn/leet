#include "include.h"
using namespace std;

class Solution {
public:

    int map['z' + 1];
    string customSortString(string order, string s) {
        for (int i = 0; i < order.size(); i++) map[order[i]] = order.size() - i;
        for (int i = 0; i < s.size() - 1; i++)
            for (int j = i + 1; j < s.size(); j++)
                if (map[s[i]] < map[s[j]]) swap(s[i], s[j]);
        return s;
    }

};

int main() {

    Solution sol;
    cout << sol.customSortString("cbafg", "abcd");

    return 0;
}