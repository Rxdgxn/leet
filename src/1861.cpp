#include "../include.h"

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios::sync_with_stdio(false);
        cin.tie();

        const int m = box.size(), n = box[0].size();

        vector<vector<char>> transpose(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            auto& row = box[i];
            int last = 0, spaces = 0, stones = 0;

            for (int j = 0; j < n; j++) {
                if (row[j] == '*') {
                    for (int k = last; k < last + spaces; k++)
                        row[k] = '.';
                    for (int k = last + spaces; k < last + spaces + stones; k++)
                        row[k] = '#';

                    last = j + 1;
                    spaces = stones = 0;
                }
                else if (row[j] == '#') stones++;
                else spaces++;

                if (j == n - 1) {
                    for (int k = last; k < last + spaces; k++)
                        row[k] = '.';
                    for (int k = last + spaces; k < last + spaces + stones; k++)
                        row[k] = '#';
                }
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                transpose[j][i] = box[m - i - 1][j];

        return transpose;
    }
};