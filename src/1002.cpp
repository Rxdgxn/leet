#include "../include.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int map[26], n = words.size();

        for (int i = 0; i < 26; i++) {
            map[i] = INT_MAX;
        }

        for (string& word : words) {
            int tmp[26] = {0};

            for (char c : word) {
                tmp[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                map[i] = min(map[i], tmp[i]);
            }
        }

        vector<string> ret;

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < map[i]; j++) {
                char x = i + 'a';
                string s;
                s += x;

                ret.push_back(s);
            }

        return ret;
    }
};