#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 64

// add two submatrices
void add_matrix(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
                int rowA, int colA, int rowB, int colB, int rowC, int colC) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            C[rowC+i][colC+j] = A[rowA+i][colA+j] + B[rowB+i][colB+j];
        }
    }
}

// subtract two submatrices
void sub_matrix(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
                int rowA, int colA, int rowB, int colB, int rowC, int colC) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            C[rowC+i][colC+j] = A[rowA+i][colA+j] - B[rowB+i][colB+j];
        }
    }
}

// iterative method
void iterative(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            C[i][j] = 0;
            for(int k=0; k<n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// divide and conquer method
void divide_conquer(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
                    int rowA, int colA, int rowB, int colB, int rowC, int colC) {
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
        int k = n/2;
        int M1[MAX][MAX]={0}, M2[MAX][MAX]={0};

        //C11= A11*B11 + A12*B21
        divide_conquer(k,A,B,M1,rowA,colA,rowB,colB,0,0);
        divide_conquer(k,A,B,M2,rowA,colA+k,rowB+k,colB,0,0);
        add_matrix(k,M1,M2,C,0,0,0,0,rowC,colC);

        //C12= A11*B12 + A12*B22
        divide_conquer(k,A,B,M1,rowA,colA,rowB,colB+k,0,0);
        divide_conquer(k,A,B,M2,rowA,colA+k,rowB+k,colB+k,0,0);
        add_matrix(k,M1,M2,C,0,0,0,0,rowC,colC+k);

        //C21= A21*B11 + A22*B21
        divide_conquer(k,A,B,M1,rowA+k,colA,rowB,colB,0,0);
        divide_conquer(k,A,B,M2,rowA+k,colA+k,rowB+k,colB,0,0);
        add_matrix(k,M1,M2,C,0,0,0,0,rowC+k,colC);

        //C22= A21*B12 + A22*B22
        divide_conquer(k,A,B,M1,rowA+k,colA,rowB,colB+k,0,0);
        divide_conquer(k,A,B,M2,rowA+k,colA+k,rowB+k,colB+k,0,0);
        add_matrix(k,M1,M2,C,0,0,0,0,rowC+k,colC+k);
    }
}

// Strassen method
void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
              int rowA, int colA, int rowB, int colB, int rowC, int colC) {
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
        int k = n/2;
        int P[MAX][MAX]={0}, Q[MAX][MAX]={0}, R[MAX][MAX]={0}, S[MAX][MAX]={0};
        int T[MAX][MAX]={0}, U[MAX][MAX]={0}, V[MAX][MAX]={0};
        int T1[MAX][MAX]={0}, T2[MAX][MAX]={0};

        //P= (A11+A22)*(B11+B22)
        add_matrix(k,A,A,T1,rowA,colA,rowA+k,colA+k,0,0);
        add_matrix(k,B,B,T2,rowB,colB,rowB+k,colB+k,0,0);
        strassen(k,T1,T2,P,0,0,0,0,0,0);

        //Q= (A21+A22)*B11
        add_matrix(k,A,A,T1,rowA+k,colA,rowA+k,colA+k,0,0);
        strassen(k,T1,B,Q,0,0,rowB,colB,0,0);

        //R= A11*(B12-B22)
        sub_matrix(k,B,B,T2,rowB,colB+k,rowB+k,colB+k,0,0);
        strassen(k,A,T2,R,rowA,colA,0,0,0,0);

        //S= A22*(B21-B11)
        sub_matrix(k,B,B,T2,rowB+k,colB,rowB,colB,0,0);
        strassen(k,A,T2,S,rowA+k,colA+k,0,0,0,0);

        //T= (A11+A12)*B22
        add_matrix(k,A,A,T1,rowA,colA,rowA,colA+k,0,0);
        strassen(k,T1,B,T,0,0,rowB+k,colB+k,0,0);

        //U= (A21-A11)*(B11+B12)
        sub_matrix(k,A,A,T1,rowA+k,colA,rowA,colA,0,0);
        add_matrix(k,B,B,T2,rowB,colB,rowB,colB+k,0,0);
        strassen(k,T1,T2,U,0,0,0,0,0,0);

        //V= (A12-A22)*(B21+B22)
        sub_matrix(k,A,A,T1,rowA,colA+k,rowA+k,colA+k,0,0);
        add_matrix(k,B,B,T2,rowB+k,colB,rowB+k,colB+k,0,0);
        strassen(k,T1,T2,V,0,0,0,0,0,0);

        //C11= P+S-T+V
        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                C[rowC+i][colC+j] = P[i][j] + S[i][j] - T[i][j] + V[i][j];
            }
        }

        //C12= R+T
        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                C[rowC+i][colC+j+k] = R[i][j] + T[i][j];
            }
        }

        //C21= Q+S
        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                C[rowC+i+k][colC+j] = Q[i][j] + S[i][j];
            }
        }

        //C22= P+R-Q+U
        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                C[rowC+i+k][colC+j+k] = P[i][j] + R[i][j] - Q[i][j] + U[i][j];
            }
        }
    }
}

// generate random matrix
void generateRandomMatrix(int n, int M[MAX][MAX]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            M[i][j] = rand() % 100;
        }
    }
}

int main() {
    int A[MAX][MAX]={0}, B[MAX][MAX]={0}, C[MAX][MAX]={0};
    int n;

    printf("Enter the size of matrices (power of 2, <= %d): ", MAX);
    scanf("%d",&n);

    srand(time(0));

    // Iterative
    clock_t start = clock();
    for(int i=0; i<10000; i++) {
        generateRandomMatrix(n,A);
        generateRandomMatrix(n,B);
        iterative(n,A,B,C);
    }
    clock_t end = clock();
    double time_iter = ((double)(end-start))/CLOCKS_PER_SEC/1000.0;

    // Divide & Conquer
    start = clock();
    for(int i=0; i<10000; i++) {
        generateRandomMatrix(n,A);
        generateRandomMatrix(n,B);
        divide_conquer(n,A,B,C,0,0,0,0,0,0);
    }
    end = clock();
    double time_divide_conquer = ((double)(end-start))/CLOCKS_PER_SEC/1000.0;

    // Strassen
    start = clock();
    for(int i=0; i<10000; i++) {
        generateRandomMatrix(n,A);
        generateRandomMatrix(n,B);
        strassen(n,A,B,C,0,0,0,0,0,0);
    }
    end = clock();
    double time_strassen = ((double)(end-start))/CLOCKS_PER_SEC/1000.0;

    printf("Time taken for %dx%d matrices:\n",n,n);
    printf("Iterative: %f seconds\n", time_iter);
    printf("Divide & Conquer: %f seconds\n", time_divide_conquer);
    printf("Strassen: %f seconds\n", time_strassen);

    return 0;
}
