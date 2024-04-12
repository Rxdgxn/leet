#include "../include.h"

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge;

        int p1 = 0, p2 = 0, n1 = word1.size(), n2 = word2.size();

        while (p1 < n1 && p2 < n2) {
            if (word1[p1] > word2[p2]) merge += word1[p1++];
            else if (word1[p1] < word2[p2]) merge += word2[p2++];
            else {
                int k1 = p1, k2 = p2;
                while (k1 < n1 && k2 < n2 && word1[k1] == word2[k2]) {
                    k1++;
                    k2++;
                }
                
                if (k1 == n1 || word1[k1] < word2[k2]) {
                    merge += word2[p2++];
                    continue;
                }
                
                if (k2 == n2 || word2[k2] < word1[k1]) {
                    merge += word1[p1++];
                    continue;
                }
            }
        }

        while (p1 < n1) {
            merge += word1[p1++];
        }
        while (p2 < n2) {
            merge += word2[p2++];
        }

        return merge;
    }
};