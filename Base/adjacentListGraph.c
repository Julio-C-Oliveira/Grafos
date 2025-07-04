#include "adjacentListGraph.h"

Node_list* createNode_list(int destination, int weight) {
    Node_list* newNode = (Node_list*)malloc(sizeof(Node_list));
    newNode->destination = destination; // Pra onde essa aresta leva.
    newNode->weight = weight;
    newNode->next = NULL; // Leva pra próxima aresta disponivel no vértice.
    return newNode;
}

AdjacentGraph_list* createAdjacentGraph_list(int numberOfVertices, bool driven) {
    AdjacentGraph_list* graph = (AdjacentGraph_list*)malloc(sizeof(AdjacentGraph_list));
    graph->numberOfVertices = numberOfVertices;
    graph->driven = driven;

    graph->adjacentList = (Node_list**)malloc(numberOfVertices*sizeof(Node_list*));
    for (int i = 0; i < numberOfVertices; i++)
        graph->adjacentList[i] = NULL;

    return graph;
}

void addEdge_list(AdjacentGraph_list* graph, int origin, int destination, int weight) {
    Node_list* newNode = createNode_list(destination, weight);
    newNode->next = graph->adjacentList[origin];
    graph->adjacentList[origin] = newNode;

    if (!graph->driven) {
        newNode = createNode_list(origin, weight);
        newNode->next = graph->adjacentList[destination];
        graph->adjacentList[destination] = newNode;
    }
}

void displayGraph_list(AdjacentGraph_list* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++) {
        Node_list* currentNode = graph->adjacentList[i];
        printf("Vértice %d: ", i);
        while (currentNode != NULL) {
            printf("-> %d (peso: %d) ", currentNode->destination, currentNode->weight);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

void freeGraph_list(AdjacentGraph_list* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++) {
        Node_list* currentNode = graph->adjacentList[i];
        while (currentNode != NULL) {
            Node_list* temporaryNode = currentNode;
            currentNode = currentNode->next;
            free(temporaryNode);
        }
    }
    free(graph->adjacentList);
    free(graph);
}

int getNumberOfVertices_list(AdjacentGraph_list* graph) {
    return graph->numberOfVertices;
}