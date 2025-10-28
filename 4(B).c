#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Series (Iterative): ");
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}
 
int main() {
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive number of terms.\n");
        return 1;
    }

    clock_t start = clock();
    printFibonacci(terms);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
