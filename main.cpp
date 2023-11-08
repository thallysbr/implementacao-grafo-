#include "funcoes.cpp"
#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(GRAFO *gr) {
    // cria a matriz
    int matriz[gr->vertices][gr->vertices];

    // inicia a matriz com zeros
    for (int i = 1; i < gr->vertices; i++) {
        for (int j = 1; j < gr->vertices; j++) {
            matriz[i][j] = 0;
        }
    }

    // completa a matriz com os pesos das arestas
    for (int i = 1; i < gr->vertices; i++) {
        ADJACENCIA *adj = gr->adj[i].cab; // Obtém a lista de adjacências do vértice

        while (adj != NULL) {
            int destino = adj->vertice;
            int peso = adj->peso;
            if (destino > 0) { // Garante que não acessaremos o índice 0
                matriz[i][destino] = peso;
            }
            adj = adj->prox;
        }
    }

    // Imprime a matriz de adjacência a partir de 1,1
    printf("Matriz de Adjacencia:\n");

    for (int i = 1; i < gr->vertices; i++) {
        for (int j = 1; j < gr->vertices; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimeSomaPesosCaminho(GRAFO *gr, int vi, int vf) {
    if (!gr) {
        printf("Grafo vazio!\n");
        return;
    }
    
    // soma dos pesos no caminho
    int valorTotal = 0;
    // array de vertices visitados
    int visitados[gr->vertices];
    for (int i = 0; i < gr->vertices; i++) {
        // marca todos os vértices como não visitados
        visitados[i] = 0;
    }

    // define o inicio
    int atual = vi;
    // marca como já visitou o 1 (porque parte dele não entra no laço)
    visitados[atual] = 1;

    // Continua a busca até chegar ao vértice 5
    while (atual != vf) {
        ADJACENCIA *adj = gr->adj[atual].cab;
        while (adj) {
            // verifica se o vertice adjacente não foi visitado e está no caminho para o vértice vf
            if (!visitados[adj->vertice]) {
                valorTotal += adj->peso;
                // marca vertice como visitado
                visitados[adj->vertice] = 1;
                atual = adj->vertice;
                // sai do loop
                break;
            }
            adj = adj->prox;
        }
    }

    printf("valor total do caminho de {%d, %d}: %d\n", vi, vf, valorTotal);
}

// Adiciona as arestas com peso para um grafo orientado e ponderado
void adicionaArestaComPeso(GRAFO* gr, int vi, int vf) {
    TIPOPESO peso;
    printf("Entre com o peso para a aresta %d -> %d: ", vi, vf);
    scanf("%d", &peso);
    criaAresta(gr, vi, vf, peso); // Aresta de origem para destino
}

// função principal
int main() {
    // número de vértices no grafo
    int vertices = 5;

    // cria o grafo
    GRAFO *grafo = criaGrafo(vertices + 1);

    // adiciona as arestas e peso
    adicionaArestaComPeso(grafo, 1, 1);
    adicionaArestaComPeso(grafo, 1, 3);
    adicionaArestaComPeso(grafo, 3, 2);
    adicionaArestaComPeso(grafo, 3, 4);
    adicionaArestaComPeso(grafo, 2, 4);
    adicionaArestaComPeso(grafo, 2, 5);
    adicionaArestaComPeso(grafo, 4, 5);

    // imprime a lista com método já criado
    printf("Lista de Adjacencia \n");
    imprime(grafo);

    // imprime a matriz com método novo
    imprimirMatriz(grafo);

    // imprime o valor do caminho grafo
    imprimeSomaPesosCaminho(grafo, 1, 5);

    printf("Aperte um botao para sair");
    system("pause");

    return 0;
}