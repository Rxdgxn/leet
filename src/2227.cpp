#include "../include.h"

struct Node {
    bool is_word;
    Node *children[26];
};

Node* new_node() {
    Node *n = new Node;

    n->is_word = false;
    
    for (int i = 0; i < 26; i++)
        n->children[i] = NULL;

    return n;
}

// Or just keep a map of encrypted dict words
class Encrypter {
public:
    unordered_map<char, string> key_to_val;
    unordered_map<string, vector<char>> string_to_chars;
    Node *dict_root = new_node();
    Node *decrypt_it = NULL;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); i++) {
            key_to_val[keys[i]] = values[i];
            string_to_chars[values[i]].push_back(keys[i]);
        }

        for (string& s : dictionary) {
            Node *it = dict_root;
            
            for (char c : s) {
                if (it->children[c - 'a'] == NULL)
                    it->children[c - 'a'] = new_node();

                it = it->children[c - 'a'];
            }

            it->is_word = true;
        }
    }
    
    string encrypt(string word1) {
        string ret;

        for (char c : word1)
            if (key_to_val.find(c) == key_to_val.end())
                return "";
            else
                ret += key_to_val[c];

        return ret;
    }

    void helper(int& total, string& s, int start) {
        if (start == s.size()) {
            if (decrypt_it->is_word)
                total++;

            return;
        }

        for (char ch : string_to_chars[s.substr(start, 2)]) {
            if (decrypt_it->children[ch - 'a'] == NULL)
                continue;

            Node *saved = decrypt_it;
            decrypt_it = decrypt_it->children[ch - 'a'];
            helper(total, s, start + 2);
            decrypt_it = saved;
        }
    }
    
    int decrypt(string word2) {
        int ret = 0;

        decrypt_it = dict_root;
        helper(ret, word2, 0);

        return ret;
    }
};