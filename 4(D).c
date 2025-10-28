#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
long long nthFibonacciBottomUp(int n) {
    if (n <= 1) return n;
    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0 || n > 100000) {
        printf("Please enter a valid number (0–100000).\n");
        return 1;
    }

    // Print nth Fibonacci once
    long long result = nthFibonacciBottomUp(n);
    printf("The %dth Fibonacci number (Bottom-Up DP) is: %lld\n", n, result);

    // Measure time using 1000 repetitions (without printing)
    clock_t start = clock();
    for (int k = 0; k < 100000; k++) {
        nthFibonacciBottomUp(n);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("Average time taken to compute %dth Fibonacci (Bottom-Up DP): %f seconds\n", n, time_taken);

    return 0;
}
