int numEquivDominoPairs(int** dominoes, int n, int* _) {
    int map[100] = {0};
    int equ = 0;

    for (int i = 0; i < n; i++) {
        int a = dominoes[i][0], b = dominoes[i][1];
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }

        equ += map[a * 10 + b];
        map[a * 10 + b]++;
    }

    return equ;
}