#include "../include.h"

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // Dummy solution

        ios::sync_with_stdio(false);
        cin.tie();

        vector<int> seats(n, 0);

        for (const auto& booking : bookings) {
            for (int i = booking[0]; i <= booking[1]; i++) {
                seats[i - 1] += booking[2];
            }
        }

        return seats;
    }
};