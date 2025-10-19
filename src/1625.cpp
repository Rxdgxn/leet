#include "../include.h"

class Solution {
public:
    string findLexSmallestString(string str, int a, int b) {
        queue<string> q;
        set<string> s;

        s.insert(str);
        q.push(str);

        const int n = str.size();

        string min = str;

        while (!q.empty()) {
            string pos = q.front();
            q.pop();

            if (pos < min)
                min = pos;

            string rot = pos.substr(n - b);
            rot += pos.substr(0, n - b);

            for (int i = 1; i < n; i += 2)
                pos[i] = '0' + (pos[i] - '0' + a) % 10;

            if (s.find(rot) == s.end()) {
                s.insert(rot);
                q.push(rot);
            }
            if (s.find(pos) == s.end()) {
                s.insert(pos);
                q.push(pos);
            }
        }

        return min;
    }
};