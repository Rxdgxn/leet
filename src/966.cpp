#include "../include.h"

class Solution {
public:
    string lowercase(string s) {
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);

        return s;
    }
    
    string reduce(string s) {
        for (int i = 0; i < s.size(); i++)
            s[i] = (strchr("aeiou", s[i]) != NULL ? '*' : s[i]);

        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> capital, vowel;
        unordered_set<string> perfect;

        for (string& w : wordlist) {
            perfect.insert(w);

            string lc = lowercase(w);
            if (capital.find(lc) == capital.end())
                capital.insert({lc, w});

            string blob = reduce(lc);
            if (vowel.find(blob) == vowel.end())
                vowel.insert({blob, w});
        }

        vector<string> ret;

        for (string& q : queries) {
            string lc = lowercase(q);
            string blob = reduce(lc);

            if (perfect.find(q) != perfect.end())
                ret.push_back(q);
            else if (capital.find(lc) != capital.end())
                ret.push_back(capital[lc]);
            else if (vowel.find(blob) != vowel.end())
                ret.push_back(vowel[blob]);
            else ret.push_back("");
        }

        return ret;
    }
};