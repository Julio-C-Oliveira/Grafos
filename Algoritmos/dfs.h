#ifndef DFS
#define DFS

#include "../Base/adjacentListGraph.h"
#include "../Base/adjacentMatrizGraph.h"

typedef struct {
    char color;
    int startTime;
    int endTime;
    int predecessor;
} DFS_AuxiliaryAttributes;

void dfsVisit_list(AdjacentGraph_list* graph, int vertex, DFS_AuxiliaryAttributes* auxiliaryAttibutes, int* timestamp);
void dfs_list(AdjacentGraph_list* graph, int startVertex);

void dfsVisit_matriz(AdjacentGraph_matriz* graph, int vertex, bool visited[]);
void dfs_matriz(AdjacentGraph_matriz* graph, int startVertex);

#endif