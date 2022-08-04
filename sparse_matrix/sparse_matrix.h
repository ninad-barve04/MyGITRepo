#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H (1)

typedef struct spm_node {
    int data;
    int rowno;
    int colno;
    struct spm_node *right;
    struct spm_node *down;
} spm_node;

typedef struct SparseMatrix {
    int rows;
    int cols;
    spm_node **row_arr; 
    spm_node **col_arr;
} SparseMatrix;



void init_SparseMatrix(SparseMatrix *M, const char *filename);
void display_SparseMatrix(SparseMatrix *M);
SparseMatrix *add_SparseMatrix(SparseMatrix *A, SparseMatrix *B);
SparseMatrix *sub_SparseMatrix(SparseMatrix *A, SparseMatrix *B);
SparseMatrix *mul_SparseMatrix(SparseMatrix *A, SparseMatrix *B);


#endif /* ifndef SPARSE_MATRIX_H */
