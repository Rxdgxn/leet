#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class DataStream {
public:
    int value, k, size, length;

    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        size = 0;
        length = 0;
    }
    
    bool consec(int num) {
        size++;

        if (value == num) {
            length++;

            if (size < k) return false;

            if (length >= k) return 1;

            return 0;
        }
        
        length = 0;

        return 0;
    }
};