#include <stdio.h>
#include <stdlib.h>

#include "adjacency_matrix.h"


int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Too less arguments\n");
        return -1;
    }
    GraphMatrix graph;
    
    init_graph(&graph, argv[1]);

    print_graph(&graph);


    print_connected_vertices(&graph, 3);


    BFS(&graph, 1);

    printf("\n\n");

    DFS1(&graph, 1);

    DFS2(&graph, 1);

    return 0;
}
