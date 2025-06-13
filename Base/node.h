typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int numberOfVertices;
    int** adjacentMatriz;
    Node** adjacentList;
} Graph;

Graph* createGraph(int numberOfVertices); // Criar um Grafo
void addEdge(Graph* graph, int source, int destination); // Criar aresta
int degree(Graph* graph, int vertex); // Calcula o grau de um vértice
int numberOfVertices(Graph* graph); // Pegar o número de vértices
int numberOfEdges(Graph* graph); // Pegar o número de 

// node.h
char* adjacencyMatrixToString(Graph* graph);
char* adjacencyListToString(Graph* graph);
