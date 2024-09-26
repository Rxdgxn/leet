#include "../include.h"

class MyCalendar {
public:
    set<pair<int, int>> calendar;
    
    bool book(int start, int end) {
        pair<int, int> event = {start, end};
        auto nextEvent = calendar.lower_bound(event);

        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;
        }

        if (nextEvent != calendar.begin()) {
            auto prevEvent = prev(nextEvent);
            
            if (prevEvent->second > start) {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }
};