typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int numberOfVertices;
    int** adjacentMatriz;
    Node** adjacentList;
} Graph;

Graph* createGraph(int numberOfVertices); // Cria um Grafo.

void addUnidirectionalEdge(Graph* graph, int source, int destination); // Cria uma aresta unidirecional.
void addBidirectionalEdge(Graph* graph, int source, int destination); // Cria uma aresta bidirecional.
void addEdge(Graph* graph, int source, int destination, int type); // Cria uma aresta.

int degree(Graph* graph, int vertex); // Calcula o grau de um vértice.
int numberOfVertices(Graph* graph); // Pegar o número de vértices.
int numberOfEdges(Graph* graph); // Pegar o número de arestas.


char* adjacencyMatrixToString(Graph* graph);
char* adjacencyListToString(Graph* graph);