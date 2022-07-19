#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "adjacency_matrix.h"
#include "algorithms.h"


int main(int argc, char *argv[])
{
    // if (argc < 2) {
    //     printf("Too less arguments %d\n", argc);
    //     return -1;
    // }
    GraphMatrix graph;
    init_graph(&graph, "matrix.txt");

    printf("Displaying matrix representation of the graph\n");
    display_graph(&graph);
    printf("\n\n");

    int in = 0, out = 0;
    for (int i = 0; i < graph.vertices; i++) {
        in  = in_degree(&graph, i);
        out = out_degree(&graph, i);
        printf("In  Degree of %d = %d\nOut Degree of %d = %d\n\n", i, in, i, out);
    }
    printf("\n\n");

    for (int i = 0; i < graph.vertices; i++) {
        print_connected_vertices(&graph, i);
    }
    printf("\n\n");

    printf("Is directed: %d\n", is_directed(&graph));
    printf("Is matrix symmetric: %d\n", is_symmetric(&graph));
    printf("\n\n");

    printf("BFS\n");
    BFS(&graph, 0);
    printf("\n\n");

    printf("DFS\n");
    DFS_iter(&graph, 0);
    printf("\n\n");

    printf("DFS\n");
    DFS_rec(&graph, 0);
    printf("\n\n");

    int c = number_of_components(&graph);
    printf("Number of components of graph = %d\n", c);
    printf("\n\n");

    int e = count_edges(&graph);
    printf("Number of edges of graph = %d\n", e);
    printf("\n\n");
 
    printf("Prims\n");
    printPrims(&graph, 0);
    printf("\n\n");
 
    printf("Kruskals\n");
    printKruskals(&graph);
    printf("\n\n");

    printf("Dijkstras\n");
    int *array = dijkstras(&graph, 0);
    for (int i = 0; i < graph.vertices; i++) {
        if (array[i] == INT_MAX) {
            printf("Inf - ");
        } else {
            printf("%d - ", array[i]);
        }
    }
    printf("E\n");
    return 0;
}
