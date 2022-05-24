#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H (1)

typedef struct graphnode {
    int vertex;
    struct graphnode *next;
} graphnode;

typedef struct GraphList {
    graphnode **node_array;
} GraphList;

void init

#endif /* ifndef ADJACENCY_LIST_H */
