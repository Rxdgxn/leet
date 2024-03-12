#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return nullptr;
}();

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;

    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            pq.push(i);
    }
    
    int reserve() {
        int s = pq.top();
        pq.pop();

        return s;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};