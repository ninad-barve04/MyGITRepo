#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "adjacency_list.h"
#include "algorithm.h"


/**
 * @brief Prims algorithm implementation
 * 
 * @param graph pointer to adjacency list implementation object of graph
 * @param start Initial vertex to start prims alorithm
 * @return Edges** pointer to an array of edges forming a minimum spanning tree
 */
Edges **Prims(GraphList *graph, int start) {
    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    if (visited == NULL) {
        return NULL;
    }
    int number = (graph->vertices) - 1;
    Edges **edge_array = (Edges **)malloc(sizeof(Edges *) * number);

    visited[start] = 1;
    
    int min_wt = INT_MAX;

    int ver = 0;

    graphnode *temp = NULL;

    while (ver < (graph->vertices) - 1) {
        Edges *minedge = (Edges *)malloc(sizeof(Edges));
        min_wt = INT_MAX;
        for (int i = 0; i < graph->vertices; i++) {
            if (visited[i]) {
                temp = graph->node_array[i];
                while (temp != NULL) {
                    if (!visited[temp->vertex] && temp->weight < min_wt) {
                        min_wt = temp->weight;
                        minedge->start = i;
                        minedge->end = temp->vertex;
                        minedge->weight = min_wt;
                    }
                    temp = temp->next;
                }
            }
        }
        edge_array[ver] = minedge;
        visited[minedge->end] = 1;
        ver++;
    }

    return edge_array;
}


/**
 * @brief Wrapper function to display contents of edges array in a nice format
 * 
 * @param graph Pointer to graph
 * @param start start vertex to be passed to actual prims call
 */
void printPrims(GraphList *graph, int start) {
    Edges **edgearr = Prims(graph, start);
    for (int i = 0; i < graph->vertices - 1; i++) {
        printf("%d->%d | %d\n", edgearr[i]->start, edgearr[i]->end, edgearr[i]->weight);
    }
    return;
}



/**
 * @brief Helper function to return weight of path from start to dest
 * 
 * @param graph Pointer to graph
 * @param start Start vertex
 * @param dest Destination vertex
 * @return int weight of the path. INT_MAX(infinity) if no path or path 
 *             of intermediate hops not known
 */
int find_weight(GraphList *graph, int start, int dest) {
    int weight = 0;
    if (start == dest) {
        return 0;
    }
    graphnode *p = graph->node_array[start];
    while (p != NULL) {
        if (p->vertex == dest) {
            return p->weight;
        } else {
            p = p->next;
        }
    }

    return INT_MAX;
}


/**
 * @brief Dijkstra's algorithm to find weights of paths to all vertices from start
 * 
 * @param graph pointer to graph
 * @param start start vertex for algorithm
 * @return int* array denoting weights of all vertices from start
 */
int *dijkstras(GraphList *graph, int start) {
    int *visited = (int *)malloc((graph->vertices)* sizeof(int));

    int *weights = (int *)malloc(sizeof(int) * (graph->vertices));

    if (visited == NULL || weights == NULL) {
        printf("Array cannot be initialized! Exiting.\n");
        return NULL;
    }

    for (int i = 0; i < graph->vertices; i++) {
        weights[i] = INT_MAX;
        visited[i]=0;
    }
    
    visited[start] = 1;
    weights[start] = 0;

    graphnode *p = NULL;

    int min_distance, min_vertex;
    int v = start;

    for (int i = 0; i < (graph->vertices) - 1; i++) {
        p = graph->node_array[v];
        min_distance = INT_MAX;
        while (p != NULL) {
            if (p->weight + weights[v] < weights[p->vertex]) {
                weights[p->vertex] = p->weight + weights[v];
            }
            p = p->next;
        }
        
        min_vertex = -1;
        min_distance = INT_MAX;

        for (int j = 0; j < graph->vertices; j++) {
            if (!visited[j] && weights[j] < min_distance) {
                min_vertex = j;
                min_distance = weights[j];
            }
        }
        v = min_vertex;
        visited[v] = 1;
    }

    return weights;
}


/**
 * @brief Count the number of edges in the graph
 * 
 * @param graph pointer to graph
 * @return int number of edges
 */
int count_edges(GraphList *graph) {
    int count = 0;
    graphnode *p = NULL;
    for (int i = 0; i < graph->vertices; i++) {
        p = graph->node_array[i];
        while (p != NULL) {
            p = p->next;
            count++;
        }
    }

    if (is_directed(graph) == 0) {
        count = count/2;
    }

    return count;
}

/**
 * @brief Sort the edges in ascending order by weights
 * 
 * @param graph 
 * @return Edges** pointer to the sorted edge array
 */
Edges **sort_edges(GraphList *graph) {
    Edges **edge_array = (Edges **)malloc(sizeof(Edges *) * count_edges(graph));

    int j = 0;
    graphnode *p = NULL;

    for (int i = 0; i < graph->vertices; i++) {
        p = graph->node_array[i];
        while (p != NULL) {
            Edges *edge = (Edges *)malloc(sizeof(Edges));
            if (i < p->vertex) {
                edge->start = i;
                edge->end = p->vertex;
                edge->weight = p->weight;
                edge_array[j] = edge;
                j++;
            }
            p = p->next;
        }
    }

    int sorted = 0;
    Edges *temp = NULL;
    for (int m = 0; m < graph->vertices - 1; m++) {
        for (int n = 0; n < (graph->vertices) - m - 1; n++) {
            if (edge_array[n]->weight > edge_array[n+1]->weight) {
                temp = edge_array[n];
                edge_array[n] = edge_array[n+1];
                edge_array[n+1] = temp;
            }
        }
    }
    
    return edge_array;
}


/**
 * @brief Kruskal's algorithm implementation
 * 
 * @param graph 
 * @return Edges** MST in an array
 */
Edges **Kruskals(GraphList *graph) {
    Edges **sorted_array = sort_edges(graph);
    Edges **edge_array = (Edges **)malloc(sizeof(Edges *) * (graph->vertices - 1));

    int *set = (int *)malloc(sizeof(int) * (graph->vertices));
    for (int i = 0; i < graph->vertices; i++) {
        set[i] = i;
    }

    int current = 0;
    int m = 0;
    int i = 0;
    while (i < graph->vertices - 1) {
        Edges *current_edge = sorted_array[current];

        if (set[current_edge->start] == set[current_edge->end]) {
            current++;
            continue;
        }

        edge_array[m] = current_edge;
        m++;
        int a;
        if(set[current_edge->end] > set[current_edge->start]) {
            a = set[current_edge->end];
            set[current_edge->end] = set[current_edge->start];
        }
        for (int k = 0; k < graph->vertices; k++) {
            if (set[k] == a) {
                set[k] = set[current_edge->start];
            }
        }
        
        current++;
        i++;
    }

    return edge_array;
}


/**
 * @brief Wrapper function to print the output array of kruskals
 * 
 * @param graph 
 */
void printKruskals(GraphList *graph) {
    Edges **edgearr = Kruskals(graph);
    for (int i = 0; i < graph->vertices - 1; i++) {
        printf("%d->%d | %d\n", edgearr[i]->start, edgearr[i]->end, edgearr[i]->weight);
    }
    return;
}
