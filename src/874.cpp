#include "../include.h"

class Solution {
public:
    enum Direction {
        North,
        East,
        South,
        West
    };

    inline void change(Direction& dir, int c) {
        if (c == -2) {
            switch (dir)
            {
            case North:
                dir = West;
                break;
            case West:
                dir = South;
                break;
            case South:
                dir = East;
                break;
            case East:
                dir = North;
                break;
            default:
                break;
            }

            return;
        }

        switch (dir)
        {
        case North:
            dir = East;
            break;
        case East:
            dir = South;
            break;
        case South:
            dir = West;
            break;
        case West:
            dir = North;
            break;
        default:
            break;
        }
    }

    inline void update(int& x, int& y, Direction& dir) {
        switch (dir)
        {
        case North:
            y++;
            break;
        case West:
            x--;
            break;
        case South:
            y--;
            break;
        case East:
            x++;
            break;
        default:
            break;
        }
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, PairHash> blocked;

        for (auto& o : obstacles) {
            blocked.insert({o[0], o[1]});
        }

        int x = 0, y = 0;
        Direction dir = North;

        int max_dist = 0;

        for (int& c : commands) {
            if (c < 0) {
                change(dir, c);
                continue;
            }

            for (int i = 0; i < c; i++) {
                int prevx = x, prevy = y;
                update(x, y, dir);

                if (blocked.find({x, y}) != blocked.end()) {
                    x = prevx;
                    y = prevy;
                    break;
                }

                max_dist = max(max_dist, x * x + y * y);
            }
        }

        return max_dist;
    }

private:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return p.first ^ p.second;
        }
    };
};