#include "general.h"
#include "libraries.h"


void runTest_list(AdjacentGraph_list* graph, int startVertex, int endVertex) {
    displayGraph_list(graph);
    printf("\nNúmero de vértices: %d\n\n", getNumberOfVertices_list(graph));
    dfs_list(graph, startVertex);
    printf("\n");
    bfs_list(graph, startVertex);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_list(graph, startVertex, endVertex));
    printf("\n");
    dfsCycleSearch_list(graph, startVertex);
}

void runTest_matriz(AdjacentGraph_matriz* graph, int startVertex, int endVertex) {
    displayGraph_matriz(graph);
    printf("Número de vértices: %d\n\n", getNumberOfVertices_matriz(graph));
    dfs_matriz(graph, 0);
    printf("\n");
    bfs_matriz(graph, 0);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_matriz(graph, startVertex, endVertex));
    printf("\n");
    dfsCycleSearch_matriz(graph, startVertex);
}

int main() {
    int startVertex = 0; int endVertex = 4;

    printf("Não Euleriano ====================================================================================== ||||\n");
    printf("Grafo com lista de adjacência: ====================================== ||\n");
    AdjacentGraph_list* adjacentListGraphNaoEuleriano = createAdjacentGraph_list(5, false);

    addEdge_list(adjacentListGraphNaoEuleriano, 2, 1, 1);
    addEdge_list(adjacentListGraphNaoEuleriano, 2, 0, 1);
    addEdge_list(adjacentListGraphNaoEuleriano, 1, 0, 1);
    addEdge_list(adjacentListGraphNaoEuleriano, 1, 3, 1);
    addEdge_list(adjacentListGraphNaoEuleriano, 0, 3, 1);
    addEdge_list(adjacentListGraphNaoEuleriano, 3, 4, 1);

    runTest_list(adjacentListGraphNaoEuleriano, startVertex, endVertex);
    freeGraph_list(adjacentListGraphNaoEuleriano);

    printf("\nGrafo com matriz de adjacência: ====================================== ||\n");
    AdjacentGraph_matriz* adjacentMatrizGraphNaoEuleriano = createAdjacentGraph_matriz(5, false);

    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 2, 1, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 2, 0, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 1, 0, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 1, 3, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 0, 3, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 3, 4, 1);

    runTest_matriz(adjacentMatrizGraphNaoEuleriano, startVertex, endVertex);
    freeGraph_matriz(adjacentMatrizGraphNaoEuleriano);

    printf("\n\nCiclo Euleriano ====================================================================================== ||||\n");
    printf("Grafo com lista de adjacência: ====================================== ||\n");
    AdjacentGraph_list* adjacentListGraphComCicloEuleriano = createAdjacentGraph_list(5, false);
    
    addEdge_list(adjacentListGraphComCicloEuleriano, 2, 1, 1);
    addEdge_list(adjacentListGraphComCicloEuleriano, 2, 0, 1);
    addEdge_list(adjacentListGraphComCicloEuleriano, 1, 0, 1);
    addEdge_list(adjacentListGraphComCicloEuleriano, 0, 3, 1);
    addEdge_list(adjacentListGraphComCicloEuleriano, 0, 4, 1);
    addEdge_list(adjacentListGraphComCicloEuleriano, 3, 4, 1);

    runTest_list(adjacentListGraphComCicloEuleriano, startVertex, endVertex);
    freeGraph_list(adjacentListGraphComCicloEuleriano);

    printf("\nGrafo com matriz de adjacência: ====================================== ||\n");
    AdjacentGraph_matriz* adjacentMatrizGraphComCicloEuleriano = createAdjacentGraph_matriz(5, false);
    
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 2, 1, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 2, 0, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 1, 0, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 0, 3, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 0, 4, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 3, 4, 1);

    runTest_matriz(adjacentMatrizGraphComCicloEuleriano, startVertex, endVertex);
    freeGraph_matriz(adjacentMatrizGraphComCicloEuleriano);


    printf("\n\nCaminho Euleriano ====================================================================================== ||||\n");
    printf("Grafo com lista de adjacência: ====================================== ||\n");
    AdjacentGraph_list* adjacentListGraphComCaminhoEuleriano = createAdjacentGraph_list(5, false);

    addEdge_list(adjacentListGraphComCaminhoEuleriano, 2, 1, 1);
    addEdge_list(adjacentListGraphComCaminhoEuleriano, 2, 0, 1);
    addEdge_list(adjacentListGraphComCaminhoEuleriano, 0, 3, 1);
    addEdge_list(adjacentListGraphComCaminhoEuleriano, 3, 4, 1);

    runTest_list(adjacentListGraphComCaminhoEuleriano, startVertex, endVertex);
    freeGraph_list(adjacentListGraphComCaminhoEuleriano);

    printf("\nGrafo com matriz de adjacência: ====================================== ||\n");
    AdjacentGraph_matriz* adjacentMatrizGraphComCaminhoEuleriano = createAdjacentGraph_matriz(5, false);
    
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 2, 1, 1);
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 2, 0, 1);
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 0, 3, 1);
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 3, 4, 1);

    runTest_matriz(adjacentMatrizGraphComCaminhoEuleriano, startVertex, endVertex);
    freeGraph_matriz(adjacentMatrizGraphComCaminhoEuleriano);
    return 0;
}