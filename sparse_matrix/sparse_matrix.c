#include<stdio.h>
#include<stdlib.h>

#include "sparse_matrix.h"

void init_SparseMatrix(SparseMatrix *M, const char *filename) {
    FILE *fp = fopen(filename, "r");
    int r = 0;
    int c = 0;
    fscanf(fp, "%d", &r);
    fscanf(fp, "%d", &c);

    int number = 0;


    M->rows = r;
    M->cols = c;
    M->row_arr = (spm_node **)malloc(sizeof(spm_node *) * r);
    M->col_arr = (spm_node **)malloc(sizeof(spm_node *) * c);

    for (int i = 0; i < r; i++) {
        M->row_arr[i] = NULL;
    }

    for (int i = 0; i < c; i++) {
        M->col_arr[i] = NULL;
    }
    
    spm_node *p = NULL;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fscanf(fp, "%d", &number);
            if (number != 0) {
                spm_node *newnode = (spm_node *)malloc(sizeof(spm_node));
                newnode->data = number;
                newnode->rowno = i;
                newnode->colno = j;
                newnode->down = NULL;
                newnode->right = NULL;

                if (!M->row_arr[i]) { 
                    M->row_arr[i] = newnode;
                } else {
                    p = M->row_arr[i];
                    while (p->right) {
                        p = p->right;
                    }
                    p->right = newnode;
                }
                
                if (!M->col_arr[j]) {
                    M->col_arr[j] = newnode;
                } else {
                    p = M->col_arr[j];
                    while (p->down) {
                        p = p->down;
                    }
                    p->down = newnode;
                }
            }
        }
    }
    return;
}


void display_SparseMatrix(SparseMatrix *M) {
    for (int i = 0; i < M->rows; i++) {
        spm_node *p = M->row_arr[i];
        int found = 0;
        int column = 0;

        if (!p) {
            for (int j = 0; j < M->cols; j++) {
                printf("0 ");
            }
            printf("\n");
        } else {
            for (int j = 0; j < M->cols; j++) {
                spm_node *q = M->col_arr[j];
                if (!q) {
                    printf("0 ");
                } else {
                    while (q) {
                        if (q == p) {
                            printf("%d ", p->data);
                            p = p->right;
                            break;
                        } else {
                            q = q->down;
                            if (!q) printf("0 ");
                        }       
                    }
                }

                if (!p) {
                    for (int k = 0; k < M->cols - 1 - j; k++) {
                        printf("0 ");
                    }
                    break;
                }
            }
            printf("\n");
        }
    }
    return;
}


SparseMatrix *add_SparseMatrix(SparseMatrix *A, SparseMatrix *B) {
    if (A->rows != B->rows && A->cols != B->cols) {
        printf("Matrices of not same order!\nAbort.....\n");
        return NULL;
    }

    SparseMatrix *Result = (SparseMatrix *)malloc(sizeof(SparseMatrix));

    Result->rows = A->rows;
    Result->cols = A->cols;
    Result->row_arr = (spm_node **)malloc(sizeof(spm_node *) * Result->rows);
    Result->col_arr = (spm_node **)malloc(sizeof(spm_node *) * Result->cols);

    for (int i = 0; i < Result->rows; i++) {
        Result->row_arr[i] = NULL;
    }
    for (int i = 0; i < Result->cols; i++) {
        Result->col_arr[i] = NULL;
    }


    spm_node *a = NULL;
    spm_node *b = NULL;
    spm_node *r = NULL;
    spm_node *temp_r = NULL;
    spm_node *temp_c = NULL;

    for (int i = 0; i < Result->rows; i++) {
        a = A->row_arr[i];
        b = B->row_arr[i];

        while (a != NULL || b != NULL) {
            r = (spm_node *)malloc(sizeof(spm_node));
            r->down = NULL;
            r->right = NULL;
            r->rowno = i;

            if (a != NULL && b != NULL) {
                if (a->colno == b->colno) {
                    // printf("Assigned addition\n");
                    r->data = a->data + b->data;
                    r->colno = a->colno;
                    a = a->right;
                    b = b->right;
                } else {
                    if (a->colno > b->colno) {
                        // printf("Assigned 'b' value\n");
                        r->data = b->data;
                        r->colno = b->colno;
                        b = b->right;
                    } else if (a->colno < b->colno) {
                        // printf("Assigned 'a' value\n");
                        r->data = a->data;
                        r->colno = a->colno;
                        a = a->right;
                    }
                }                
            } else if (a != NULL && b == NULL) {
                // printf("Assigned 'a' value\n");
                r->data = a->data;
                r->colno = a->colno;
                a = a->right;
            } else if (a == NULL && b != NULL) {
                // printf("Assigned 'b' value\n");
                r->data = b->data;
                r->colno = b->colno;
                b = b->right;
            }
            // printf("r->data = %d\nr->rowno = %d\nr->colno = %d\n", r->data, r->rowno, r->colno);
            
            
            if (Result->row_arr[i] == NULL) {
                // printf("Assigned r to NULL row\n");
                Result->row_arr[i] = r;
            } else {
                temp_r = Result->row_arr[i];
                // printf("temp_r data: %d     %p\n", temp_r->data, temp_r->right);
                while (temp_r->right) {
                    // printf("temp_r data: %d     %p\n", temp_r->data, temp_r->right);
                    temp_r = temp_r->right;
                }
                temp_r->right = r;
            }

            if (Result->col_arr[r->colno] == NULL) {
                // printf("Assigned r to NULL col\n");
                Result->col_arr[r->colno] = r;
            } else {
                temp_c = Result->col_arr[r->colno];
                while (temp_c->down) {
                    temp_c = temp_c->down;
                }
                temp_c->down = r;
            }
        }


    }


    return Result;
}


SparseMatrix *sub_SparseMatrix(SparseMatrix *A, SparseMatrix *B) {
    if (A->rows != B->rows && A->cols != B->cols) {
        printf("Matrices of not same order!\nAbort.....\n");
        return NULL;
    }

    SparseMatrix *Result = (SparseMatrix *)malloc(sizeof(SparseMatrix));

    Result->rows = A->rows;
    Result->cols = A->cols;
    Result->row_arr = (spm_node **)malloc(sizeof(spm_node *) * Result->rows);
    Result->col_arr = (spm_node **)malloc(sizeof(spm_node *) * Result->cols);

    for (int i = 0; i < Result->rows; i++) {
        Result->row_arr[i] = NULL;
    }
    for (int i = 0; i < Result->cols; i++) {
        Result->col_arr[i] = NULL;
    }


    spm_node *a = NULL;
    spm_node *b = NULL;
    spm_node *r = NULL;
    spm_node *temp_r = NULL;
    spm_node *temp_c = NULL;

    for (int i = 0; i < Result->rows; i++) {
        a = A->row_arr[i];
        b = B->row_arr[i];

        while (a != NULL || b != NULL) {
            r = (spm_node *)malloc(sizeof(spm_node));
            r->down = NULL;
            r->right = NULL;
            r->rowno = i;

            if (a != NULL && b != NULL) {
                if (a->colno == b->colno) {
                    // printf("Assigned addition\n");
                    r->data = a->data - b->data;
                    r->colno = a->colno;
                    a = a->right;
                    b = b->right;
                } else {
                    if (a->colno > b->colno) {
                        // printf("Assigned 'b' value\n");
                        r->data = (-1) * (b->data);
                        r->colno = b->colno;
                        b = b->right;
                    } else if (a->colno < b->colno) {
                        // printf("Assigned 'a' value\n");
                        r->data = a->data;
                        r->colno = a->colno;
                        a = a->right;
                    }
                }                
            } else if (a != NULL && b == NULL) {
                // printf("Assigned 'a' value\n");
                r->data = a->data;
                r->colno = a->colno;
                a = a->right;
            } else if (a == NULL && b != NULL) {
                // printf("Assigned 'b' value\n");
                r->data = b->data;
                r->colno = b->colno;
                b = b->right;
            }
            // printf("r->data = %d\nr->rowno = %d\nr->colno = %d\n", r->data, r->rowno, r->colno);
            
            
            if (Result->row_arr[i] == NULL) {
                // printf("Assigned r to NULL row\n");
                Result->row_arr[i] = r;
            } else {
                temp_r = Result->row_arr[i];
                // printf("temp_r data: %d     %p\n", temp_r->data, temp_r->right);
                while (temp_r->right) {
                    // printf("temp_r data: %d     %p\n", temp_r->data, temp_r->right);
                    temp_r = temp_r->right;
                }
                temp_r->right = r;
            }

            if (Result->col_arr[r->colno] == NULL) {
                // printf("Assigned r to NULL col\n");
                Result->col_arr[r->colno] = r;
            } else {
                temp_c = Result->col_arr[r->colno];
                while (temp_c->down) {
                    temp_c = temp_c->down;
                }
                temp_c->down = r;
            }
        }


    }


    return Result;
}


SparseMatrix *mul_SparseMatrix(SparseMatrix *A, SparseMatrix *B) {
    if (A->cols != B->rows) {
        printf("Matrices of not correct order!\nAbort.....\n");
        return NULL;
    }
    SparseMatrix *Result = (SparseMatrix *)malloc(sizeof(SparseMatrix));

    Result->rows = A->rows;
    Result->cols = B->cols;
    Result->row_arr = (spm_node **)malloc(sizeof(spm_node *) * Result->rows);
    Result->col_arr = (spm_node **)malloc(sizeof(spm_node *) * Result->cols);

    for (int i = 0; i < Result->rows; i++) {
        Result->row_arr[i] = NULL;
    }
    for (int i = 0; i < Result->cols; i++) {
        Result->col_arr[i] = NULL;
    }

    spm_node *p = NULL;
    spm_node *q = NULL;
    spm_node *temp_r = NULL;
    spm_node *temp_c = NULL;
    int sum = 0;
    for (int i = 0; i < Result->rows; i++) {
        for (int j = 0; j < Result->cols; j++) {
            p = A->row_arr[i];
            q = B->col_arr[j];
            sum = 0;
            while (p != NULL && q != NULL) {
                if (p->colno < q->rowno) {
                    sum = sum + 0;
                    q = q->down;
                } else if (p->colno > q->rowno) {
                    sum = sum + 0;
                    p = p->right;
                } else {
                    sum = sum + ((p->data) * (q->data));
                    q = q->down;
                    p = p->right;
                }
            }
            spm_node *r = (spm_node *)malloc(sizeof(spm_node));
            r->data = sum;
            r->rowno = i;
            r->colno = j;
            r->right = NULL;
            r->down = NULL;
            if (Result->row_arr[i] == NULL) {
                // printf("Assigned r to NULL row\n");
                Result->row_arr[i] = r;
            } else {
                temp_r = Result->row_arr[i];
                // printf("temp_r data: %d     %p\n", temp_r->data, temp_r->right);
                while (temp_r->right) {
                    // printf("temp_r data: %d     %p\n", temp_r->data, temp_r->right);
                    temp_r = temp_r->right;
                }
                temp_r->right = r;
            }

            if (Result->col_arr[r->colno] == NULL) {
                // printf("Assigned r to NULL col\n");
                Result->col_arr[r->colno] = r;
            } else {
                temp_c = Result->col_arr[r->colno];
                while (temp_c->down) {
                    temp_c = temp_c->down;
                }
                temp_c->down = r;
            }
        }
    }

    return Result;
}
