int captureForts(int* forts, int n) {
    int last_own = -1, captured = 0;
    
    for (int i = 0; i < n; i++) {
        if (forts[i] == -1) {
            if (last_own >= 0) {
                int c = i - last_own - 1;
                captured = (captured < c ? c : captured);
                last_own = -1;
            }
        }
        else if (forts[i] == 1) {
            last_own = i;
        }
    }

    last_own = -1;

    for (int i = n - 1; i >= 0; i--) {
        if (forts[i] == -1) {
            if (last_own >= 0) {
                int c = last_own - i - 1;
                captured = (captured < c ? c : captured);
                last_own = -1;
            }
        }
        else if (forts[i] == 1) {
            last_own = i;
        }
    }

    return captured;
}