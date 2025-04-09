#include "../include.h"

struct Node {
    int index;
    vector<Node*> children;
};

class WordFilter {
public:
    vector<Node*> trie;

    WordFilter(vector<string>& words) {
        int index = 0;

        trie = vector<Node*>(27, NULL);

        for (auto& word : words) {
            string w = '{' + word;

            if (trie[w[0] - 'a'] == NULL) {
                trie[w[0] - 'a'] = new Node;
                trie[w[0] - 'a']->children = vector<Node*>(27, NULL);
            }

            trie[w[0] - 'a']->index = index;
            auto it = trie[w[0] - 'a'];

            for (int i = 1; i < w.size(); i++) {
                if (it->children[w[i] - 'a'] == NULL) {
                    it->children[w[i] - 'a'] = new Node;
                    it->children[w[i] - 'a']->children = vector<Node*>(27, NULL);
                }

                it->children[w[i] - 'a']->index = index;
                it = it->children[w[i] - 'a'];
            }

            for (int j = word.size() - 1; j >= 0; j--) {
                w = word[j] + w;

                if (trie[w[0] - 'a'] == NULL) {
                    trie[w[0] - 'a'] = new Node;
                    trie[w[0] - 'a']->children = vector<Node*>(27, NULL);
                }

                trie[w[0] - 'a']->index = index;
                auto it = trie[w[0] - 'a'];

                for (int i = 1; i < w.size(); i++) {
                    if (it->children[w[i] - 'a'] == NULL) {
                        it->children[w[i] - 'a'] = new Node;
                        it->children[w[i] - 'a']->children = vector<Node*>(27, NULL);
                    }

                    it->children[w[i] - 'a']->index = index;
                    it = it->children[w[i] - 'a'];
                }

            }

            index++;
        }
    }
    
    int f(string pref, string suff) {
        string search = suff + '{' + pref;

        auto it = trie[search[0] - 'a'];

        if (it == NULL)
            return -1;

        for (int i = 1; i < search.size(); i++) {
            it = it->children[search[i] - 'a'];

            if (it == NULL)
                return -1;
        }

        return it->index;
    }
};