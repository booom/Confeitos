#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
//VETOR COM AS LETRAS DOS "DOCES"
char doce[5]={
    'B', 'G', 'R', 'Y'
};

char criavetor ()
{
//RANDOMIZAÇÃO DA MATRIZ

    srand(time(NULL)); //Seed com segundos desde 1 Jan 1970, OU SEJA, OS NÚMEROS "NUNCA" TERÃO A MESMA SEQUENCIA.

//PEGA AS LETRAS DO VETOR DE DOCES

    for (i=0; i<O; i++)
    {
        for (j=0; j<P; j++)
        {
            r = rand() % 4;
            tab[i][j]= doce[r];
        }
    }
}
//IMPRIME O VETOR NA TELA
char imprimevetor()
{
     for(i=0; i<O; i++)
    {
        for(j=0; j<P; j++)
        {
            printf("%.2c ",tab[i][j]);
        }
        printf("\n");
    }
}
