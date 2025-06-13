#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int main() {
    int numDeVertices = 5;
    Graph* grafo = createGraph(numDeVertices);

    addEdge(grafo, 0, 0);
    addEdge(grafo, 0, 1);
    addEdge(grafo, 0, 4);
    addEdge(grafo, 0, 2);
    addEdge(grafo, 0, 3);

    printf("Quantidade de vertices = %d\n", numberOfVertices(grafo));

    printf("Quantidade de arestas = %d\n", numberOfEdges(grafo));

    char* matriz = adjacencyMatrixToString(grafo);
    printf("Matriz de adjacencias:\n%s", matriz);
    free(matriz);

    char* lista = adjacencyListToString(grafo);
    printf("Lista de adjacencias:\n%s", lista);
    free(lista);

    for(int i = 0; i < numDeVertices; i++) {
        printf("Grau do vertice %d = %d\n", i, degree(grafo, i)); 
    }

    return 0;
}