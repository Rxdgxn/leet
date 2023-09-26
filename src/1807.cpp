#include "../include.h"

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kw;
        for (auto k : knowledge) {
            kw[k[0]] = k[1];
        }

        string ret, key;
        bool in_key = false;

        for (char ch : s) {
            if (ch == '(') {
                in_key = true;
            }
            else if (ch == ')') {
                const string val = kw[key];
                ret += (!val.empty() ? val : "?");

                key = "";
                in_key = false;
            }
            else {
                if (in_key) key += ch;
                else ret += ch;
            } 
        }

        return ret;
    }
};