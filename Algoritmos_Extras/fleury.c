#include "fleury.h"

/*
Vou me basear nesse pseudo-código:
Entrada: Grafo conexo G = (V, E)
Saída: Um percurso fechado de Euler C

Algoritmo:
Escolher um vértice v qualquer de G; C <- {v}
repita
    Escolher uma aresta (v, w) não marcada via regra da ponte
    atravessar (v,w); C <- C{w}
    Marcar (v,w); v <- w
até todas as arestas estarem marcadas;
C <- C{v}; imprimir C

Regra da Ponte: Se uma aresta (v,w) é uma ponte no grafo induzido pelas arestas não marcadas, 
então (v,w) só deve ser escolhido pelo algoritmo caso não exista qualquer outra opção.
*/

void fleury_list(AdjacentGraph_list* graph, int startVertex) {
    Node_list* currentNode = graph->adjacentList[startVertex];
    while (currentNode != NULL) {
        currentNode = currentNode->next;
    }
}