#include "../include.h"

class H2O {
public:
    counting_semaphore<2> hydro, oxy;
    barrier<> particles;
    mutex mtx;
    int count = 3;

    H2O() : hydro(2), oxy(1), particles(3) {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        hydro.acquire();
        releaseHydrogen();

        particles.arrive();

        {
            lock_guard<mutex> lock(mtx);

            count--;
            if (count == 0) {
                count = 3;
                hydro.release();
                hydro.release();
                oxy.release();
            }
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        oxy.acquire();
        releaseOxygen();

        particles.arrive();

        {
            lock_guard<mutex> lock(mtx);

            count--;
            if (count == 0) {
                count = 3;
                hydro.release();
                hydro.release();
                oxy.release();
            }
        }
    }
};