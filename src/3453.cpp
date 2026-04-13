#include "../include.h"

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l = 0, h = 2 * 1e9 + 1;
        double y_min;

        sort(squares.begin(), squares.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        const int n = squares.size();
        double total_area = 0;

        for (int i = 0; i < n; i++)
            total_area += (long long)squares[i][2] * squares[i][2];

        while (l + 0.00001 < h) {
            double y = l + (h - l) / 2;
            double lower_area = 0;

            for (int i = 0; i < n; i++) {
                if (squares[i][1] > y)
                    break;

                lower_area += squares[i][2] * (min(y, (double)squares[i][1] + squares[i][2]) - squares[i][1]);
            }

            double upper_area = total_area - lower_area;

            if (upper_area > lower_area) {
                l = y;
            }
            else {
                h = y;
                y_min = y;
            }
        }

        return y_min;
    }
};