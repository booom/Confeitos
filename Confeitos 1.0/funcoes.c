#include "funcoes.h"
int vl1, vl2, vc1, vc2;
//VETOR COM AS LETRAS DOS "DOCES"
char doce[7]=
{
    'B', 'G', 'R', 'Y', 'W', 'P'
};
//CRIA O VETOR
int criavetor (void)
{
//RANDOMIZAÇÃO DA MATRIZ
    srand(time(NULL)); //Seed com segundos desde 1 Jan 1970, OU SEJA, OS NÚMEROS "NUNCA" TERÃO A MESMA SEQUENCIA. GERA NUMEROS ALEATORIOS
//PEGA AS LETRAS DO VETOR DE DOCES
    for (i=1; i<=O; i++)
    {
        for (j=1; j<=P; j++)
        {
            r = rand() %6;
            tab[i][j] = doce[r];
        }
    }
    return 0;
}
//LÊ AS COORDENADAS E RETORNA O VALOR INTEIRO DE SCAN
int verifica (void)
{
    printf("\nDigite as coordenadas e o sentido para mover a peca. Ex: 8,0, DIR \n");
    scan = scanf("%d, %d, %s", &x,&y, sentido);
    return scan;
}
//LÊ AS COORDENADAS E VERIFICA SE É VALIDO
int leitura (void)
{
    scan = verifica();
    //PARÂMETROS PARA SER VÁLIDO
    if(scan!=3 || x<=0 || y<=0)
    {
        __fpurge(stdin);
        msg(1);
    }
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
            if (tab[i][j]== 'B')
                printf("\033[1;36m");
            else if (tab[i][j]== 'G')
                printf("\033[1;32m");
            else if (tab[i][j]== 'Y')
                printf("\033[1;33m");
            else if (tab[i][j]== 'R')
                printf("\033[1;31m");
            else if (tab[i][j]=='P')
                printf("\033[1;35m");
            else if (tab[i][j]=='W')
                printf("\033[1;37m");

            printf("(%c) ",tab[i][j]);
            printf("\033[1;0m");
        }
        printf("\n\n");
    }
    return 0;
}
//MOVE A PEÇA (OU NÃO)
int mover(int x, int y, char sentido[6])
{
    if (strcasecmp(sentido, "dir")== 0)
    {
        if ((y+1)>9)
            msg(1);
        else
        {

            confeito = tab[x][y+1];
            tab[x][y+1] = tab[x][y];
            tab[x][y] = confeito;
            jogada(x, y+1, sentido);
            msg(0);
        }
    }
    else if (strcasecmp(sentido, "esq")== 0)
    {
        if (y-1<1)
            msg(1);
        else
        {

            confeito = tab[x][y-1];
            tab[x][y-1] = tab[x][y];
            tab[x][y] = confeito;
            jogada(x,y-1, sentido);
            msg(0);
        }
    }
    else if (strcasecmp(sentido, "cima")== 0)
    {
        if (x-1<1)
            msg(1);
        else
        {

            confeito = tab[x-1][y];
            tab[x-1][y] = tab[x][y];
            tab[x][y] = confeito;
            jogada(x-1, y, sentido);
            msg(0);
        }
    }
    else if (strcasecmp(sentido, "baixo")== 0)
    {
        if (x+1>9)
            msg(1);
        else
        {

            confeito = tab[x+1][y];
            tab[x+1][y] = tab[x][y];
            tab[x][y] = confeito;
            jogada(x+1, y, sentido);
            msg(0);
        }
    }
    else
        msg(1);

    return 0;
}
//RETORNA UMA MENSAGEM ACIMA DO TABULEIRO
int msg(int m)
{
    if (m==1)
    {
        CLEAR
        printf("************ MOVIMENTO INVALIDO! TENTE NOVAMENTE: ************\n");
        imprimevetor();
        leitura();
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
    else if (m==4)
    {
        CLEAR
        printf("****************** SWEET! **************\n");
        imprimevetor();
        leitura();
    }
    return 0;

}
//MENU DO JOGO
int menu(void)
{
    int opcao;
    char nome[30];
    printf("*****************************   Confeitos v1.0   ******************************\n");
    printf("\n\n");
    printf("             Seja bem vindo a cidade dos doces! Qual seu nome?\n\n");
    scanf("%[A-Z a-z 0-9]",nome);
    getchar();
    CLEAR;
    printf("*****************************   Confeitos v1.0   ******************************\n");
    printf("\n\n");
    printf("               Ola %s! Esta pronto para uma doce aventura?\n\n                          Digite a opcao desejada:\n",nome);
    printf("\n\n");
    printf("                            1 - Jogar. \n");
    printf("                            2 - Pontuacoes.\n");
    printf("                            3 - Fechar o programa.\n");
    scanf("%i",&opcao);
    if (opcao==1)
    {
        //CRIA UMA MATRIZ ALEATÓRIA
        criavetor();
//VERIFICACAO DAS TRIPLAS PARA NEUTRALIZÃO DO TABULEIRO
        verificatripla();
//CRIA AS COORDENADAS LATERAIS DO TABULEIRO
        lc();
        printf("*************************   Confeitos v1.0   ******************************\n");
        getchar();
        //IMPRESSÃO DA MATRIZ
        imprimevetor();
//LEITURA DAS COORDENADAS
        leitura();
    }
//   else if (opcao==2)
//        tabelapontos();
    else if (opcao==3)
    {
        CLEAR;
        printf("*************************   Confeitos v1.0   ******************************\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("      Voce esta deixando nossa cidade, ate a proxima aventura %s!\n\n",nome);
        printf("\n\n\n\n\n\n\n\n");
        printf("-------------------------- FECHANDO PROGRAMA... ---------------------------\n");
        exit(0);
    }
    else if (opcao>3 || opcao<1)
    {
        printf("*****************  OPCAO INVALIDA! TENTE NOVAMENTE!  *********************");
        return 0;
    }
    CLEAR;
    __fpurge(stdin);
    return 0;
}
//VERIFICA PEÇAS TRIPLAS NO INÍCIO DO JOGO
int verificatripla()
{
    for (i=1; i<10; i++)
    {
        for (j=1; j<8; j++)
        {

            if (tab[i][j]==tab[i][j+2])
            {
                do
                {
                    r = rand() % 6;
                    tab[i][j+2] = doce[r];
                }
                while(tab[i][j+2] == tab[i][j]);

            }

        }
    }
    CLEAR
    return 0;

}

//VERIFICA A JOGADA
int jogada(int x, int y, char sentido[6])
{
    if (tab[x][y] == tab[x][y-2] && tab[x][y] == tab[x][y-1] || tab[x][y+2] && tab[x][y] == tab[x][y+1] || tab[x][y] == tab[x+2][y] && tab[x][y] == tab[x+1][y] || tab[x][y] == tab[x-2][y] && tab[x][y] == tab[x-1][y] || tab[x][y] == tab[x-1][y] && tab[x][y] == tab[x+1][y] )
    {
        i = y;
        while (tab[x][y] == tab[x][i+1])
        {
        tab[x][i+1] = ' ';
        i++;
        }
        i = y;
        while (tab[x][y] == tab[x][i-1])
        {
        tab[x][i-1] = ' ';
        i--;
        }
        i = x;
        while (tab[x][y] == tab[i+1][y])
        {
        tab[i+1][y] = ' ';
        i++;
        }
        i = x;
        while (tab[x][y] == tab[i-1][y])
        {
        tab[i-1][y] = ' ';
        i--;
        }
        tab[x][y] = ' ';
    }
return 0;
}

/*

(P)(P)(P)(P)(P)
 1  2  3  4  5

 2345
 1234

 234
 345
 123

*/

