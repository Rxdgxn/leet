#include <cuda_runtime.h>

#define BLOCK_SIZE 256

__global__ void kern(const float* y_samples, float* result, float scalar, int n) {
    __shared__ float data[BLOCK_SIZE];

    int tid = threadIdx.x;
    int gtid = blockIdx.x * blockDim.x + tid;

    data[tid] = (gtid < n ? y_samples[gtid] : 0.0f);
    __syncthreads();

    for (int s = BLOCK_SIZE >> 1; s > 0; s >>= 1) {
        if (tid < s) {
            data[tid] += data[tid + s];
        }
        __syncthreads();
    }

    if (tid == 0) {
        atomicAdd(result, data[0] * scalar);
    }
}

// y_samples, result are device pointers
extern "C" void solve(const float* y_samples, float* result, float a, float b, int n) {
    const int gridSize = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;

    cudaMemset(result, 0, sizeof(float));

    kern<<<gridSize, BLOCK_SIZE>>>(y_samples, result, (b - a) / (float)n, n);
}