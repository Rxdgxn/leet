#include "../include.h"

class Solution {
public:
    unordered_map<char, int> letters;

    int pos = 0;

    void dfs(string curr, int n) {
        if (curr.size() == n) return;

        for (auto& [letter, occ] : letters) {
            if (occ > 0) {
                curr += letter;
                letters[letter]--;
                dfs(curr, n);

                pos++;

                curr.pop_back();
                letters[letter]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        for (char tile : tiles)
            letters[tile]++;

        dfs("", tiles.size());

        return pos;
    }
};