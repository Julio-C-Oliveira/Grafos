#include <stdlib.h>
#include <stdio.h>
#include "Base/base.h"
#include "Algoritmos/dfs.h"

int main() {
    /*
    // Testando a base do grafo:
    int numDeVertices = 5;
    Graph* grafo = createGraph(numDeVertices);

    addEdge(grafo, 0, 0, 1);
    addEdge(grafo, 0, 1, 2);
    addEdge(grafo, 0, 4, 2);
    addEdge(grafo, 0, 2, 2);
    addEdge(grafo, 0, 3, 2);
    addEdge(grafo, 4, 4, 1);
    addEdge(grafo, 4, 1, 2);
    addEdge(grafo, 4, 2, 2);
    addEdge(grafo, 4, 3, 2);

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
    */
    
    // Testando o Algoritmo de Fleury:
    int numDeVertices = 5;
    Graph* grafoNaoEuleriano = createGraph(numDeVertices); // A saída deve ser 0 para informar que não existe um caminho euleriano.
    Graph* grafoComCicloEuleriano = createGraph(numDeVertices); // A saída deve ser 2 para informar que existe um ciclo euleriano.
    Graph* grafoComCaminhoEuleriano = createGraph(numDeVertices); // A saída deve ser 1 para informar que existe um caminho euleriano, mas não é um ciclo.

    addEdge(grafoNaoEuleriano, 2, 1, 2);
    addEdge(grafoNaoEuleriano, 2, 0, 2);
    addEdge(grafoNaoEuleriano, 1, 0, 2);
    addEdge(grafoNaoEuleriano, 1, 3, 2);
    addEdge(grafoNaoEuleriano, 0, 3, 2);
    addEdge(grafoNaoEuleriano, 3, 4, 2);

    addEdge(grafoComCicloEuleriano, 2, 1, 2);
    addEdge(grafoComCicloEuleriano, 2, 0, 2);
    addEdge(grafoComCicloEuleriano, 1, 0, 2);
    addEdge(grafoComCicloEuleriano, 0, 3, 2);
    addEdge(grafoComCicloEuleriano, 0, 4, 2);
    addEdge(grafoComCicloEuleriano, 3, 4, 2);

    addEdge(grafoComCaminhoEuleriano, 2, 1, 2);
    addEdge(grafoComCaminhoEuleriano, 2, 0, 2);
    addEdge(grafoComCaminhoEuleriano, 0, 3, 2);
    addEdge(grafoComCaminhoEuleriano, 3, 4, 2);

    runDFS(grafoComCicloEuleriano, 0);
    return 0;
}