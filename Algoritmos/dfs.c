#include "dfs.h"

void dfsVisit_list(AdjacentGraph_list* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("Visitando vértice %d\n", vertex);

    Node_list* currentNode = graph->adjacentList[vertex];
    while (currentNode != NULL) {
        int neighbor = currentNode->destination;
        if (!visited[neighbor])
            dfsVisit_list(graph, neighbor, visited);
        currentNode = currentNode->next;
    }
}

void dfs_list(AdjacentGraph_list* graph, int startVertex) {
    bool* visited = (bool*)calloc(graph->numberOfVertices, sizeof(bool));

    if (!visited) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }

    printf("Iniciando DFS com o vértice %d\n", startVertex);
    dfsVisit_list(graph, startVertex, visited);

    free(visited);
}

void dfsVisit_matriz(AdjacentGraph_matriz* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("Visitando vértice %d\n", vertex);

    for (int neighbor = graph->numberOfVertices - 1; neighbor >= 0; neighbor--) {
        if (graph->adjacentMatriz[vertex][neighbor] != 0 && !visited[neighbor])
            dfsVisit_matriz(graph, neighbor, visited);
    }
}

void dfs_matriz(AdjacentGraph_matriz* graph, int startVertex) {
    bool* visited = (bool*)calloc(graph->numberOfVertices, sizeof(bool));

    if (!visited) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }

    printf("Iniciando DFS com o vértice %d\n", startVertex);
    dfsVisit_matriz(graph, startVertex, visited);

    free(visited);
}