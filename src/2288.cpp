#include "../include.h"

// Technically it's not a valid solution since it fails with "Memory limit exceeded", but this ONLY happens when it's submitted,
// and not when the SAME testcases are verified via the "Run" button. Could simply be a problem for C++...
class Solution {
public:
    string ret;

    string discountPrices(string sentence, int discount) {
        auto p = strtok((char* )sentence.c_str(), " ");
        string word;

        while (p != NULL) {
            word = p;

            if (word[0] == '$') {
                double price = 0; // $0 shouldn't be a thing

                for (int i = 1; i < word.size(); i++) {
                    if (word[i] >= '0' && word[i] <= '9') price = price * 10 + (word[i] - '0');
                    else {
                        price = 0;
                        break;
                    }
                }

                if (price && discount) {
                    price -= (discount * price / 100.0);
                    long p = round(price * 100);
                    ret = ret + "$" + to_string(p / 100) + "." + (p % 100 < 10 && p % 100 != 0 ? "0" : "") + to_string(p % 100) + (p % 100 == 0 ? "0" : "");
                }
                else ret += word + (price ? ".00" : "");
            }
            else ret += word;

            ret += ' ';
            p = strtok(NULL, " ");
        }

        return ret.substr(0, ret.size() - 1);
    }
};