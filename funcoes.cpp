#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int TIPOPESO;

// função para criar grafo
GRAFO *criaGrafo (int v) {
    int i;
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v*sizeof(VERTICE));

    for (i=0; i<v; i++){
        g->adj[i].cab=NULL;
    }
    return(g);
}

ADJACENCIA *criaAdj(int v, int peso){
    ADJACENCIA *temp = (ADJACENCIA *) malloc(sizeof(ADJACENCIA)); //aloca espaço para um nó
    temp->vertice = v; //vertice alvo da adjacencia
    temp->peso = peso; //peso da aresta
    temp->prox = NULL;
    return(temp); //retorna endereço da adjacência
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) { //vai de vi a vf
    if(!gr) return (false); //validações se o grafo existe
    if((vf<0)||(vf >= gr->vertices)) return(false); //validações se os valores não são neg
    if((vi<0)||(vf >= gr->vertices)) return(false); //ou maiores que o número de vértice do grafo

    ADJACENCIA *novo = criaAdj(vf,p); //crio adjacencia com o vértice final e o peso
    //coloco a adjacencia na lista do vértice inicial
    novo->prox = gr->adj[vi].cab; //o campo prox da adjacencia vai receber a cabeça da lista
    gr->adj[vi].cab=novo; // e a cabeça da lista passa a ser o novo elemento
    gr->arestas++; // atualizo o número de aresta no grafo
    return (true);
}

void imprime(GRAFO *gr){
    //validações se o grafo existe

    printf("Vertices: %d. Arestas: %d. \n", gr->vertices, gr->arestas); //printo número de vértice
    int i;
    for(i=0; i<gr->vertices; i++){
        printf("V%d: ", i); //Imprimo em qual aresta estou
        ADJACENCIA *ad = gr->adj[i].cab; //chamo a cabeça da lista de adjacencia desta aresta
        while(ad){ //enquanto as adjacencias não forem nula
            printf("v%d(%d) ", ad->vertice, ad->peso); //imprimo a adjacencia e seu peso
            ad=ad->prox; //passo para proxima adjacencia
        }
        printf("\n");
    }
}