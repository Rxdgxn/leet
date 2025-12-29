#include "../include.h"

class SummaryRanges {
public:
    map<int, int> ranges; // x -> y for interval [x, y]

    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if (ranges.empty()) {
            ranges.insert(make_pair(value, value));
            return;
        }

        auto lb = ranges.lower_bound(value);

        if (lb == ranges.end()) {
            // new value is somewhere at the end of the map
            int x = ranges.rbegin()->first;
            int y = ranges.rbegin()->second;

            if (value <= y) {
                // value is already in an interval
                return;
            }
            if (value == y + 1) {
                // simply extend interval
                ranges[x] = value;
                return;
            }

            // otherwise, add new interval
            ranges.insert(make_pair(value, value));
            return;
        }

        const int x = lb->first, y = lb->second;

        if (x > value) {
            if (x == value + 1) {
                if (lb != ranges.begin() && prev(lb, 1)->second == value - 1) {
                    // merge [a, value - 1] x {value} x [value + 1, b]
                    ranges[prev(lb, 1)->first] = y;
                    ranges.erase(x);
                    return;
                }

                // merge {value} x [value + 1, b]
                ranges.insert(make_pair(value, y));
                ranges.erase(x);
                return;
            }

            // merge [a, value - 1] x {value}
            if (lb != ranges.begin() && prev(lb, 1)->second == value - 1) {
                ranges[prev(lb, 1)->first] = value;
                return;
            }
            if ((lb != ranges.begin() && prev(lb, 1)->second < value - 1) || lb == ranges.begin()) {
                ranges.insert(make_pair(value, value));
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;

        for (auto& [k, v] : ranges) {
            ret.push_back({k, v});
        }

        return ret;
    }
};