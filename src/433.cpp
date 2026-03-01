#include "../include.h"

// for a big bank, a trie would be a better approach

class Solution {
public:
    #define GENE_LENGTH 8

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> used_genes;
        
        const int n = bank.size();

        queue<pair<int, string>> usable_genes;
        usable_genes.push({0, startGene});

        while (!usable_genes.empty()) {
            auto p = usable_genes.front();
            usable_genes.pop();
            int& mut = p.first;
            string& gene = p.second;

            used_genes.insert(gene);

            if (gene == endGene)
                return mut;

            for (int i = 0; i < n; i++) {
                string& curr_gene = bank[i];
                int diff = 0;

                for (int j = 0; j < GENE_LENGTH && diff < 2; j++) {
                    if (curr_gene[j] != gene[j]) {
                        diff++;
                    }
                }

                if (diff == 1 && used_genes.find(curr_gene) == used_genes.end()) {
                    usable_genes.push({mut + 1, curr_gene});
                }
            }
        }

        return -1;
    }
};