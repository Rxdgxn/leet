#include "../include.h"

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15000, celsius * 1.80000 + 32.00000};
    }
};