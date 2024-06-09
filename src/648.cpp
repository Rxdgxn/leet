#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ret;

        sort(dictionary.begin(), dictionary.end());

        auto s = (char*) sentence.c_str();

        char *p = strtok(s, " ");
        while (p) {
            bool root = false;

            for (string& word : dictionary) {
                auto w = (char*) word.c_str();

                if (strstr(p, w) == p) {
                    ret += w;
                    ret += ' ';
                    root = true;
                    break;
                }
            }

            if (!root) {
                ret += p;
                ret += ' ';
            }

            p = strtok(NULL, " ");
        }

        ret.pop_back();

        return ret;
    }
};