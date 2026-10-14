#include <stdlib.h>
#include <threads.h>

typedef struct {
    char hydro, oxy;
    mtx_t count_mutex;
} H2O;

void releaseHydrogen();

void releaseOxygen();

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    obj->hydro = obj->oxy = 0;
    mtx_init(&obj->count_mutex, mtx_plain);
    
    return obj;
}

// Could have also just used a while(true) loop, as a spinlock
// Also there was apparently a faster version using semaphores and a barrier, since this solution basically relies on "luck" (retrying to pass too fast)

void hydrogen(H2O* obj) {
retry:
    mtx_lock(&obj->count_mutex);

    if (obj->hydro == 2) {
        mtx_unlock(&obj->count_mutex);
        goto retry;
    }

    obj->hydro++;

    if (obj->hydro == 2 && obj->oxy == 1) {
        obj->hydro = obj->oxy = 0;
    }
    
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();

    mtx_unlock(&obj->count_mutex);
}

void oxygen(H2O* obj) {
retry:
    mtx_lock(&obj->count_mutex);

    if (obj->oxy == 1) {
        mtx_unlock(&obj->count_mutex);
        goto retry;
    }

    obj->oxy = 1;

    if (obj->hydro == 2 && obj->oxy == 1) {
        obj->hydro = obj->oxy = 0;
    }
    
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();

    mtx_unlock(&obj->count_mutex);
}

void h2oFree(H2O* obj) {
    mtx_destroy(&obj->count_mutex);
    free(obj);
}