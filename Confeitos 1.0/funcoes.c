#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
//VETOR COM AS LETRAS DOS "DOCES"
int scan;
char doce[5]=
{
    'B', 'G', 'R', 'Y'
};
char criavetor (void)
{
//RANDOMIZAÇÃO DA MATRIZ
    srand(time(NULL)); //Seed com segundos desde 1 Jan 1970, OU SEJA, OS NÚMEROS "NUNCA" TERÃO A MESMA SEQUENCIA. GERA NUMEROS ALEATORIOS
//PEGA AS LETRAS DO VETOR DE DOCES
    for (i=1; i<=O; i++)
    {
        for (j=1; j<=P; j++)
        {
            r = rand() % 4;
            tab[i][j]= doce[r];
        }
    }
    return 0;
}
int leitura ()
{
    printf("Digite as coordenadas e o sentido para mover a peca. Ex: 8,0, DIR \n");
    scanf("%d, %d, %s", &x,&y, sentido);
    mover(x, y, sentido);
    return 0;
}

//ESCREVE AS COORDENADAS AO REDOR DO VETOR
char lc()
{
    for (i=1; i<O; i++)
    {
        char dig = (char)(((int)'0')+i); // PROCURAR NA INTERNET
        tab[i][0] = dig;
        tab[0][i] = dig;
    }
    tab[0][0] = 'X';
    return 0;
}
//IMPRIME O VETOR NA TELA
char imprimevetor(void)
{
    for(i=0; i<O; i++)
    {
        for(j=0; j<P; j++)
        {
            printf("[%c] ",tab[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}

char mover(int x, int y, char sentido[4])
{
    if (strcmp(sentido, "DIR")== 0)
    {
        if ((y+1)>9)
            m=1;
        else
        {
            m=0;
            confeito = tab[x][y+1];
            tab[x][y+1] = tab[x][y];
            tab[x][y] = confeito;
        }
    }
    else if (strcmp(sentido, "ESQ")== 0)
    {
        if (y-1<1)
            m=1;
        else
        {
            m=0;
            tab[x][y-1]=tab[x][y];
        }
    }
    else if (strcmp(sentido, "CIMA")== 0)
    {
        if (j-1<1)
            m=1;
        else
        {
            m=0;
            tab[x-1][y]=tab[x][y];
        }
    }
    else if (strcmp(sentido, "BAIXO")== 0)
    {
        if (j+1>9)
            m=1;
        else
        {
            m=0;
            tab[x+1][y]=tab[x][y];
        }
    }
    else
        m=1;
    msg(m);
    return 0;
}
char msg(int m)
{
    if (m==1)
    {
        {
            printf("************ MOVIMENTO INVALIDO! TENTE NOVAMENTE: ************\n");
            leitura();
        }
    }
    else if (m==0)
    {
        printf("Peca movida com sucesso!\n");
        imprimevetor();
    }
    else if (m==3)
    {
        printf("****************** ERRO DE SINTAXE, TENTE NOVAMENTE!**************\n");
        leitura();
    }
    return 0;
}

