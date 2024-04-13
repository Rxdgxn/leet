#include "../include.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        dirs.push_back("/");

        auto cstr = (char *)path.c_str();

        int level = 0;

        char *p = strtok(cstr, "/");
        while (p) {
            if (strcmp(p, "..") == 0) {
                if (level > 0) {
                    level--;
                    dirs.pop_back();
                }
            }
            else if (strcmp(p, ".") != 0) {
                level++;
                dirs.push_back(p);
            }

            p = strtok(NULL, "/");
        }

        if (level == 0) return dirs[0];

        string new_path;
        new_path += "/";

        for (int i = 1; i <= level; i++) {
            new_path += dirs[i];
            new_path += "/";
        }

        new_path.pop_back();

        return new_path;
    }
};