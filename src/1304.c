int* sumZero(int n, int* returnSize) {
    int *ret = malloc(n * sizeof(int));

    for (int i = 0; i < n - 1; i++)
        ret[i] = i + 1;

    ret[n - 1] = -n * (n - 1) / 2;

    *returnSize = n;
    return ret;
}