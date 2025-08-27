#include "../include.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        set<int> biggest_freq;
        unordered_map<int, priority_queue<string, vector<string>, greater<string>>> freq_to_word;
        vector<string> ret;

        for (string& w : words)
            freq[w]++;

        for (auto& [k, v] : freq) {
            biggest_freq.insert(v);
            freq_to_word[v].push(k);
        }

        for (auto it = biggest_freq.rbegin(); it != biggest_freq.rend(); it++) {
            if (k == 0) break;

            while (k > 0 && !freq_to_word[*it].empty()) {
                ret.push_back(freq_to_word[*it].top());
                freq_to_word[*it].pop();
                k--;
            }
        }

        return ret;
    }
};