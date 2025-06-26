#include "general.h"
#include "libraries.h"

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

    displayGraph_list(adjacentListGraphNaoEuleriano);
    printf("\nNúmero de vértices: %d\n\n", getNumberOfVertices_list(adjacentListGraphNaoEuleriano));
    dfs_list(adjacentListGraphNaoEuleriano, startVertex);
    printf("\n");
    bfs_list(adjacentListGraphNaoEuleriano, startVertex);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_list(adjacentListGraphNaoEuleriano, startVertex, endVertex));
    freeGraph_list(adjacentListGraphNaoEuleriano);

    printf("\nGrafo com matriz de adjacência: ====================================== ||\n");
    AdjacentGraph_matriz* adjacentMatrizGraphNaoEuleriano = createAdjacentGraph_matriz(5, false);

    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 2, 1, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 2, 0, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 1, 0, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 1, 3, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 0, 3, 1);
    addEdge_matriz(adjacentMatrizGraphNaoEuleriano, 3, 4, 1);

    displayGraph_matriz(adjacentMatrizGraphNaoEuleriano);
    printf("Número de vértices: %d\n\n", getNumberOfVertices_matriz(adjacentMatrizGraphNaoEuleriano));
    dfs_matriz(adjacentMatrizGraphNaoEuleriano, 0);
    printf("\n");
    bfs_matriz(adjacentMatrizGraphNaoEuleriano, 0);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_matriz(adjacentMatrizGraphNaoEuleriano, startVertex, endVertex));
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

    displayGraph_list(adjacentListGraphComCicloEuleriano);
    printf("\nNúmero de vértices: %d\n\n", getNumberOfVertices_list(adjacentListGraphComCicloEuleriano));
    dfs_list(adjacentListGraphComCicloEuleriano, 0);
    printf("\n");
    bfs_list(adjacentListGraphComCicloEuleriano, 0);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_list(adjacentListGraphComCicloEuleriano, startVertex, endVertex));
    freeGraph_list(adjacentListGraphComCicloEuleriano);

    printf("\nGrafo com matriz de adjacência: ====================================== ||\n");
    AdjacentGraph_matriz* adjacentMatrizGraphComCicloEuleriano = createAdjacentGraph_matriz(5, false);
    
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 2, 1, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 2, 0, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 1, 0, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 0, 3, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 0, 4, 1);
    addEdge_matriz(adjacentMatrizGraphComCicloEuleriano, 3, 4, 1);

    displayGraph_matriz(adjacentMatrizGraphComCicloEuleriano);
    printf("\nNúmero de vértices: %d\n\n", getNumberOfVertices_matriz(adjacentMatrizGraphComCicloEuleriano));
    dfs_matriz(adjacentMatrizGraphComCicloEuleriano, 0);
    printf("\n");
    bfs_matriz(adjacentMatrizGraphComCicloEuleriano, 0);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_matriz(adjacentMatrizGraphComCicloEuleriano, startVertex, endVertex));
    freeGraph_matriz(adjacentMatrizGraphComCicloEuleriano);


    printf("\n\nCaminho Euleriano ====================================================================================== ||||\n");
    printf("Grafo com lista de adjacência: ====================================== ||\n");
    AdjacentGraph_list* adjacentListGraphComCaminhoEuleriano = createAdjacentGraph_list(5, false);

    addEdge_list(adjacentListGraphComCaminhoEuleriano, 2, 1, 1);
    addEdge_list(adjacentListGraphComCaminhoEuleriano, 2, 0, 1);
    addEdge_list(adjacentListGraphComCaminhoEuleriano, 0, 3, 1);
    addEdge_list(adjacentListGraphComCaminhoEuleriano, 3, 4, 1);

    displayGraph_list(adjacentListGraphComCaminhoEuleriano);
    printf("\nNúmero de vértices: %d\n\n", getNumberOfVertices_list(adjacentListGraphComCaminhoEuleriano));
    dfs_list(adjacentListGraphComCaminhoEuleriano, 0);
    printf("\n");
    bfs_list(adjacentListGraphComCaminhoEuleriano, 0);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_list(adjacentListGraphComCaminhoEuleriano, startVertex, endVertex));
    freeGraph_list(adjacentListGraphComCaminhoEuleriano);

    printf("\nGrafo com matriz de adjacência: ====================================== ||\n");
    AdjacentGraph_matriz* adjacentMatrizGraphComCaminhoEuleriano = createAdjacentGraph_matriz(5, false);
    
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 2, 1, 1);
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 2, 0, 1);
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 0, 3, 1);
    addEdge_matriz(adjacentMatrizGraphComCaminhoEuleriano, 3, 4, 1);

    displayGraph_matriz(adjacentMatrizGraphComCaminhoEuleriano);
    printf("\nNúmero de vértices: %d\n\n", getNumberOfVertices_matriz(adjacentMatrizGraphComCaminhoEuleriano));
    dfs_matriz(adjacentMatrizGraphComCaminhoEuleriano, 0);
    printf("\n");
    bfs_matriz(adjacentMatrizGraphComCaminhoEuleriano, 0);
    printf("\n");
    printf("De %d para %d são necessários %d passos.\n", startVertex, endVertex, bfsCalculateStepSize_matriz(adjacentMatrizGraphComCaminhoEuleriano, startVertex, endVertex));
    freeGraph_matriz(adjacentMatrizGraphComCaminhoEuleriano);
    return 0;
}