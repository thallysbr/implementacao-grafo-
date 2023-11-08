#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>

// Define o tipo para peso das arestas
typedef int TIPOPESO;

// Define uma estrutura para as adjacências
typedef struct adjacencia {
    int vertice; // vertice de destino
    TIPOPESO peso; // peso associado à aresta que leva ao vertice de destino
    struct adjacencia *prox; // o próximo elemento da lista de adjacencias
} ADJACENCIA;

// Define uma estrutura para os vértices
typedef struct vertice {
    /* Dados armazenados vão aqui */
    ADJACENCIA *cab; //possui apenas a cabeça da lista de adjacencia
} VERTICE;

// Define a estrutura do grafo
typedef struct grafo {
    //lembrando que cada grafo possui:
    int vertices; // número de vértice total do grafo
    int arestas; // número de arestas totais do grafo
    VERTICE *adj; // Arranjo de vértices da estrutura
} GRAFO;

// Protótipos das funções para manipulação do grafo
GRAFO *criaGrafo(int v);
ADJACENCIA *criaAdj(int v, int peso);
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p);
void imprime(GRAFO *gr);

#endif