#include <stdlib.h>
#include <string.h>

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char **ret = malloc(sizeof(char*));

    int i = 1;
    int map[26] = {0};

    *returnSize = 1;

    for (int i = 0; i < strlen(words[0]); i++)
        map[words[0][i] - 'a']++;

    ret[0] = words[0];

    while (i < wordsSize) {
        int temp_map[26] = {0};

        for (int j = 0; j < strlen(words[i]); j++)
            temp_map[words[i][j] - 'a']++;

        for (int j = 0; j < 26; j++) {
            if (temp_map[j] != map[j]) {
                // the word we reached is not an anagram, so we need to update the current anagram word map
                for (int k = 0; k < 26; k++)
                    map[k] = temp_map[k];

                ret = realloc(ret, ++(*returnSize) * sizeof(char*));
                ret[*returnSize - 1] = words[i];

                break;
            }
        }

        i++;
    }

    return ret;
}