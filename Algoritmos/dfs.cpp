#include "../Base/base.h"
#include <stdio.h>
#include <stdlib.h>

void dfsVisit(Graph* graph, int vertex, char* colors, int* predecessors, int* startTimes, int* endTimes, int* timestamp) {
    colors[vertex] = 1;
    (*timestamp)++;
    startTimes[vertex] = *timestamp;

    Node* temporaryNode = graph->adjacentList[vertex];
    while (temporaryNode) {
        if (colors[temporaryNode->vertex] == 0) {
            predecessors[temporaryNode->vertex] = vertex;
            dfsVisit(graph, temporaryNode->vertex, colors, predecessors, startTimes, endTimes, timestamp);
        }
        temporaryNode = temporaryNode->next;
    }

    (*timestamp)++;
    colors[vertex] = 2;
    endTimes[vertex] = *timestamp;
}

void runDFS(Graph* graph, int startPoint) {
    int numberOfVertices = graph->numberOfVertices;

    char* colors = (char*)calloc(numberOfVertices, sizeof(char));
    int* predecessors = (int*)malloc(numberOfVertices * sizeof(int));

    int* startTimes = (int*)calloc(numberOfVertices, sizeof(int));
    int* endTimes = (int*)calloc(numberOfVertices, sizeof(int));

    for (int i = 0; i < numberOfVertices; i++) 
        predecessors[i] = -1; // Definindo como não visitados

    int timestamp = 0;

    for (int vertex = 0; vertex < numberOfVertices; vertex++) {
        if (colors[vertex] == 0) 
            dfsVisit(graph, vertex, colors, predecessors, startTimes, endTimes, &timestamp);
    }
}