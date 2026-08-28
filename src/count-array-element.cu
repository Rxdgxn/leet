#include <cuda_runtime.h>

__global__ void kern(const int* input, int* output, int N, int K) {
    __shared__ int data[256];
    int tid = threadIdx.x + blockDim.x * blockIdx.x;

    data[threadIdx.x] = (tid < N) ? (input[tid] == K) : 0;
    __syncthreads();

    // Note: there is still room for improvement (parallel tree reduction)
    if (threadIdx.x == 0) {
        int perBlock = 0;

        for (int i = 0; i < 256; i++) {
            perBlock += data[i];
        }

        atomicAdd(output, perBlock);
    }
}

// input, output are device pointers
extern "C" void solve(const int* input, int* output, int N, int K) {
    const int blockSize = 256;
    const int gridSize = (N + blockSize - 1) / blockSize;

    kern<<<gridSize, blockSize>>>(input, output, N, K);
    cudaDeviceSynchronize(); 
}