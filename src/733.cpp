#include "../include.h"

class Solution {
public:

    // Port of official Java solution

    void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor) {
        if (image[i][j] == color) {
            image[i][j] = newColor;
            if (i > 0) dfs(image, i - 1, j, color, newColor);
            if (j > 0) dfs(image, i , j - 1, color, newColor);
            if (i < image.size() - 1) dfs(image, i + 1, j, color, newColor);
            if (j < image[0].size() - 1) dfs(image, i, j + 1, color, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int c = image[sr][sc];
        if (c != newColor) dfs(image, sr, sc, c, newColor);
        return image;
    }
};