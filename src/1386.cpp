#include "../include.h"

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> occupied;

        for (auto& seat : reservedSeats) {
            if (occupied.find(seat[0]) == occupied.end()) {
                occupied[seat[0]] = vector<bool>(11, false);
            }

            occupied[seat[0]][seat[1]] = true;
        }

        int groups = 0;

        // Ugliest method, i know
        for (auto& [_row, occupiedSeats] : occupied) {
            bool ok = true;
            for (int i = 2; i <= 5; i++) {
                if (occupiedSeats[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                groups++;
                occupiedSeats[2] = occupiedSeats[3] = occupiedSeats[4] = occupiedSeats[5] = true;
            }

            ok = true;
            for (int i = 4; i <= 7; i++) {
                if (occupiedSeats[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                groups++;
                occupiedSeats[4] = occupiedSeats[5] = occupiedSeats[6] = occupiedSeats[7] = true;
            }

            ok = true;
            for (int i = 6; i <= 9; i++) {
                if (occupiedSeats[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                groups++;
            }
        }

        groups += (n - occupied.size()) * 2;

        return groups;
    }
};