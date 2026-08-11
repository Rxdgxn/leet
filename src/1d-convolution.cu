#include <cuda_runtime.h>

__global__ void convolution_1d_kernel(const float* input, const float* kernel, float* output, int input_size, int kernel_size) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    if (tid > input_size - kernel_size)
        return;

    float res = 0;
    for (int i = 0; i < kernel_size; i++) {
        res += input[tid + i] * kernel[i];
    }

    output[tid] = res;
}

// input, kernel, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* input, const float* kernel, float* output, int input_size,
                      int kernel_size) {
    int output_size = input_size - kernel_size + 1;
    int threadsPerBlock = 256;
    int blocksPerGrid = (output_size + threadsPerBlock - 1) / threadsPerBlock;

    convolution_1d_kernel<<<blocksPerGrid, threadsPerBlock>>>(input, kernel, output, input_size,
                                                              kernel_size);
    cudaDeviceSynchronize();
}
