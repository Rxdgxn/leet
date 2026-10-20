#include "../include.h"

// Apparently the diagonals part could've been simplified
class Solution {
private:
    unordered_map<uint32_t, int> col, row;
    unordered_map<uint64_t, int> main_diag, sec_diag;
    unordered_set<uint64_t> active;

    void turn_off_lamps(uint64_t c, int n) {
        int x = c >> 32;
        int y = c & UINT_MAX;

        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && j >= 0 && i < n && j < n) {
                    auto c = make_coordinate(i, j);

                    if (active.find(c) == active.end()) {
                        continue;
                    }

                    active.erase(c);

                    row[i]--;
                    col[j]--;

                    auto pm = project_main(i, j);
                    main_diag[pm]--;

                    auto ps = project_secondary(i, j, n);
                    sec_diag[ps]--;
                }
            }
        }
    }

    inline uint64_t make_coordinate(uint32_t x, uint32_t y) {
        uint64_t ret = x;
        ret <<= 32;
        ret |= y;

        return ret;
    }

    inline uint64_t project_main(int x, int y) {
        return make_coordinate(max(0, x - y), max(0, y - x));
    }

    inline uint64_t project_secondary(int x, int y, int n) {
        return make_coordinate(max(0, x - (n - 1 - y)), min(n - 1, y + x));
    }

public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        for (auto& l : lamps) {
            int x = l[0], y = l[1];
            auto c = make_coordinate(x, y);
            
            if (active.find(c) != active.end()) {
                continue;
            }

            active.insert(c);

            row[x]++;
            col[y]++;
            
            auto pm = project_main(x, y);
            main_diag[pm]++;

            auto ps = project_secondary(x, y, n);
            sec_diag[ps]++;
        }

        vector<int> ret;
        ret.reserve(queries.size());

        for (auto& q : queries) {
            uint32_t x = q[0], y = q[1];
            auto c = make_coordinate(x, y);

            auto pm = project_main(x, y);
            auto ps = project_secondary(x, y, n);

            if (active.find(c) != active.end() || row[x] > 0 || col[y] > 0 || main_diag[pm] > 0 || sec_diag[ps] > 0) {
                ret.push_back(1);
            }
            else {
                ret.push_back(0);
            }
            
            turn_off_lamps(c, n);
        }

        return ret;
    }
};