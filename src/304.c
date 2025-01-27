#include <stdlib.h>

typedef struct {
    // m x n matrix
    int m, n;
    // dp 2d array
    int **innerSums;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix *mat = malloc(sizeof(NumMatrix));

    mat->m = matrixSize;
    mat->n = matrixColSize[0];

    int **innerSums = malloc(sizeof(int*) * matrixSize);

    for (int i = 0; i < matrixSize; i++)
        innerSums[i] = calloc(matrixColSize[0], sizeof(int));

    innerSums[0][0] = matrix[0][0];

    for (int i = 1; i < mat->n; i++)
        innerSums[0][i] = innerSums[0][i - 1] + matrix[0][i];

    for (int i = 1; i < mat->m; i++)
        innerSums[i][0] = innerSums[i - 1][0] + matrix[i][0];

    for (int i = 1; i < mat->m; i++)
        for (int j = 1; j < mat->n; j++)
            innerSums[i][j] = innerSums[i - 1][j] + innerSums[i][j - 1] + matrix[i][j] - innerSums[i - 1][j - 1];

    mat->innerSums = innerSums;

    return mat;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int s = obj->innerSums[row2][col2];
    
    if (row1 > 0) s -= obj->innerSums[row1 - 1][col2];
    if (col1 > 0) s -= obj->innerSums[row2][col1 - 1];
    if (row1 > 0 && col1 > 0) s += obj->innerSums[row1 - 1][col1 - 1];

    return s;
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->m; i++)
        free(obj->innerSums[i]);

    free(obj->innerSums);
}