#include <cuda_runtime.h>

// NOTE: this entire algorithm is very useful, it seems
__global__ void kern(const float* input, float* output, int N) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    __shared__ float data[256];
    data[threadIdx.x] = tid < N ? input[tid] : 0;
    __syncthreads();

    for (int s = 128; s >= 1; s /= 2) {
        if (threadIdx.x < s) {
            data[threadIdx.x] += data[threadIdx.x + s];
        }
        __syncthreads();
    }

    if (threadIdx.x == 0) {
        atomicAdd(output, data[0]);
    }
}

// input, output are device pointers
extern "C" void solve(const float* input, float* output, int N) {
    const int blockSize = 256;
    const int gridSize = (N + blockSize - 1) / blockSize;

    cudaMemset(output, 0, sizeof(float));

    kern<<<gridSize, blockSize>>>(input, output, N);
    cudaDeviceSynchronize();
}
