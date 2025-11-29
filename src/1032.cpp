#include "../include.h"

struct TrieNode {
    TrieNode* children[26] = {0};
    bool is_word = 0;
};

class StreamChecker {
public:
    TrieNode *root;
    vector<char> stream;

    StreamChecker(vector<string>& words) {
        root = new TrieNode;

        for (string& w : words) {
            TrieNode *it = root;

            for (int i = w.size() - 1; i >= 0; i--) {
                if (it->children[w[i] - 'a'] == NULL) {
                    it->children[w[i] - 'a'] = new TrieNode;
                }

                it = it->children[w[i] - 'a'];

                if (i == 0) {
                    it->is_word = 1;
                }
            }
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);

        TrieNode *it = root;

        for (int i = stream.size() - 1; i >= 0; i--) {
            if (it->children[stream[i] - 'a'] == NULL)
                return false;

            it = it->children[stream[i] - 'a'];

            if (it->is_word)
                return true;
        }

        return false;
    }
};