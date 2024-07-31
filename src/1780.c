bool checkPowersOfThree(int n) {
    while (n) {
        int r = n % 3;
        n /= 3;

        if (r == 2) return 0;
    }

    return 1;
}