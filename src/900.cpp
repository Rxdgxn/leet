#include "../include.h"

class RLEIterator {
public:
    deque<int> apparitions, values;
    int q = 0;

    RLEIterator(vector<int>& encoded) {
        for (int i = 0; i < encoded.size(); i++) {
            if (i % 2 == 0) {
                if (encoded[i] == 0) {
                    i++;
                    continue;
                }
                apparitions.push_back(encoded[i]);
            }
            else values.push_back(encoded[i]);
        }

        q = apparitions.front();


    }
    
    int next(int n) {
        q -= n;
        
        while (q < 0 && !apparitions.empty()) {
            apparitions.pop_front();
            values.pop_front();
            q += apparitions.front();
        }
        
        if (values.empty()) return -1;

        return values.front();
    }
};