#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ret = 0;

        vector<int> devices; // number of devices per row

        for (string& row : bank) {
            const int d = count(row.begin(), row.end(), '1');
            if (d) devices.push_back(d);
        }

        const int end = (int)(devices.size()) - 1;
        for (int i = 0; i < end; i++) ret += devices[i] * devices[i + 1];

        return ret;
    }
};