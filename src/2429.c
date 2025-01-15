int minimizeXor(int num1, int num2) {
    int set_bits = 0;

    while (num2) {
        set_bits += (num2 & 1);
        num2 >>= 1;
    }

    char bits1[31] = {0}, bits_x[31] = {0};

    int it = 0;
    while (num1) {
        bits1[it++] = num1 & 1;
        num1 >>= 1;
    }

    for (int i = 30; i >= 0; i--) {
        if (bits1[i] == 0 || set_bits == 0) {
            bits_x[i] = 0;
            continue;
        }

        bits_x[i] = 1;
        set_bits--;
    }

    if (set_bits != 0) {
        for (int i = 0; i < 31 && set_bits != 0; i++)
            if (bits_x[i] == 0) {
                bits_x[i] = 1;
                set_bits--;
            }
    }

    int x = 0;
    for (int i = 0; i < 31; i++)
        x += bits_x[i] * (1 << i);

    return x;
}