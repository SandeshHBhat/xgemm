# xGEMM: High-performance Matrix Multiplication
🚀 Build a GEMM pipeline from naive O(n^3) to multi-core cache-blocked, SIMD-optimized, benchmarked vs OpenBLAS on ARM64 (Mac M3).

## Steps
- Naïve triple loop GEMM (baseline)
- Loop reordering & contiguous access
- Cache blocking (tiling)
- Multithreading (std::thread)
- SIMD auto-vectorization (NEON)
- CUDA port with shared memory tiling
- Benchmarked vs OpenBLAS / cuBLAS

