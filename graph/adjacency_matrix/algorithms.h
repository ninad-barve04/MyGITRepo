#ifndef   ALGORITHMS_H
#define   ALGORITHMS_H (1)

#include "adjacency_matrix.h"

/**
 * @brief Typedef structure denoting a single directed edge between two vertices
 *        Used for Prims and Kruskal's algorithms
 */
typedef struct Edges {
    int start;
    int end;
    int weight;
} Edges;


void printPrims(GraphMatrix *graph, int start);
int *dijkstras(GraphMatrix *graph, int start);
int find_weight(GraphMatrix *graph, int start, int dest);
int count_edges(GraphMatrix *graph);

void printKruskals(GraphMatrix *graph);


#endif 
/* ifndef ALGORITHMS_H */
