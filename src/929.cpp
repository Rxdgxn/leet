#include "include.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, bool> mp;

        for (string email : emails) {
            string curr;
            int len = 0, plus = 0;

            for (char ch : email) {
                if (ch == '@') break;
                if (ch == '+') plus = 1;

                if (ch != '.' && !plus) curr += ch;

                len++;
            }

            curr += email.substr(len, email.size() - len);
            mp[curr] = 1;
        }

        return mp.size();
    }
};