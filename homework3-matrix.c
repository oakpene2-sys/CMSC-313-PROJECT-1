#include <stdio.h>

/* Function declarations */
void matmult(int result[3][3], int first[3][3], int second[3][3]);
void matadd(int result[3][3], int first[3][3], int second[3][3]);
void printMatrix(int mat[3][3]);


int main()
{
    /* Given matrices */
    int A[3][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    int B[3][3] = {
        {1, 2, 0}, 
        {3, 4, 5}, 
        {0, 6, 7}
    };

    /* Result matrices */
    int multResult[3][3];
    int finalResult[3][3];

    /* Perform calculations */
    matmult(multResult, A, B);     /* multResult = A * B */
    matadd(finalResult, multResult, A);  /* finalResult = (A * B) + A */
    
    
    /* Print matrices in required format */
    printf("    [%d %d %d]           [%d %d %d]\n", A[0][0], A[0][1], A[0][2], B[0][0], B[0][1], B[0][2]);
    printf("A = |%d %d %d|       B = |%d %d %d|\n", A[1][0], A[1][1], A[1][2], B[1][0], B[1][1], B[1][2]);
    printf("    [%d %d %d]           [%d %d %d]\n", A[2][0], A[2][1], A[2][2], B[2][0], B[2][1], B[2][2]);
    printf(" \n");
    printf("          [%3d %3d %3d]\n", finalResult[0][0], finalResult[0][1], finalResult[0][2]);
    printf("A*B+A =   |%3d %3d %3d|\n", finalResult[1][0], finalResult[1][1], finalResult[1][2]);
    printf("          [%3d %3d %3d]\n", finalResult[2][0], finalResult[2][1], finalResult[2][2]);

    return 0;
    }
    
    /* multiply matrices */
void matmult(int result[3][3], int first[3][3], int second[3][3]) {
    int i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (k = 0; k < 3; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

/* add matrices */
void matadd(int result[3][3], int first[3][3], int second[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}
