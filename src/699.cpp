#include "../include.h"

class Solution {
public:
    struct Square {
        int x1, x2;
        int y_top;
    };

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<Square> squares;
        int max_height = 0;
        vector<int> ret;

        for (auto& p : positions) {
            int y = 0;

            for (int i = 0; i < squares.size(); i++) {
                if (!(p[0] >= squares[i].x2 || p[0] + p[1] <= squares[i].x1)) {
                    y = max(y, squares[i].y_top);
                }
            }

            squares.push_back({p[0], p[0] + p[1], y + p[1]});
            max_height = max(max_height, y + p[1]);

            ret.push_back(max_height);
        }

        return ret;
    }
};