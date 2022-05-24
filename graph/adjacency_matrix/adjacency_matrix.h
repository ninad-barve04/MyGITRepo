#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX (1)

#define MAX (10)

/**************** Structure typedefs ****************/

/**
 * @brief Graph representation using marix representation 
 */
typedef struct GraphMatrix {
    int vertices;
    int **matrix;
} GraphMatrix;


/**************** Function prototypes ****************/

void init_graph(GraphMatrix *graph, char *filename);
void print_graph(GraphMatrix *graph);

int get_indegree(GraphMatrix *graph, int vertex);
int get_outdegree(GraphMatrix *graph, int vertex);

int print_connected_vertices(GraphMatrix *graph, int vertex);

int is_symmetric(GraphMatrix *graph);
int is_directed(GraphMatrix *graph);

// Breadth first and depth first searches
void BFS(GraphMatrix *graph, int start);
void DFS1(GraphMatrix *graph, int start);
void DFS_R(GraphMatrix *graph, int start, int *visited);
void DFS2(GraphMatrix *graph, int start);

#endif 
/* ifndef ADJACENCY_MATRIX */
