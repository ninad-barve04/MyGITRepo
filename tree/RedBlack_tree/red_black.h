#ifndef RED_BLACK_H
#define RED_BLACK_H (1)

typedef enum COLOR {
    RED,
    BLACK,
} COLOR;

typedef struct rbnode {
    int data;
    COLOR color;
    struct rbnode *left;
    struct rbnode *right;
    struct rbnode *parent;    
} rbnode;

typedef rbnode * RBtree;

void recolor(rbnode *node);

#endif /* ifndef RED_BLACK_H */
