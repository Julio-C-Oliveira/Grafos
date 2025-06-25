#include "dfs.h"

void dfsVisit_list(AdjacentGraph_list* graph, int vertex, DFS_AuxiliaryAttributes* auxiliaryAttibutes, int* timestamp) {
    ++(*timestamp);
    auxiliaryAttibutes[vertex].color = GRAY;
    auxiliaryAttibutes[vertex].startTime = (*timestamp); 

    printf("Visitando vértice %d\n", vertex);

    Node_list* currentNode = graph->adjacentList[vertex];
    while (currentNode != NULL) {
        int neighbor = currentNode->destination;
        if (auxiliaryAttibutes[neighbor].color == WHITE) {
            auxiliaryAttibutes[neighbor].predecessor = vertex;
            dfsVisit_list(graph, neighbor, auxiliaryAttibutes, timestamp);
        }
        currentNode = currentNode->next;
    }

    ++(*timestamp);
    auxiliaryAttibutes[vertex].color = BLACK;
    auxiliaryAttibutes[vertex].endTime = (*timestamp);
}

void dfs_list(AdjacentGraph_list* graph, int startVertex) {
    DFS_AuxiliaryAttributes* auxiliaryAttibutes = (DFS_AuxiliaryAttributes*)malloc(graph->numberOfVertices*sizeof(DFS_AuxiliaryAttributes));

    if (!auxiliaryAttibutes) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }

    int timestamp = 0;
    for (int i = 0; i < graph->numberOfVertices; i++) {
        auxiliaryAttibutes[i].color = WHITE;
        auxiliaryAttibutes[i].startTime = NULLNUMBER;
        auxiliaryAttibutes[i].endTime = NULLNUMBER;
        auxiliaryAttibutes[i].predecessor = NULLNUMBER;
    }

    printf("Iniciando DFS com o vértice %d\n", startVertex);

    dfsVisit_list(graph, startVertex, auxiliaryAttibutes, &timestamp);

    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (auxiliaryAttibutes[i].color == WHITE)
            dfsVisit_list(graph, i, auxiliaryAttibutes, &timestamp);
    }

    free(auxiliaryAttibutes);
}

void dfsVisit_matriz(AdjacentGraph_matriz* graph, int vertex, DFS_AuxiliaryAttributes* auxiliaryAttibutes, int* timestamp) {
    ++(*timestamp);
    auxiliaryAttibutes[vertex].color = GRAY;
    auxiliaryAttibutes[vertex].startTime = (*timestamp); 

    printf("Visitando vértice %d\n", vertex);

    for (int neighbor = graph->numberOfVertices - 1; neighbor >= 0; neighbor--) {
        if (graph->adjacentMatriz[vertex][neighbor] != 0 && auxiliaryAttibutes[neighbor].color == WHITE) {
            auxiliaryAttibutes[neighbor].predecessor = vertex;
            dfsVisit_matriz(graph, neighbor, auxiliaryAttibutes, timestamp);
        }
    }

    ++(*timestamp);
    auxiliaryAttibutes[vertex].color = BLACK;
    auxiliaryAttibutes[vertex].endTime = (*timestamp);
}

void dfs_matriz(AdjacentGraph_matriz* graph, int startVertex) {
    DFS_AuxiliaryAttributes* auxiliaryAttibutes = (DFS_AuxiliaryAttributes*)malloc(graph->numberOfVertices*sizeof(DFS_AuxiliaryAttributes));

    if (!auxiliaryAttibutes) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return;
    }

    int timestamp = 0;
    for (int i = 0; i < graph->numberOfVertices; i++) {
        auxiliaryAttibutes[i].color = WHITE;
        auxiliaryAttibutes[i].startTime = NULLNUMBER;
        auxiliaryAttibutes[i].endTime = NULLNUMBER;
        auxiliaryAttibutes[i].predecessor = NULLNUMBER;
    }

    printf("Iniciando DFS com o vértice %d\n", startVertex);

    dfsVisit_matriz(graph, startVertex, auxiliaryAttibutes, &timestamp);

    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (auxiliaryAttibutes[i].color == WHITE)
            dfsVisit_matriz(graph, i, auxiliaryAttibutes, &timestamp);
    }

    free(auxiliaryAttibutes);
}