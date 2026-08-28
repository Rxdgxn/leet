#include "../include.h"

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int start = 0, end = 0;
        const int n = s.size();

        int ones = 0;

        while (end < n && ones < k) {
            ones += s[end] - '0';
            end++;
        }

        if (end == n && ones < k)
            return "";

        string current = s.substr(start, end);

        while (current[start] == '0') {
            start++;
        }

        int shortestLen = end - start;
        string shortest = current.substr(start, shortestLen);

        while (end < n) {
            if (ones == k) {
                ones--;
                start++;
            }

            while (s[start] == '0') {
                start++;
            }

            ones += s[end] - '0';
            end++;

            if (ones == k && end - start <= shortestLen) {
                current = s.substr(start, end - start);

                if (end - start < shortestLen || current < shortest) {
                    shortestLen = end - start;
                    shortest = current;
                }
            }
        }
        
        return shortest;
    }
};