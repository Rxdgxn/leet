#include "include.h"

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> dups;
        vector<vector<string>> ret;

        for (string path : paths) {
            stringstream ss(path);
            string item, folder;
            ss >> item;
            folder = item;

            while (ss >> item) {
                int it = item.find('(');
                string key = item.substr(it, item.size() - it);
                string file = item.substr(0, it);
                dups[key].push_back(folder + "/" + file);
            }
        }

        for (auto it = dups.begin(); it != dups.end(); it++) {
            vector<string> tmp;
            for (auto s : it->second)
                if (dups[it->first].size() > 1)
                    tmp.push_back(s);
            if (tmp.size())
                ret.push_back(tmp);
        }

        return ret;
    }
};