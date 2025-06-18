#ifndef DFS_H
#define DFS_H

#include "../Base/base.h"

void dfsVisit(Graph* graph, int vertex, char* colors, int* predecessors, int* startTimes, int* endTimes, int timestamp);
void runDFS(Graph* graph, int startPoint);

void dfsForConnectivity(Graph* graph, int vertex, char* visited);
bool isConnect(Graph* graph);

#endif