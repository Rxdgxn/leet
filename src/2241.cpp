#include "../include.h"

class ATM {
public:
    vector<long long> banknotes;

    ATM() {
        banknotes = vector<long long>(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            banknotes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ret(5, 0);
        int it = 4;
        int values[] = {20, 50, 100, 200, 500};
        auto prev = banknotes;

        while (amount && it >= 0) {
            if (amount < values[it]) {
                it--;
                continue;
            }
            const int q = min(banknotes[it], (long long)(amount / values[it]));
            banknotes[it] -= q;
            amount -= (q * values[it]);
            ret[it] = q;
            it--;
        }

        if (amount) {
            banknotes = prev;
            return {-1};
        }

        return ret;
    }
};