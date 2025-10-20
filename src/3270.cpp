#include "../include.h"

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ret = "";
        int map[26] = {0};

        for (char c : s)
            map[c - 'a']++;

        const int n = s.size();

        int i = 0;
        while (i < n) {
            if (map[target[i] - 'a'] > 0) {
                ret += target[i];
                map[target[i] - 'a']--;
            }
            else {
                int j = target[i] - 'a' + 1;
                
                while (j < 26 && map[j] == 0)
                    j++;

                if (j < 26) {
                    ret += j + 'a';
                    map[j]--;

                    for (int k = 0; k < 26; k++)
                        for (int l = 0; l < map[k]; l++)
                            ret += k + 'a';

                    return ret;
                }

                // backtrack
                while (i > 0) {
                    i--;
                    map[ret.back() - 'a']++;
                    ret.pop_back();

                    int j = target[i] - 'a' + 1;
                    while (j < 26 && map[j] == 0)
                        j++;

                    if (j < 26) {
                        ret += j + 'a';
                        map[j]--;

                        for (int k = 0; k < 26; k++)
                            for (int l = 0; l < map[k]; l++)
                                ret += k + 'a';

                        return ret;
                    }
                }

                return "";
            }

            i++;
        }

        if (ret == target) {
            int i = n - 1;

            while (i > 0) {
                if (ret[i - 1] < ret[i]) {
                    int j = ret[i - 1] - 'a' + 1;

                    map[ret[i] - 'a']++;
                    map[ret[i - 1] - 'a']++;
                    ret.pop_back();
                    ret.pop_back();

                    while (j < 26 && map[j] == 0)
                        j++;

                    ret += j + 'a';
                    map[j]--;

                    for (int j = 0; j < 26; j++)
                        for (int k = 0; k < map[j]; k++)
                            ret += j + 'a';

                    return ret;
                }
                else {
                    map[ret[i] - 'a']++;
                    ret.pop_back();
                }

                i--;
            }
        }

        return "";
    }
};