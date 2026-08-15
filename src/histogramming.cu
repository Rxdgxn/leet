#include <cuda_runtime.h>

__global__ void clear(int* histogram, int num_bins) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    if (tid < num_bins)
        histogram[tid] = 0;
}

__global__ void kern(const int* input, int* histogram, int N, int num_bins) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    for (int i = tid; i < N; i += gridDim.x * blockDim.x)
        atomicAdd(&histogram[input[i]], 1);
}

// input, histogram are device pointers
extern "C" void solve(const int* input, int* histogram, int N, int num_bins) {
    const int blockSize = 256;
    const int gridSize = (N + blockSize - 1) / blockSize;

    clear<<<4, blockSize>>>(histogram, num_bins);
    kern<<<gridSize, blockSize>>>(input, histogram, N, num_bins);
    cudaDeviceSynchronize();
}