#ifndef   ALGORITHMS_H
#define   ALGORITHMS_H (1)

#include "adjacency_list.h"

/**
 * @brief Typedef structure denoting a single directed edge between two vertices
 *        Used for Prims and Kruskal's algorithms
 */
typedef struct Edges {
    int start;
    int end;
    int weight;
} Edges;


void printPrims(GraphList *graph, int start);
int *dijkstras(GraphList *graph, int start);
int find_weight(GraphList *graph, int start, int dest);

void printKruskals(GraphList *graph);


#endif 
/* ifndef ALGORITHMS_H */
