#include <cuda_runtime.h>

// Could be further optimized by using shared memory
__global__ void kern(const float* points, int* indices, int N) {
    int tid = threadIdx.x + blockDim.x * blockIdx.x;
    if (tid >= N)
        return;

    float x = points[3 * tid];
    float y = points[3 * tid + 1];
    float z = points[3 * tid + 2];

    float best_dist = 1e9;
    int index = -1;

    for (int i = 0; i < N; i++) {
        if (i == tid)
            continue;

        float dist = (x - points[3 * i]) * (x - points[3 * i]) + (y - points[3 * i + 1]) * (y - points[3 * i + 1]) + (z - points[3 * i + 2]) * (z - points[3 * i + 2]);

        if (dist < best_dist) {
            best_dist = dist;
            index = i;
        }
    }

    indices[tid] = index;
}

// points and indices are device pointers
extern "C" void solve(const float* points, int* indices, int N) {
    const int blockSize = 256;
    const int gridSize = (N + blockSize - 1) / blockSize;

    kern<<<gridSize, blockSize>>>(points, indices, N);
    cudaDeviceSynchronize();
}
