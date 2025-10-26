#include "../include.h"

class Bank {
public:
    int n = 0;
    vector<long long> balance;

    Bank(vector<long long>& balance) {
        this->n = balance.size();
        this->balance = balance;
    }

    inline bool isValid(int account) {
        return 0 <= account && account < this->n;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;

        if (!isValid(account1) || !isValid(account2))
            return false;

        if (this->balance[account1] < money)
            return false;

        this->balance[account1] -= money;
        this->balance[account2] += money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        account--;

        if (!isValid(account))
            return false;

        this->balance[account] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        account--;

        if (!isValid(account) || this->balance[account] < money)
            return false;

        this->balance[account] -= money;

        return true;
    }
};