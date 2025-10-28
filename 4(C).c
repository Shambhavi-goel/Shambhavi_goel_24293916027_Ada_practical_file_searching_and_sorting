#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
long long fib_array[100]; // memo array

long long fibTopDown(int n) {
    if (n <= 1) return n;
    if (fib_array[n] != 0) return fib_array[n];
    fib_array[n] = fibTopDown(n - 1) + fibTopDown(n - 2);
    return fib_array[n];
}

int main() {
    int n;
    printf("Enter n (up to 92): ");
    scanf("%d", &n);

    if (n < 0 || n > 92) {
        printf("Please enter a valid number (0 - 92).\n");
        return 1;
    }

    // Print nth Fibonacci once
    for (int i = 0; i < 100; i++) fib_array[i] = 0; // initialize memo
    int result = fibTopDown(n);
    printf("The %dth Fibonacci number (Top-Down DP) is: %d\n", n, result);

    // Measure time using 1000 repetitions (without printing)
    clock_t start = clock();
    for (int k = 0; k < 100000; k++) {
        for (int i = 0; i < 100; i++) fib_array[i] = 0; // reset memo
        fibTopDown(n); // compute silently
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("Average time taken to compute %dth Fibonacci (Top-Down DP): %f seconds\n", n, time_taken);

    return 0;
}
