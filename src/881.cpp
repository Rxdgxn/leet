#include "../include.h"

class Solution {
public:
    #define sort_v(v) sort((v).begin(), (v).end())

    int numRescueBoats(vector<int>& people, int limit) {
        sort_v(people);
        int i = 0, j = people.size() - 1;
        int boats = 0;

        while (i <= j) {
            boats++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }

        return boats;
    }
};