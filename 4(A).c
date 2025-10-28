#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    clock_t start = clock();
    int result = fib(n);
    clock_t end = clock();

    printf("The %dth Fibonacci number (Recursive) is: %d\n", n, result);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
