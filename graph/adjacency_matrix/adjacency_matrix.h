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
void display_graph(GraphMatrix *graph);

int in_degree(GraphMatrix *graph, int vertex);
int out_degree(GraphMatrix *graph, int vertex);

int print_connected_vertices(GraphMatrix *graph, int vertex);

int is_symmetric(GraphMatrix *graph);
int is_directed(GraphMatrix *graph);

// Breadth first and depth first searches
void BFS(GraphMatrix *graph, int start);
void DFS_iter(GraphMatrix *graph, int start);
void DFS_actual_rec(GraphMatrix *graph, int start, int *visited);
void DFS_rec(GraphMatrix *graph, int start);


void BFS_actual(GraphMatrix *graph, int start, int *visited);
int number_of_components(GraphMatrix *graph);

#endif 
/* ifndef ADJACENCY_MATRIX */
