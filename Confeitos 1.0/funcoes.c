#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
//VETOR COM AS LETRAS DOS "DOCES"
char doce[7]=
{
    'B', 'G', 'R', 'Y', 'O', 'P'
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
            r = rand() % 6;
            tab[i][j]= doce[r];
        }
    }
    return 0;
}
//LÊ AS COORDENADAS E RETORNA O VALOR INTEIRO DE SCAN
int verifica ()
{
    getchar();
    printf("\nDigite as coordenadas e o sentido para mover a peca. Ex: 8,0, DIR \n");
    scan = scanf("%d, %d, %s", &x,&y, sentido);
    return scan;
}
//LÊ AS COORDENADAS E VERIFICA SE É VALIDO
int leitura ()
{
    scan = verifica();
    //PARÂMETROS PARA SER VÁLIDO
    if(scan!=3 || x<=0 || y<=0)
        msg(1);
    else
    {
     mover(x, y, sentido);
    }

    return 0;
}

//ESCREVE AS COORDENADAS AO REDOR DO VETOR
int lc(void)
{
    for (i=1; i<O; i++)
    {
        char num = (char)(((int)'0')+i); // PROCURAR NA INTERNET
        tab[i][0] = num;
        tab[0][i] = num;
    }
    tab[0][0] = ' ';
    return 0;
}
//IMPRIME O VETOR NA TELA
int imprimevetor(void)
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

int mover(int x, int y, char sentido[6])
{
    if (strcmpi(sentido, "dir")== 0)
    {
        if ((y+1)>9)
            msg(1);
        else
        {
            jogada(x,y+1);
            confeito = tab[x][y+1];
            tab[x][y+1] = tab[x][y];
            tab[x][y] = confeito;
        }
    }
    else if (strcmpi(sentido, "esq")== 0)
    {
        if (y-1<1)
            msg(1);
        else
        {
            jogada(x,y-1);
            confeito = tab[x][y-1];
            tab[x][y-1] = tab[x][y];
            tab[x][y] = confeito;
        }
    }
    else if (strcmpi(sentido, "cima")== 0)
    {
        if (x-1<1)
            msg(1);
        else
        {
            jogada(x-1,y);
            confeito = tab[x-1][y];
            tab[x-1][y] = tab[x][y];
            tab[x][y] = confeito;
        }
    }
    else if (strcmpi(sentido, "baixo")== 0)
    {
        if (x+1>9)
            msg(1);
        else
        {
            jogada(x+1,y);
            confeito = tab[x+1][y];
            tab[x+1][y] = tab[x][y];
            tab[x][y] = confeito;
        }
    }
    else
        msg(1);

    return 0;
}
int msg(int m)
{
    if (m==1)
    {
        {
            CLEAR
            printf("************ MOVIMENTO INVALIDO! TENTE NOVAMENTE: ************\n");
            imprimevetor();
            leitura();
        }
    }
    else if (m==0)
    {
        CLEAR
        printf("********************* PECA MOVIDA COM SUCESSO! *******************\n");
        imprimevetor();
        leitura();
    }
    else if (m==3)
    {
        CLEAR
        printf("****************** ERRO DE SINTAXE, TENTE NOVAMENTE!**************\n");
        imprimevetor();
        leitura();
    }
    return 0;

}
int jogada(int x, int y)
    {
        confeito = tab[x][y];
        if (x==1) // PRIMEIRA LINHA
        {
            if(y>1 && y<9) //PODE VERIFICAR DIREITA, ESQUERDA, BAIXO
                tab;
        }
        tab[x][y];
    }
