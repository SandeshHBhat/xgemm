#include <iostream>
#include <vector>
#include <chrono>

// Naïve GEMM using vector<vector<float>> (2D matrix)
void naive_gemm_2d(const std::vector<std::vector<float>>& A,
                   const std::vector<std::vector<float>>& B,
                   std::vector<std::vector<float>>& C,
                   int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
}

int main() {
    int N = 4096;
    std::vector<std::vector<float>> A(N, std::vector<float>(N, 1.0f));
    std::vector<std::vector<float>> B(N, std::vector<float>(N, 1.0f));
    std::vector<std::vector<float>> C(N, std::vector<float>(N, 0.0f));

    auto start = std::chrono::high_resolution_clock::now();
    naive_gemm_2d(A, B, C, N);
    auto end = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration<double, std::milli>(end - start).count();

    float checksum = 0.0f;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            checksum += C[i][j];

    std::cout << "Checksum: " << checksum << "\n";
    std::cout << "Time: " << ms << " ms\n";
}

