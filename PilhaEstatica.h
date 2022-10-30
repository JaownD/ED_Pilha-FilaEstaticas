
#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

typedef struct Pilha{
    char vetor[50][31];
    int topo;
}Pilha;

Pilha *cria_pilha();

void pushP(Pilha *p, char pais[31]);

char *popP(Pilha *p);



#endif // PILHAESTATICA_H_INCLUDED
