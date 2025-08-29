long long flowerGame(int N, int M) {
    long long m = M;
    long long n = N;
    long long w = (m / 2 + m % 2) * (n / 2);
    long long z = (n / 2 + n % 2) * (m / 2);

    return w + z;
}