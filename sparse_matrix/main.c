#include<stdio.h>
#include<stdlib.h>

#include "sparse_matrix.h"


int main(int argc, const char *argv[])
{
    // SparseMatrix M1;
    // init_SparseMatrix(&M1, argv[1]);
    // printf("Success!!\n");
    // display_SparseMatrix(&M1);
    // printf("Success!!\n");

    SparseMatrix A;
    init_SparseMatrix(&A, "mat1.txt");
    printf("Matrix A\n");
    display_SparseMatrix(&A);
    SparseMatrix B;
    init_SparseMatrix(&B, "mat2.txt");
    printf("\nMatrix B\n");
    display_SparseMatrix(&B);
    

    // SparseMatrix *C = add_SparseMatrix(&A, &B);
    // SparseMatrix *D = sub_SparseMatrix(&A, &B);
    // printf("\nMatrix C\n");
    // display_SparseMatrix(C);
    // printf("\nMatrix D\n");
    // display_SparseMatrix(D);

    SparseMatrix *E = mul_SparseMatrix(&B, &A);
    printf("\nMatrix E\n");
    display_SparseMatrix(E);
    return 0;
}

