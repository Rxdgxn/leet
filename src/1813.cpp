#include "../include.h"

class Solution {
public:
    vector<string> v1, v2;

    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() < sentence2.size()) swap(sentence1, sentence2);

        auto s1 = (char*) sentence1.c_str(), s2 = (char*) sentence2.c_str();
        
        char *p = strtok(s2, " ");
        while (p) {
            v2.push_back(p);
            p = strtok(NULL, " ");
        }

        p = strtok(s1, " ");
        while (p) {
            v1.push_back(p);
            p = strtok(NULL, " ");
        }

        
        int s = 0, i = v1.size() - 1, j = v2.size() - 1;

        while (s < v2.size() && v2[s] == v1[s]) s++;

        while (j >= 0 && v2[j] == v1[i]) {
            i--;
            j--;
        }

        return j < s;
    }
};