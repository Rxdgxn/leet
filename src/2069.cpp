#include "../include.h"

class Robot {
public:
    int x, y, dir;
    int width, height;
    string dirs[4] = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        this->width = width;
        this->height = height;

        x = y = 0;
        dir = 0;
    }

    int brute_step(int num) {
        int take;

        if (dirs[dir] == "East") {
            take = min(num, width - 1 - x);
            x += take;
        }
        else if (dirs[dir] == "West") {
            take = min(num, x);
            x -= take;
        }
        else if (dirs[dir] == "North") {
            take = min(num, height - 1 - y);
            y += take;
        }
        else {
            take = min(num, y);
            y -= take;
        }

        num -= take;

        if (num > 0)
            dir = (dir + 1) % 4;

        return num; // remaining
    }
    
    void step(int num) {
        int perimeter = 2 * (width + height - 2);

        int rem = num % perimeter;

        if (rem == 0 && x == 0 && y == 0 && dir == 0)
            dir = 3;

        while (rem > 0)
            rem = brute_step(rem);
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};