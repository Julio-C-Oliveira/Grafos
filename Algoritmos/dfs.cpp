#include "dfs.h"
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

void dfsForConnectivity(Graph* graph, int vertex, char* visited) {
    visited[vertex] = 1;

    Node* temporaryNode = graph->adjacentList[vertex];
    while (temporaryNode) {
        if (!visited[temporaryNode->vertex]) {
            dfsForConnectivity(graph, temporaryNode->vertex, visited);
        }
        temporaryNode = temporaryNode->next;
    }
}

void dfsMarkReachable(Graph* graph, int v, bool* visited) {
    visited[v] = true;
    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (graph->adjacentMatriz[v][i] > 0 && !visited[i]) {
            dfsMarkReachable(graph, i, visited);
        }
    }
}


bool isConnect(Graph* graph) {
    bool* visited = (bool*)calloc(graph->numberOfVertices, sizeof(bool));

    // Encontra o primeiro vértice com grau > 0
    int start = -1;
    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (degree(graph, i) > 0) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        // Grafo sem arestas é considerado conexo
        free(visited);
        return true;
    }

    // DFS
    dfsMarkReachable(graph, start, visited);

    // Verifica se todos os vértices com grau > 0 foram visitados
    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (degree(graph, i) > 0 && !visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}
