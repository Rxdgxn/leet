#include "../include.h"

class Solution {
public:
    inline bool isVowel(const char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int start = 0, end = 0, consonants = 0;
        long long ss = 0;

        unordered_map<char, int> vowelCount;
        unordered_map<int, int> nextConsonant;

        const int n = word.size();

        int nextConsonantIndex = n;

        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;

            if (!isVowel(word[i]))
                nextConsonantIndex = i;
        }

        while (end < n) {
            const char& ch = word[end];

            if (isVowel(ch)) vowelCount[ch]++;
            else consonants++;

            while (consonants > k) {
                const char& sc = word[start];

                if (!isVowel(sc))
                    consonants--;
                else {
                    vowelCount[sc]--;

                    if (vowelCount[sc] == 0)
                        vowelCount.erase(sc);
                }

                start++;
            }

            while (vowelCount.size() == 5 && consonants == k) {
                ss += nextConsonant[end] - end;

                const char& sc = word[start];

                if (isVowel(sc)) {
                    vowelCount[sc]--;

                    if (vowelCount[sc] == 0)
                        vowelCount.erase(sc);
                }
                else consonants--;

                start++;
            }

            end++;
        }

        return ss;
    }
};