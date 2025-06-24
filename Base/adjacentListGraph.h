#ifndef ADJACENTLISTGRAPH
#define ADJACENTLISTGRAPH

#include "../general.h"

// Estrutura para o nó da lista de adjacência.
typedef struct Node {
    int destination;
    int weight;
    struct Node* next;
} Node;

// Estrutura do grafo por lista de adjacência.
typedef struct {
    int numberOfVertices;
    bool driven; // Se ele é direcionado ou não.
    Node** adjacentList; // Um array onde cada elemento é um nó.
} AdjacentListGraph;

Node* createNode(int destination, int weight);
AdjacentListGraph* createAdjacentListGraph(int numberOfVertices, bool driven);

void addEdge(AdjacentListGraph* graph, int source, int destination, int weight);
void displayGraph(AdjacentListGraph* graph);
void freeGraph(AdjacentListGraph* graph);

#endif 