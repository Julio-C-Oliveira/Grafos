#ifndef ADJACENTMATRIZGRAPH
#define ADJACENTMATRIZGRAPH

#include "../general.h"

// Estrutura do grafo por matriz de adjacência.
typedef struct {
    int numberOfVertices;
    bool driven;
    int** adjacentMatriz;
} AdjacentMatrizGraph;

AdjacentMatrizGraph* createAdjacentMatrizGraph(int numberOfVertices, bool driven);
void addEdge(AdjacentMatrizGraph* graph, int source, int destination, int weight);
void displayGraph(AdjacentMatrizGraph* graph);
void freeGraph(AdjacentMatrizGraph* graph);

#endif 