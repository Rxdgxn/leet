long long calc(int* time, int timeSize, long long mid) {
    long long t = 0;

    for (int i = 0; i < timeSize; i++)
        t += (mid / time[i]);

    return t;
}

long long minimumTime(int* time, int timeSize, int totalTrips) {
    long long low = 1, high = 1e14;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (calc(time, timeSize, mid) >= totalTrips)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}