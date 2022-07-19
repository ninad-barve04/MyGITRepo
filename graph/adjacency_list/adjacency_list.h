/**
 * @file adjacency_list.h
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief header file for adjacency list
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H (1)

/**
 * @brief Structure defining a node in adjacency list
 *        has vertex, weight and pointer to next node in list
 * 
 */
typedef struct graphnode {
    int vertex;
    int weight;
    struct graphnode *next;
} graphnode;

/**
 * @brief Adjacency list structure. contains number of vertices and array of 
 *        pointers to graphnode.
 *        Each node in array denotes a linked list containing all the vertices 
 *        connected to the vertex in array
 * 
 */
typedef struct GraphList {
    int vertices;
    graphnode **node_array;
} GraphList;


void init_graph(GraphList *graph, char const *filename);
void display_graph_list(GraphList *graph);
void display_graph_matrix(GraphList *graph);
int in_degree (GraphList *graph, int node);
int out_degree (GraphList *graph, int node);
int is_directed(GraphList *graph);
void BFS(GraphList *graph, int s);
void DFS_iter(GraphList *graph, int s);
void DFS_rec(GraphList *graph, int s);
void DFS_actual_recursion(GraphList *graph, int s, int *visited);


#endif /* ifndef ADJACENCY_LIST_H */
