#ifndef BFS
#define BFS

#include "../Base/adjacentListGraph.h"
#include "../Base/adjacentMatrizGraph.h"

#include "defines.h"

#include <limits.h>

typedef struct {
    char color;
    int distance;
    int predecessor;
} BFS_AuxiliaryAttributes;

void bfs_list(AdjacentGraph_list* graph, int startVertex);
void bfs_matriz(AdjacentGraph_matriz* graph, int startVertex);

#endif