#include "../include.h"

class Router {
public:
    typedef long long Packet;    

    int capacity;
    queue<Packet> router;
    unordered_map<Packet, bool> unique_packets;
    unordered_map<int, vector<int>> destinations;

    Router(int memoryLimit) {
        capacity = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet p = (static_cast<long long>(source) << 48) | (static_cast<long long>(destination) << 32) | timestamp;

        if (unique_packets.find(p) != unique_packets.end())
            return false;

        if (router.size() == capacity)
            forwardPacket();

        unique_packets[p] = true;
        router.push(p);
        destinations[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (router.empty())
            return {};

        Packet p = router.front();
        router.pop();
        unique_packets.erase(p);

        int s = (p >> 48) & 0xFFFF;
        int d = (p >> 32) & 0xFFFF;
        int t = p & 0xFFFFFFFF;

        // forwarding a packet always deletes the first timestamp of the vector, which is also the smallest, because of FIFO and the problem statement
        destinations[d].erase(destinations[d].begin());

        return { s, d, t };
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& vect = destinations[destination];

        if (vect.empty())
            return 0;

        int st = 0, dr = vect.size() - 1;
        int lb, ub;

        while (st <= dr) {
            lb = (st + dr) / 2;

            if (vect[lb] >= startTime) {
                dr = lb - 1;
            }
            else {
                st = lb + 1;
            }
        }

        if (vect[lb] < startTime) lb++;

        st = 0, dr = vect.size() - 1;

        while (st <= dr) {
            ub = (st + dr) / 2;

            if (vect[ub] <= endTime) {
                st = ub + 1;
            }
            else {
                dr = ub - 1;
            }
        }

        if (vect[ub] > endTime) ub--;

        return ub - lb + 1;
    }
};