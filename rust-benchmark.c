#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000000 // 1 billion elements

// ---------------------------------------------------------
// 1. Standard C Implementation
// ---------------------------------------------------------
long long sum_c(const long long *arr, size_t size) {
    long long sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// ---------------------------------------------------------
// 2. Rust Implementation (via FFI)
// ---------------------------------------------------------
// We tell the C compiler that this function exists somewhere else (in our Rust lib)
extern long long sum_rust(const long long *arr, size_t size);

// ---------------------------------------------------------
// Helper function to calculate time difference in seconds
// ---------------------------------------------------------
double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    printf("Allocating array of %d elements...\n", ARRAY_SIZE);
    long long *arr = malloc(ARRAY_SIZE * sizeof(long long));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = 1;
    }

    struct timespec start, end;
    long long result_c, result_rust;
    double time_c, time_rust;

    printf("Running benchmarks...\n\n");

    // --- Benchmark C Version ---
    clock_gettime(CLOCK_MONOTONIC, &start);
    result_c = sum_c(arr, ARRAY_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    time_c = get_time_diff(start, end);
    printf("[C Version]    Result: %lld | Time: %.6f seconds\n", result_c, time_c);

    // --- Benchmark Rust Version ---
    clock_gettime(CLOCK_MONOTONIC, &start);
    result_rust = sum_rust(arr, ARRAY_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    time_rust = get_time_diff(start, end);
    printf("[Rust Version] Result: %lld | Time: %.6f seconds\n", result_rust, time_rust);

    // --- Comparison ---
    printf("\nDifference: Rust was %.2f%% %s than C.\n", 
           (time_c > time_rust) ? ((time_c / time_rust - 1) * 100) : ((time_rust / time_c - 1) * 100),
           (time_c > time_rust) ? "faster" : "slower");

    free(arr);
    return 0;
}