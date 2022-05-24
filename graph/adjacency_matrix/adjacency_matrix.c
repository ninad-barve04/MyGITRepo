#include <stdio.h>
#include <stdlib.h>

#include "adjacency_matrix.h"
#include "queue.h"
#include "astack.h"

void init_graph(GraphMatrix *graph, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file\n");
        return;
    }
    int x;
    fscanf(fp, "%d", &x);
    graph->vertices = x;

    /* Allocating memory for matrix */
    graph->matrix = (int **)malloc(sizeof(int *) * x);
    for (int m = 0; m < x; m++) {
        graph->matrix[m] = (int *)malloc(sizeof(int) * x);
    }
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            fscanf(fp, "%d", &(graph->matrix[i][j]));
        }
        
    }
}


void print_graph(GraphMatrix *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

int get_indegree(GraphMatrix *graph, int vertex) {
    int ideg = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[i][vertex]) {
            ideg++;
        }
    }
    return ideg;
}

int get_outdegree(GraphMatrix *graph, int vertex) {
    int odeg = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[vertex][i]) {
            odeg++;
        }
    }
    return odeg;
}

int print_connected_vertices(GraphMatrix *graph, int vertex) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[i][vertex]) {
            printf("Connected %d <=> %d\n", i, vertex);
        }
        if (graph->matrix[vertex][i]) {
            printf("Connected %d <=> %d\n", vertex, i);
        }
    }
}

int is_directed(GraphMatrix *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->matrix[i][j] != graph->matrix[j][i]) {
                return 1;
            }
        }
    }
    return 0;
}

int is_symmetric(GraphMatrix *graph) {
    return !is_directed(graph);
}


void BFS(GraphMatrix *graph, int start) {
    /* 
     * Code for traversal
     * a) enqueue vertex
     * b) mark S as visited
     * c) print on screen
     * d) enqueue all edges connected S
     * e) for all unvisited loops, again loop b)
     */

    Queue q;
    init_queue(&q);

    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    int v;
    enQueue(&q, start);
    visited[start] = 1;
    printf("%d - ", start);

    while (!isEmptyQueue(q)) {
        v = deQueue(&q);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[v][i] && !visited[i]) {
                enQueue(&q, i);
                visited[i] = 1;
                printf("%d - ", i);
            }
        }
    }

    printf("END\n");
    return;
}


int count_components(GraphMatrix *graph) {

}


void DFS1(GraphMatrix *graph, int start) {
    Stack s;
    init_stack(&s, graph->vertices);

    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    int v;

    printf("%d - ", start);
    push(&s, start);
    visited[start] = 1;
    while(!isEmpty(&s)) {
        v = pop(&s);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[v][i] && !visited[i]) {
                push(&s, i);
                visited[i] = 1;
                printf("%d - ", i);
            }
        }
    }


    printf("END\n");
    return;
}


void DFS_R(GraphMatrix *graph, int start, int *visited) {
    visited[start] = 1;

    printf("%d - ", start);

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[start][i] && !visited[i]) {
            DFS_R(graph, i, visited);
        }
    }

    return;
}


void DFS2(GraphMatrix *graph, int start) {
    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    DFS_R(graph, start, visited);
    printf("END\n");
    return;
}