#include <stdlib.h>
#include <stdio.h>
#include "node.h"

// Criar um Grafo:
Graph* createGraph(int numberOfVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numberOfVertices = numberOfVertices;

    graph->adjacentMatriz = (int**)malloc(numberOfVertices*sizeof(int*));
    for(int i = 0; i < numberOfVertices; i++) {
        graph->adjacentMatriz[i] = (int*)calloc(numberOfVertices, sizeof(int));
    }

    graph->adjacentList = (Node**)malloc(numberOfVertices*sizeof(Node*));
    for(int i = 0; i < numberOfVertices; i++) {
        graph->adjacentList[i] = NULL;
    }

    return graph;
}

// Criar aresta:
void addEdge(Graph* graph, int source, int destination) {
    // Criando uma dupla ligação, para formar a unidirecional.
    graph->adjacentMatriz[source][destination] = 1;
    graph->adjacentMatriz[destination][source] = 1;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = destination;
    newNode->next = graph->adjacentList[source];
    graph->adjacentList[source] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = source;
    newNode->next = graph->adjacentList[destination];
    graph->adjacentList[destination] = newNode;
}

// Calcula o grau de um vértice:
int degree(Graph* graph, int vertex) {
    int degree = 0;
    Node* temporaryNode = graph->adjacentList[vertex];
    while (temporaryNode) {
        degree++;
        temporaryNode = temporaryNode->next;
    }
    return degree;
}

int numberOfVertices(Graph* graph) {
    return graph->numberOfVertices;
}

int numberOfEdges(Graph* graph) {
    int edges = 0;
    for(int i = 0; i < graph->numberOfVertices; i++) {
        Node* temporaryNode = graph->adjacentList[i];
        while (temporaryNode) {
            edges++;
            temporaryNode = temporaryNode->next;
        }
    }
    return edges / 2;
}


// node.cpp
#include <string.h> // para strcat, strlen, etc.

char* adjacencyMatrixToString(Graph* graph) {
    int V = graph->numberOfVertices;

    // Tamanho maximo para a saída
    int maxSize = V * V * 4 + 100;
    char* str = (char*)malloc(maxSize);
    str[0] = '\0';

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            char buffer[10];
            snprintf(buffer, sizeof(buffer), "%d ", graph->adjacentMatriz[i][j]);
            strcat(str, buffer);
        }
        strcat(str, "\n");

    }
    return str;
}

char* adjacencyListToString(Graph* graph) {
    int V = graph->numberOfVertices;

    // Tamanho maximo para saída
    int maxSize = V * V * 10 + 100;
    char* str = (char*)malloc(maxSize);
    str[0] = '\0';

    for(int i = 0; i < V; i++) {
        Node* temporaryNode = graph->adjacentList[i];
        while(temporaryNode) {
            if(temporaryNode->vertex >= i) {
                char buffer[20];
                snprintf(buffer, sizeof(buffer), "(%d, %d)\n", i, temporaryNode->vertex);
                strcat(str, buffer);
            }
            temporaryNode = temporaryNode->next;
        }
    }
    return str;
}
