
#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

typedef struct Fila{
    char vetor1[50][31];
    char vetor2[50][31];
    int inicio, fim;
}Fila;

Fila *cria_fila();

void pushF(Fila *p, char *pais, char *aux_pais);

void popF(Fila *p, char *pais, char *aux_pais);

#endif // FILAESTATICA_H_INCLUDED
