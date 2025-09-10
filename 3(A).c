#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10 //change this size

void generateRandomMatrix(int mat[n][n], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            mat[i][j] = rand() % 100;
        }
    }
}

void multiplyMatrices(int a[n][n], int b[n][n], int c[n][n], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            c[i][j] = 0;
            for(int k=0; k<size; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int mat1[n][n], mat2[n][n], product[n][n];

    srand(time(0));

    clock_t start = clock();
    for(int i=0; i<10000; i++) {
        generateRandomMatrix(mat1, n);
        generateRandomMatrix(mat2, n);
        multiplyMatrices(mat1, mat2, product, n);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("Time taken to multiply %dx%d matrices : %f seconds\n", n, n, time_taken);

    return 0;
}
