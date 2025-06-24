#include "general.h"
#include "Base/adjacentListGraph.h"
#include "Base/adjacentMatrizGraph.h"

int main() {
    printf("Grafo com lista de adjacência:\n");
    AdjacentListGraph* adjacentListGraph = createAdjacentListGraph(5, false);

    addEdge(adjacentListGraph, 2, 1, 1);
    addEdge(adjacentListGraph, 2, 0, 1);
    addEdge(adjacentListGraph, 1, 0, 1);
    addEdge(adjacentListGraph, 1, 3, 1);
    addEdge(adjacentListGraph, 0, 3, 1);
    addEdge(adjacentListGraph, 3, 4, 1);

    displayGraph(adjacentListGraph);
    printf("Número de vértices: %d\n", getNumberOfVertices(adjacentListGraph));
    freeGraph(adjacentListGraph);

    printf("\nGrafo com matriz de adjacência:\n");
    AdjacentMatrizGraph* adjacentMatrizGraph = createAdjacentMatrizGraph(5, false);

    addEdge(adjacentMatrizGraph, 2, 1, 1);
    addEdge(adjacentMatrizGraph, 2, 0, 1);
    addEdge(adjacentMatrizGraph, 1, 0, 1);
    addEdge(adjacentMatrizGraph, 1, 3, 1);
    addEdge(adjacentMatrizGraph, 0, 3, 1);
    addEdge(adjacentMatrizGraph, 3, 4, 1);

    displayGraph(adjacentMatrizGraph);
    printf("Número de vértices: %d\n", getNumberOfVertices(adjacentMatrizGraph));
    freeGraph(adjacentMatrizGraph);
    return 0;
}

/*
    addEdge(grafoNaoEuleriano, 2, 1, 2);
    addEdge(grafoNaoEuleriano, 2, 0, 2);
    addEdge(grafoNaoEuleriano, 1, 0, 2);
    addEdge(grafoNaoEuleriano, 1, 3, 2);
    addEdge(grafoNaoEuleriano, 0, 3, 2);
    addEdge(grafoNaoEuleriano, 3, 4, 2);

    addEdge(grafoComCicloEuleriano, 2, 1, 2);
    addEdge(grafoComCicloEuleriano, 2, 0, 2);
    addEdge(grafoComCicloEuleriano, 1, 0, 2);
    addEdge(grafoComCicloEuleriano, 0, 3, 2);
    addEdge(grafoComCicloEuleriano, 0, 4, 2);
    addEdge(grafoComCicloEuleriano, 3, 4, 2);

    addEdge(grafoComCaminhoEuleriano, 2, 1, 2);
    addEdge(grafoComCaminhoEuleriano, 2, 0, 2);
    addEdge(grafoComCaminhoEuleriano, 0, 3, 2);
    addEdge(grafoComCaminhoEuleriano, 3, 4, 2);
*/