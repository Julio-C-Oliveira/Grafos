/*
Ciclo Euleriano:
- Todos os vértices que não possuem grau 0 devem fazer parte do mesmo componente conexo. Vértices de grau 0 não afetam o cálculo.
- Todos os vértices do grafo devem possuir grau par.
Caminho Euleriano:
- Todos os vértices que não possuem grau 0 devem fazer parte do mesmo componente conexo. Vértices de grau 0 não afetam o cálculo.
- Somente 0 ou 2 vértices com grau ímpar são permitidos:
    - se nenhum vértice possui grau ímpar -> O ciclo Euleriano existe.
    - se dois vértices possuem grau ímpar -> O caminho Euleriano existe.
    - se um, ou mais que dois vértices possuem grau ímpar -> Não existe em um grafo não direcionado    
Nota: Se um grafo não possui nenhuma aresta ele é um ciclo e um caminho euleriano, pois satisfas as regas.
*/
#include "fleury.h"
#include "dfs.h"
#include <stack>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int findStartVertex(Graph* graph) {
    int startVertex = 0;
    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (degree(graph, i) % 2 != 0) {
            return i;
        }
        if (degree(graph, i) > 0) {
            startVertex = i;
        }
    }
    return startVertex;
}

bool isEulerianCircuit(Graph* graph) {
    if (!isConnect(graph)) return false;
    
    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (degree(graph, i) % 2 != 0) return false;
    }
    return true;
}

bool isEulerianPath(Graph* graph) {
    if (!isConnect(graph)) return false;
    
    int oddCount = 0;
    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (degree(graph, i) % 2 != 0) oddCount++;
    }
    return (oddCount == 0 || oddCount == 2);
}

// Função para contar vértices alcançáveis (DFS)
int countReachableVertices(Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    int count = 1;

    for (int i = 0; i < graph->numberOfVertices; i++) {
        if (graph->adjacentMatriz[v][i] > 0 && !visited[i]) {
            count += countReachableVertices(graph, i, visited);
        }
    }
    return count;
}

// Remove uma aresta do grafo
void removeEdge(Graph* graph, int u, int v) {
    if (graph->adjacentMatriz[u][v] > 0) {
        graph->adjacentMatriz[u][v]--;
        graph->adjacentMatriz[v][u]--;
    }
}

// Verifica se a aresta é válida para o próximo passo
bool isValidNextEdge(Graph* graph, int u, int v) {
    // Se só tem uma aresta, deve pegar essa
    if (degree(graph, u) == 1) {
        return true;
    }

    // Conta vértices alcançáveis antes de remover
    bool* visited = new bool[graph->numberOfVertices]();
    int count1 = countReachableVertices(graph, u, visited);
    
    // Remove a aresta temporariamente
    removeEdge(graph, u, v);
    
    // Conta vértices alcançáveis após remover
    memset(visited, false, graph->numberOfVertices * sizeof(bool));
    int count2 = countReachableVertices(graph, u, visited);
    
    // Restaura a aresta
    graph->adjacentMatriz[u][v]++;
    graph->adjacentMatriz[v][u]++;
    
    delete[] visited;
    
    // Se count1 == count2, não é ponte
    return (count1 == count2);
}

// Cria uma cópia do grafo
Graph* copyGraph(Graph* original) {
    Graph* copy = createGraph(original->numberOfVertices);
    
    for (int i = 0; i < original->numberOfVertices; i++) {
        Node* node = original->adjacentList[i];
        while (node != NULL) {
            addBidirectionalEdge(copy, i, node->vertex);
            node = node->next;
        }
    }
    
    return copy;
}

// Implementação corrigida do Fleury
EulerianPath* fleuryFindEulerianPath(Graph* originalGraph) {
    EulerianPath* result = (EulerianPath*)malloc(sizeof(EulerianPath));
    result->path = NULL;
    result->length = 0;
    
    if (!isEulerianPath(originalGraph)) {
        return result;
    }

    Graph* graph = copyGraph(originalGraph);
    stack<int> vertexStack;
    vector<int> path;
    
    int currentVertex = findStartVertex(graph);
    vertexStack.push(currentVertex);
    
    while (!vertexStack.empty()) {
        currentVertex = vertexStack.top();
        bool foundEdge = false;
        
        // Procura por uma aresta válida
        for (int i = 0; i < graph->numberOfVertices; i++) {
            if (graph->adjacentMatriz[currentVertex][i] > 0) {
                if (isValidNextEdge(graph, currentVertex, i)) {
                    vertexStack.push(i);
                    removeEdge(graph, currentVertex, i);
                    foundEdge = true;
                    break;
                }
            }
        }
        
        if (!foundEdge) {
            path.push_back(currentVertex);
            vertexStack.pop();
        }
    }
    
    // Armazena o resultado
    result->length = path.size();
    result->path = (int*)malloc(result->length * sizeof(int));
    for (int i = 0; i < result->length; i++) {
        result->path[i] = path[result->length - 1 - i];
    }
    
    freeGraph(graph);
    return result;
}

void printEulerianPath(EulerianPath* path) {
    if (path == NULL || path->length == 0) {
        printf("Nenhum percurso euleriano encontrado.\n");
        return;
    }
    
    printf("Percurso Euleriano: ");
    for (int i = 0; i < path->length; i++) {
        printf("%d", path->path[i]);
        if (i < path->length - 1) printf(" -> ");
    }
    printf("\n");
}

void freeEulerianPath(EulerianPath* path) {
    if (path != NULL) {
        if (path->path != NULL) free(path->path);
        free(path);
    }
}
