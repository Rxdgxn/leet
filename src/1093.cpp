#include "../include.h"

class Solution {
public:
    vector<double> sampleStats(const vector<int>& count) {
        double mn = 256, mx = -1, mode, med;
        unsigned long long sum = 0;
        int cnt = 0, cnt_max = 0;
        vector<pair<int, pair<int, int>>> sample;

        for (int i = 0; i < 256; i++) {
            if (count[i]) {
                if (count[i] > cnt_max) {
                    cnt_max = count[i];
                    mode = i;
                }
                if (mn == 256) mn = i;
                mx = i;
                sum += (unsigned long long)(i) * (unsigned long long)(count[i]);
                sample.push_back(make_pair(i, make_pair(cnt, cnt + count[i] - 1)));
                cnt += count[i];
            }
        }

        int m = cnt / 2;

        for (int i = 0; i < sample.size(); i++) {
            auto it = sample[i];
            if (m >= it.second.first && m <= it.second.second) {
                if (cnt % 2) {
                    med = it.first;
                }
                else {
                    if (m == it.second.first) med = (it.first + sample[i-1].first) / 2.0;
                    else med = it.first;
                }
                break;
            }
        }

        return {mn, mx, (sum * 1.0) / cnt, med, mode};
    }
};

/*

12223333
1: 0 -> 0
2: 1 -> 3
3: 4 -> 7

*/