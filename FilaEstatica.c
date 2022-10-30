
#include "FilaEstatica.h"

Fila *cria_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = 0;
    return f;
}

void pushF(Fila *f, char *pais, char *aux_pais){
    strcpy(f->vetor1[f->fim], pais);
    strcpy(f->vetor2[f->fim], aux_pais);
    f->fim++;
}

void popF(Fila *f, char *pais, char *aux_pais){
    strcpy(pais, f->vetor1[f->inicio]);
    strcpy(aux_pais, f->vetor2[f->inicio]);
    f->inicio++;
}
