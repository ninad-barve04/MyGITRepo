#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "astack.h"
#include "adjacency_list.h"


/**
 * @brief Initialize a graph adjacency list from matrix in a text file
 * 
 * @param graph 
 * @param filename textfile name of graph matrix
 */
void init_graph(GraphList *graph, const char *filename) {
    FILE *fp = fopen(filename, "r");

    fscanf(fp, "%d", &(graph->vertices));

    graph->node_array = (graphnode **)malloc(sizeof(graphnode *) * graph->vertices);
    for (int m = 0; m < graph->vertices; m++) {
        graph->node_array[m] = NULL;  
	}
    int edge;

    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            fscanf(fp, "%d", &edge);
            graphnode *newnode = (graphnode *)malloc(sizeof(graphnode));
            newnode->next = NULL;
            if (edge != 0) {
                newnode->vertex = j;
                newnode->weight = edge;
                if (graph->node_array[i] == NULL) {
                    graph->node_array[i] = newnode;
                } else {
                    graphnode *q = graph->node_array[i];
                    while (q->next != NULL) {
                        q = q->next;
                    }
                    q->next = newnode;
                }
            }
        }
    }
    

    return;
}


/**
 * @brief Display the graph in adjacency list format
 * 
 * @param graph 
 */
void display_graph_list(GraphList *graph) {
    graphnode *p = NULL;
    for (int i = 0; i < graph->vertices; i++) {
        p = graph->node_array[i];
        printf("[%d] -> ", i);
        while (p != NULL) {
            printf("(%d, %d) - ", p->vertex, p->weight);
            p = p->next;
        }
        printf("|\n");
    }
    
    return;
}


/**
 * @brief Calculte indegree of vertex
 * 
 * @param graph 
 * @param node vertex
 * @return int 
 */
int in_degree (GraphList *graph, int node) {
    graphnode *p = NULL;
    int count = 0;

    for (int i = 0; i < graph->vertices; i++) {
        p = graph->node_array[i];
        while (p != NULL) {
            if (p->vertex == node) {
                count++;
            }
            p = p->next;
        }
    }
    return count;
}


/**
 * @brief Calculate the out-degree of a vertex
 * 
 * @param graph 
 * @param node vertex
 * @return int 
 */
int out_degree (GraphList *graph, int node) {
    graphnode *p = graph->node_array[node];
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}


/**
 * @brief Check if the graph is directed
 * 
 * @param graph 
 * @return int 1 if directed, else 0
 */
int is_directed(GraphList *graph) {
    graphnode *p = NULL;
    graphnode *q = NULL;    
    int flag = 0;
    for (int i = 0; i < graph->vertices; i++) {
        p = graph->node_array[i];
        while (p != NULL) {
            q = graph->node_array[p->vertex];
            flag = 0;
            while (q != NULL) {
                if (q->vertex == i) {
                    flag = 1; 
                    break;
                }
                q = q->next;
            }
            if (flag == 0) {
                return 1;
            }
            p = p->next;
        }
    }

    return 0;
}


/**
 * @brief Breadth first traversal
 * 
 * @param graph 
 * @param s start vertex
 */
void BFS(GraphList *graph, int s) {
    Queue q;
    init_queue(&q);

    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    if (visited == NULL) {
        return;
    }

    visited[s] = 1;
    enQueue(&q, s);
    graphnode *p = NULL;
    int x;
    while (isEmptyQueue(q) == 0) {
        x = deQueue(&q);
        printf("%d - ", x);
        p = graph->node_array[x];
        while (p != NULL) {
            //printf("p->data = %d\n", p->vertex);
            if (visited[p->vertex] == 0) {
                //printf("Not visited!\n");
                visited[p->vertex] = 1;
                enQueue(&q, p->vertex);
            }
            p = p->next;
        }
    }
    printf("END\n");
    return;
}


/**
 * @brief Iterative depth first traversal using stack
 * 
 * @param graph 
 * @param s start vertex
 */
void DFS_iter(GraphList *graph, int s) {
    Stack stk;
    init_stack(&stk, graph->vertices * 2);

    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    if (visited == NULL) {
        return;
    }

    graphnode *p = NULL;
    int x;

    push(&stk, s);
    visited[s] = 1;

    while (!isEmpty(&stk)) {
        x = pop(&stk);
        printf("%d - ", x);
        visited[x] = 1;
        p = graph->node_array[x];

        while (p != NULL) {
            if (!visited[p->vertex]) {
                visited[p->vertex] = 1;
                push(&stk, p->vertex);
            }
            p = p->next;
        }
        
    }
    printf("END\n");
    return;
}


/**
 * @brief Wrapper function calling recursive depth first traversal to maintain function tempelate
 * 
 * 
 * @param graph 
 * @param s 
 */
void DFS_rec(GraphList *graph, int s) {
    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    if (visited == NULL) {
        return;
    }
    DFS_actual_recursion(graph, s, visited);
    printf("END\n");
    return;
}   


/**
 * @brief Recursive algorithm for Depth first search
 * 
 * @param graph 
 * @param s 
 * @param visited array denoting if the vertex is visted. 1 visited, 0 not visited
 */
void DFS_actual_recursion(GraphList *graph, int s, int *visited) {
    visited[s] = 1;

    printf("%d - ", s);

    graphnode *p = graph->node_array[s];
    while (p != NULL) {
        if (!visited[p->vertex]) {
            DFS_actual_recursion(graph, p->vertex, visited);
        }
        p = p->next;
    }
    return;
}
