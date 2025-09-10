#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 64  // maximum matrix size supported

void add_matrix(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowA, int colA, int rowB, int colB, int rowC, int colC) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            C[rowC+i][colC+j] = A[rowA+i][colA+j] + B[rowB+i][colB+j];
        }
    }
}

void multiply(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowA, int colA, int rowB, int colB, int rowC, int colC) {
    if(n <= 2) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                C[rowC+i][colC+j] = 0;
                for(int k=0; k<n; k++) {
                    C[rowC+i][colC+j] += A[rowA+i][colA+k] * B[rowB+k][colB+j];
                }
            }
        }
    } else {
        int k = n / 2;
        int M1[MAX][MAX] = {0};
        int M2[MAX][MAX] = {0};

        // C11 = A11*B11 + A12*B21
        multiply(k, A,B,M1,rowA, colA, rowB, colB,0,0);
        multiply(k,A,B,M2, rowA, colA+k, rowB+k, colB,0,0);
        add_matrix(k,M1,M2,C, 0,0,0,0,rowC, colC);

        // C12 = A11*B12 + A12*B22
        multiply(k, A,B,M1,rowA, colA, rowB, colB+k,0,0);
        multiply(k,A,B,M2, rowA, colA+k, rowB+k, colB+k,0,0);
        add_matrix(k,M1,M2,C, 0,0,0,0,rowC, colC+k);

        // C21 = A21*B11 + A22*B21
        multiply(k, A,B,M1,rowA+k, colA, rowB, colB,0,0);
        multiply(k,A,B,M2, rowA+k, colA+k, rowB+k, colB,0,0);
        add_matrix(k,M1,M2,C, 0,0,0,0,rowC+k, colC);

        // C22 = A21*B12 + A22*B22
        multiply(k, A,B,M1,rowA+k, colA, rowB, colB+k,0,0);
        multiply(k,A,B,M2, rowA+k, colA+k, rowB+k, colB+k,0,0);
        add_matrix(k,M1,M2,C, 0,0,0,0,rowC+k, colC+k);
    }
}

void generateRandomMatrix(int mat[MAX][MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mat[i][j] = rand() % 100;
        }
    }
}

int main() {
    int A[MAX][MAX] = {0};
    int B[MAX][MAX] = {0};
    int C[MAX][MAX] = {0};
    int n;

    printf("Enter the size of matrices (<= %d, power of 2): ", MAX);
    scanf("%d", &n);

    if(n > MAX || n <= 0) {
        printf("Invalid size!\n");
        return 1;
    }

    srand(time(0));

    clock_t start = clock();
    for(int i=0; i<10000; i++) {
        generateRandomMatrix(A, n);
        generateRandomMatrix(B, n);
        multiply(n, A, B, C, 0, 0, 0, 0, 0, 0);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("Time taken to multiply %dx%d matrices (recursive): %f seconds\n", n, n, time_taken);

    return 0;
}
