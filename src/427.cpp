#include "../include.h"

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
};

class Solution {
public:
    int n;

    Node* divide(vector<vector<int>>& grid, int r, int c, int matrix_size) {
        if (matrix_size == 1)
            return new Node(grid[r][c] == 1, true);

        int init_val = grid[r][c];
        bool is_leaf = true;

        for (int i = 0; i < matrix_size && is_leaf; i++)
            for (int j = 0; j < matrix_size; j++)
                if (grid[r + i][c + j] != init_val) {
                    is_leaf = false;
                    break;
                }

        if (is_leaf)
            return new Node(init_val == 1, true);

        Node *root = new Node();

        const int half = matrix_size / 2;

        root->topLeft = divide(grid, r, c, half);
        root->bottomLeft = divide(grid, r + half, c, half);
        root->topRight = divide(grid, r, c + half, half);
        root->bottomRight = divide(grid, r + half, c + half, half);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        n = grid.size();
        
        return divide(grid, 0, 0, n);
    }
};