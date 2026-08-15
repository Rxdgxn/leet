#include <cuda_runtime.h>

#define BLOCKSIZE 32

// Not really sure how i could leverage the matrix being sparse
__global__ void kern(const float* A, const float* x, float* y, int columns) {
    int base = columns * blockIdx.x;
    float res = 0;
    
    for (int i = threadIdx.x; i < columns; i += BLOCKSIZE)
        res += A[base + i] * x[i];

    // Warp shuffle reduction (sums values across all 32 threads in the warp) - thanks gemini
    for (int offset = 16; offset > 0; offset /= 2)
        res += __shfl_down_sync(0xffffffff, res, offset);

    if (threadIdx.x == 0)
        y[blockIdx.x] = res;
}

// A, x, y are device pointers
extern "C" void solve(const float* A, const float* x, float* y, int M, int N, int nnz) {
    const int gridSize = M; // it should be ok since M is at most 10000

    kern<<<gridSize, BLOCKSIZE>>>(A, x, y, N);
    cudaDeviceSynchronize();
}