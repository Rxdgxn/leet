#include <cuda_runtime.h>

__device__ int lower_bound(const float *xs, float x, int n) {
    int l = 0, r = n;

    while (l < r) {
        int m = l + (r - l) / 2;

        if (xs[m] < x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }

    return l;
}

__device__ int upper_bound(const float *xs, float x, int n) {
    int l = 0, r = n;

    while (l < r) {
        int m = l + (r - l) / 2;

        if (xs[m] <= x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }

    return l;
}

__global__ void place_A(const float *A, const float *B, float *output, int M, int N) {
    int tid = threadIdx.x + blockDim.x * blockIdx.x;
    if (tid >= M)
        return;

    int offset = lower_bound(B, A[tid], N);

    output[tid + offset] = A[tid];
}

__global__ void place_B(const float *B, const float *A, float *output, int N, int M) {
    int tid = threadIdx.x + blockDim.x * blockIdx.x;
    if (tid >= N)
        return;

    int offset = upper_bound(A, B[tid], M);

    output[tid + offset] = B[tid];
}

// A, B, C are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* A, const float* B, float* C, int M, int N) {
    const int blockSize = 256;

    place_A<<<(M + blockSize - 1) / blockSize, blockSize>>>(A, B, C, M, N);
    place_B<<<(N + blockSize - 1) / blockSize, blockSize>>>(B, A, C, N, M);
    cudaDeviceSynchronize();
}