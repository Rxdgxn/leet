#include <stdlib.h>

int fcmp(const void *a, const void *b) {
    int *p1 = *(int**)a;
    int *p2 = *(int**)b;

    if (p1[0] < p2[0]) return -1;
    else if (p1[0] > p2[0]) return 1;

    return p2[1] - p1[1];
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), fcmp);

    int ret = 0;

    for (int i = 0; i < pointsSize; i++) {
        int y = INT_MIN;

        for (int j = i + 1; j < pointsSize; j++) {
            if (points[j][1] <= points[i][1] && points[j][1] > y) {
                ret++;
                y = points[j][1];
            }
        }
    }

    return ret;
}