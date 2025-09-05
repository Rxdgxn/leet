int makeTheIntegerZero(int num1, int num2) {
    int k = 1;

    while (1) {
        long long x = num1 - (long long) num2 * k;

        if (k > x)
            return -1;

        int bits = 0;

        while (x) {
            bits += (x & 1);
            x >>= 1;
        }

        if (k >= bits)
            return k;

        k++;
    }

    return -1;
}