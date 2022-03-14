#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *right, *down;
}node;

typedef struct SparseMatrix
{
    int r, c;
    node **row, **col;
}SparseMatrix;

void init_SparseMatrix(SparseMatrix *M, int r, int c, int A[r][c])
{
    M->r = r;
    M->c = c;
    M->row = (node**)malloc(sizeof(node*) * r);
    M->col = (node**)malloc(sizeof(node*) * c);

    for (int i = 0; i < r; i++) M->row[i] = NULL;
    for (int i = 0; i < c; i++) M->col[i] = NULL;
    
    node *p = NULL;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (A[i][j] != 0)
            {
                node *nn = (node*)malloc(sizeof(node));
                nn->data = A[i][j];
                nn->down = NULL;
                nn->right = NULL;

                if (!M->row[i]) M->row[i] = nn;
                else
                {
                    p = M->row[i];
                    while (p->right)
                    {
                        p = p->right;
                    }
                    p->right = nn;
                }
                
                if (!M->col[j]) M->col[j] = nn;
                else
                {
                    p = M->col[j];
                    while (p->down)
                    {
                        p = p->down;
                    }
                    p->down = nn;
                }
            }
        }
    }
    return;
}

void display(SparseMatrix M)
{
    for (int i = 0; i < M.r; i++)
    {
        node *p = M.row[i];
        int found = 0;
        int column = 0;

        if (!p)
        {
            for (int j = 0; j < M.c; j++)
            {
                printf("0 ");
            }
            printf("\n");
        }

        else
        {
            for (int j = 0; j < M.c; j++)
            {
                node *q = M.col[j];
                if (!q) printf("0 ");
                else
                {
                    while (q)
                    {
                        if (q == p)
                        {
                            printf("%d ", p->data);
                            p = p->right;
                            break;
                        }

                        else
                        {
                            q = q->down;
                            if (!q) printf("0 ");
                        }       
                    }
                }

                if (!p)
                {
                    for (int k = 0; k < 4 - j; k++)
                    {
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

int main()
{
    int A[3][5] = {{0, 0, 2, 0, 0}, {0, 3, 4, 0, 5}, {6, 0, 7, 0, 0}};
    int r = 3;
    int c = 5;
    
    SparseMatrix M1;
    init_SparseMatrix(&M1, r, c, A);
    printf("Success!!\n");
    display(M1);
    printf("Success!!\n");
}
