#include "../include.h"

class Solution {
public:
    string lastSubstring(string s) {
        const int n = s.size();

        vector<int> max_subs(n);
        max_subs[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[max_subs[i + 1]]) {
                max_subs[i] = i;
            }
            else {
                bool skip = false;
                for (int j = 0; j < n - max_subs[i + 1] + 1 && i + j < max_subs[i + 1]; j++) {
                    if (s[i + j] < s[max_subs[i + 1] + j]) {
                        max_subs[i] = max_subs[i + 1];
                        skip = true;
                        break;
                    }
                    else if (s[i + j] > s[max_subs[i + 1] + j]) {
                        break;
                    }
                }

                if (!skip) {
                    max_subs[i] = i;
                }
            }
        }

        return s.substr(max_subs[0]);
    }
};