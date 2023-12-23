#include "../include.h"

class Solution {
public:
    bool marked[1000][1000];

    bool isPathCrossing(string path) {
        int i = 0, j = 0;
        path += '.';

        for (char c : path) {
            if (marked[500 + i][500 + j]) return true;

            marked[500 + i][500 + j] = 1;

            switch (c) {
                case 'N':
                    i--;
                    break;
                case 'S':
                    i++;
                    break;
                case 'W':
                    j--;
                    break;
                case 'E':
                    j++;
                    break;
                default: break;
            }
        }
        
        return false;
    }
};