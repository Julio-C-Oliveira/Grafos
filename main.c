#include "general.h"
#include "libraries.h"

int main() {
    printf("Grafo com lista de adjacência: ====================================== ||\n");
    AdjacentGraph_list* adjacentListGraph = createAdjacentGraph_list(5, false);

    addEdge_list(adjacentListGraph, 2, 1, 1);
    addEdge_list(adjacentListGraph, 2, 0, 1);
    addEdge_list(adjacentListGraph, 1, 0, 1);
    addEdge_list(adjacentListGraph, 1, 3, 1);
    addEdge_list(adjacentListGraph, 0, 3, 1);
    addEdge_list(adjacentListGraph, 3, 4, 1);

    displayGraph_list(adjacentListGraph);
    printf("\nNúmero de vértices: %d\n\n", getNumberOfVertices_list(adjacentListGraph));
    dfs_list(adjacentListGraph, 0);
    printf("\n");
    bfs_list(adjacentListGraph, 0);
    freeGraph_list(adjacentListGraph);

    printf("\nGrafo com matriz de adjacência: ====================================== ||\n");
    AdjacentGraph_matriz* adjacentMatrizGraph = createAdjacentGraph_matriz(5, false);

    addEdge_matriz(adjacentMatrizGraph, 2, 1, 1);
    addEdge_matriz(adjacentMatrizGraph, 2, 0, 1);
    addEdge_matriz(adjacentMatrizGraph, 1, 0, 1);
    addEdge_matriz(adjacentMatrizGraph, 1, 3, 1);
    addEdge_matriz(adjacentMatrizGraph, 0, 3, 1);
    addEdge_matriz(adjacentMatrizGraph, 3, 4, 1);

    displayGraph_matriz(adjacentMatrizGraph);
    printf("Número de vértices: %d\n\n", getNumberOfVertices_matriz(adjacentMatrizGraph));
    dfs_matriz(adjacentMatrizGraph, 0);
    printf("\n");
    bfs_matriz(adjacentMatrizGraph, 0);
    freeGraph_matriz(adjacentMatrizGraph);
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