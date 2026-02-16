#include "../include.h"

class Solution {
public:
    typedef long long Time;

    Time taskSchedulerII(vector<int>& tasks, int space) {
        Time curr_time = 1;
        unordered_map<int, Time> last;

        for (int t : tasks) {
            if (last.find(t) == last.end() || last[t] + space + 1 <= curr_time) {
                last[t] = curr_time;
                curr_time++;
            }
            else {
                curr_time = last[t] + space + 2;
                last[t] = curr_time - 1;
            }
        }

        return curr_time - 1;
    }
};