#ifndef FLEURY_H
#define FLEURY_H

#include "../Base/base.h"

typedef struct {
    int* path;
    int length;
} EulerianPath;

// Funções auxiliares
int countReachableVertices(Graph* graph, int v, bool visited[]);
bool isValidNextEdge(Graph* graph, int u, int v);
int findStartVertex(Graph* graph);
void removeEdge(Graph* graph, int u, int v);
Graph* copyGraph(Graph* original);

// Funções principais
bool isEulerianCircuit(Graph* graph);
bool isEulerianPath(Graph* graph);
EulerianPath* fleuryFindEulerianPath(Graph* graph);
void printEulerianPath(EulerianPath* path);
void freeEulerianPath(EulerianPath* path);

#endif