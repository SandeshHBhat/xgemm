#include <iostream>
#include <vector>
#include <chrono>

// GEMM with loop reorder: i-k-j
void gemm_loop_reorder(const float* A, const float* B, float* C, int N) {
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j)
                C[i*N + j] += A[i*N + k] * B[k*N + j];
}

int main() {
    int N = 4096;
    std::vector<float> A(N*N, 1.0f);
    std::vector<float> B(N*N, 1.0f);
    std::vector<float> C(N*N, 0.0f);

    auto start = std::chrono::high_resolution_clock::now();
    gemm_loop_reorder(A.data(), B.data(), C.data(), N);
    auto end = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration<double, std::milli>(end - start).count();

    float checksum = 0.0f;
    for (auto v : C) checksum += v;

    std::cout << "Checksum: " << checksum << "\n";
    std::cout << "Time: " << ms << " ms\n";
}

