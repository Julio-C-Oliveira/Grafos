#include "adjacentMatrizGraph.h"

AdjacentMatrizGraph* createAdjacentMatrizGraph(int numberOfVertices, bool driven) {
    AdjacentMatrizGraph* graph = (AdjacentMatrizGraph*)malloc(sizeof(AdjacentMatrizGraph));
    graph->numberOfVertices = numberOfVertices;
    graph->driven = driven;

    graph->adjacentMatriz = (int**)malloc(numberOfVertices*sizeof(int*));

    for (int i = 0; i < numberOfVertices; i++)
        graph->adjacentMatriz[i] = (int*)calloc(numberOfVertices, sizeof(int));

    return graph;
}

void addEdge(AdjacentMatrizGraph* graph, int source, int destination, int weight) {
    graph->adjacentMatriz[source][destination] = weight;

    if (!graph->driven)
        graph->adjacentMatriz[destination][source] = weight;
}

void displayGraph(AdjacentMatrizGraph* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++) {
        for (int j = 0; j < graph->numberOfVertices; j++)
            printf("%2d ", graph->adjacentMatriz[i][j]);
        printf("\n");
    }
}

void freeGraph(AdjacentMatrizGraph* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++)
        free(graph->adjacentMatriz[i]);
    free(graph->adjacentMatriz);
    free(graph);
}