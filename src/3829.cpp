#include "../include.h"

// Just as well could've used a more linear approach because of the constraints
class RideSharingSystem {
private:
    typedef uint64_t Info;
    set<Info> riders;
    uint32_t time = 0;
    unordered_map<int, uint32_t> riderTime;

    queue<int> drivers;

    Info make_info(uint32_t id, uint32_t time) {
        Info ret = time;
        ret <<= 32;
        ret |= id;

        return ret;
    }
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riderTime[riderId] = time++;
        riders.insert(make_info(riderId, riderTime[riderId]));
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if (riders.empty() || drivers.empty()) {
            return {-1, -1};
        }

        Info r = *riders.begin();
        riders.erase(r);
        uint32_t mask = ~0;
        int riderId = (r & mask);

        int driverId = drivers.front();
        drivers.pop();

        return {driverId, riderId};
    }
    
    void cancelRider(int riderId) {
        riders.erase(make_info(riderId, riderTime[riderId]));
    }
};