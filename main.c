#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PilhaEstatica.h"
#include "FilaEstatica.h"
#define MAX 31

/*
    -->Pesquisar sobre free(retirado) e free(aux_retirado)

*/




int main(){
    int quant_time, quant_pote, i, j = 0, k = 0, aux_pote, tam_def = 0, aux_tam, aux, placar, aux_placar;
    char pais[MAX], aux_pais[MAX], pais_passou[MAX];
    char *retirado, *aux_retirado;
    Fila *f = cria_fila();
    Fila *f_pos = cria_fila();
    Pilha *p_ranking = cria_pilha();

    scanf("%d %d", &quant_time, &quant_pote);

    Pilha **potes = (Pilha**)malloc(quant_pote*sizeof(Pilha*));

    for(i = 0; i < quant_pote; i++)
        potes[i] = cria_pilha();

    for(i = 0; i < quant_time; i++){
        if(j == quant_pote)
            j = 0;
        scanf("%s", pais);
        pushP(potes[j], pais);
        aux_tam = strlen(pais);
        if(aux_tam > tam_def)
            tam_def = aux_tam;
        j++;
    }



///Passando para a fila
    for(i = 0; i < quant_time/2; i++){
        j = k + 1;

        if(j == quant_pote)
            j = 0;
        retirado = popP(potes[k]);
        aux_retirado = popP(potes[j]);
        printf("\nRetirado: %s  Aux_retirado: %s\n", retirado, aux_retirado);

        k = j + 1;
        if(k == quant_pote)
            k = 0;
        pushF(f, retirado, aux_retirado);
        printf("Aqui");
        //free(aux_retirado);
        //free(retirado);
    }

///Fila iniacial
    printf("\nFila inicial:\n");
    for(i = 0; i < quant_time/2; i++){
        popF(f, retirado, aux_retirado);

        pushF(f_pos, retirado, aux_retirado);
        aux_tam = strlen(retirado);
        aux = tam_def;
        while((aux + 3) != aux_tam){
            printf(" ");
            aux--;
        }
        printf("%s x %s\n", retirado, aux_retirado);
    }


///Disputas
    srand(time(0));
    for(i = 0; i < quant_time/2; i++){
        if(i == ((quant_time/2) - 1))
            printf("\nGrande final: \n");
        else
            printf("\nDia %d: \n", i + 1);
        for(j = 0; j < 2; j++){
            popF(f_pos, retirado, aux_retirado);

            placar = rand() %8;
            aux_placar = rand() %8;
            while(placar == aux_placar){
                placar = rand() %8;
                aux_placar = rand() %8;
            }
            aux_tam = strlen(pais);
            aux = tam_def;
            while((aux + 4) != aux_tam){
                printf(" ");
                aux--;
            }
            printf("%s %d x %d %s\n", retirado, placar, aux_placar, aux_retirado);
            if(i == ((quant_time/2) - 1)){
                if(placar > aux_placar){
                    pushP(p_ranking, aux_retirado);
                    pushP(p_ranking, retirado);
                }
                else{
                    pushP(p_ranking, retirado);
                    pushP(p_ranking, aux_retirado);
                }
                break;
            }
            else if(j == 0){
                if(placar > aux_placar){
                    pushP(p_ranking, aux_retirado);
                    strcpy(pais_passou, retirado);
                }
                else{
                    pushP(p_ranking, retirado);
                    strcpy(pais_passou, aux_retirado);
                }
            }
            else{
                if(placar > aux_placar){
                    pushP(p_ranking, aux_retirado);
                    pushF(f_pos, pais_passou, retirado);
                }
                else{
                    pushP(p_ranking, retirado);
                    pushF(f_pos, pais_passou, aux_retirado);
                }
            }
        }
    }

///Ranking
    printf("\n");
    for(i = 0; i < quant_time; i++){
        retirado = popP(p_ranking);
        if(i == 0){
            for(j = 0; j < 2; j++)
                printf(" ");
            printf("Campeao: %s\n", retirado);
        }
        else if(i == 1){
            for(j = 0; j < 5; j++)
                printf(" ");
            printf("Vice: %s\n", retirado);
        }
        else if(i < 9)
            printf(" %do lugar: %s\n", i + 1, retirado);
        else
            printf("%do lugar: %s\n", i + 1, retirado);
        //free(retirado);
    }


///Desalocando memoria
    for(i = 0; i < quant_pote; i++)
        free(potes[i]);
    free(potes);
    free(p_ranking);
    free(f);
    free(f_pos);

    return 0;
}
