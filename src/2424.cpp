#include "../include.h"

class LUPrefix {
public:

    int mp[100001] = {0}, len, pre = 0;

    LUPrefix(int n) {
        len = n;
    }

    void upload(int video) {
        mp[video] = 1;
    }

    int longest() {
        for (int i = pre + 1; i <= len; i++) {
            if (mp[i]) pre++;
            else break;
        }

        return pre;
    }
};