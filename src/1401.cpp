class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int to_x, to_y;

        if (xCenter < x1) to_x = x1;
        else if (xCenter > x2) to_x = x2;
        else to_x = xCenter;

        if (yCenter < y1) to_y = y1;
        else if (yCenter > y2) to_y = y2;
        else to_y = yCenter;

        return (xCenter - to_x) * (xCenter - to_x) + (yCenter - to_y) * (yCenter - to_y) <= radius * radius;
    }
};