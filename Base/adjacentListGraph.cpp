#include "adjacentListGraph.h"

Node* createNode(int destination, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = destination; // Pra onde essa aresta leva.
    newNode->weight = weight;
    newNode->next = NULL; // Leva pra próxima aresta disponivel no vértice.
    return newNode;
}

AdjacentListGraph* createAdjacentListGraph(int numberOfVertices, bool driven) {
    AdjacentListGraph* graph = (AdjacentListGraph*)malloc(sizeof(AdjacentListGraph));
    graph->numberOfVertices = numberOfVertices;
    graph->driven = driven;

    graph->adjacentList = (Node**)malloc(numberOfVertices*sizeof(Node*));
    for (int i = 0; i < numberOfVertices; i++)
        graph->adjacentList[i] = NULL;

    return graph;
}

void addEdge(AdjacentListGraph* graph, int source, int destination, int weight) {
    Node* newNode = createNode(destination, weight);
    newNode->next = graph->adjacentList[source];
    graph->adjacentList[source] = newNode;

    if (!graph->driven) {
        newNode = createNode(source, weight);
        newNode->next = graph->adjacentList[destination];
        graph->adjacentList[destination] = newNode;
    }
}

void displayGraph(AdjacentListGraph* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++) {
        Node* currentNode = graph->adjacentList[i];
        printf("Vértice %d: ", i);
        while (currentNode) {
            printf("-> %d (peso: %d) ", currentNode->destination, currentNode->weight);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

void freeGraph(AdjacentListGraph* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++) {
        Node* currentNode = graph->adjacentList[i];
        while (currentNode) {
            Node* temporaryNode = currentNode;
            currentNode = currentNode->next;
            free(temporaryNode);
        }
    }
    free(graph->adjacentList);
    free(graph);
}

int getNumberOfVertices(AdjacentListGraph* graph) {
    return graph->numberOfVertices;
}