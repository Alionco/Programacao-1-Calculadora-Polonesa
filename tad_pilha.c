#include <stdio.h>
#include "tad_pilha.h"

void inicializa_pilha(tad_pilha *p) {
    p->topo = 0;
}

int pilha_vazia(tad_pilha *p) {
    if (p->topo == 0) {
        return 1;
    } else {
        return 0;
    }
}

int tamanho_pilha(tad_pilha *p) {
    return p->topo;

}

int empilha(double x, tad_pilha *p) {
    if(p->topo == MAX-1) {
        return 0;
    } else {
        p->vetor[p->topo] = x;
        p->topo++;
        return 1; 
    }
}

int desempilha(double *t, tad_pilha *p) {
    if(p->topo == 0){
        return 0;
    } else {
        *t = p->vetor[p->topo-1];
        p->topo--;
        return 1;
    }
}

int topo(double *t, tad_pilha *p) {
    if(p->topo == 0){
        return 0;
    } else {
        *t = p->vetor[p->topo-1];
        return 1;
    }

}

