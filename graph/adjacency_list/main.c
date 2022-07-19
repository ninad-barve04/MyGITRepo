/**
 * @file main.c
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief Main function for adjacency list implementation of graph
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#include "adjacency_list.h"
#include "algorithm.h"

int main(int argc, char const *argv[])
{
    GraphList graph;
    init_graph(&graph, argv[1]);
    
    printf("Displaying linked list representation of the graph\n");
    display_graph_list(&graph);
    printf("\n\n");

    // printf("Displaying matrix representation of the graph\n");
    // display_graph_matrix(&graph);
    // printf("\n\n");

    int in = 0, out = 0;
    for (int i = 0; i < graph.vertices; i++) {
        in  = in_degree(&graph, 3);
        out = out_degree(&graph, 3);
        printf("In Degree of %d  = %d\nOut Degree of %d = %d\n", i, in, i, out);
    }
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

    printf("Prims\n");
    printPrims(&graph, 0);
    printf("\n\n");

    printf("Kruskals\n");
    printKruskals(&graph);
    printf("\n\n");

    printf("Dijkstras\n");
    int *array = dijkstras(&graph, 0);
    for (int i = 0; i < graph.vertices; i++) {
        printf("%d - ", array[i]);
    }
    printf("E\n");
    return 0;
}
