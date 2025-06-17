#include "../Base/base.h"

int fleury(Graph* graph) {
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
   
    return 1;
}