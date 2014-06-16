#include "funcoes.h"
//VETOR COM AS LETRAS DOS "DOCES"
char doce[7]=
{
    'B', 'G', 'R', 'Y', 'W', 'P'
};
//CRIA O VETOR
int criavetor (void)
{
//RANDOMIZA��O DA MATRIZ
    srand(time(NULL)); //Seed com segundos desde 1 Jan 1970, OU SEJA, OS N�MEROS "NUNCA" TER�O A MESMA SEQUENCIA. GERA NUMEROS ALEATORIOS
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
//L� AS COORDENADAS E RETORNA O VALOR INTEIRO DE SCAN
int verifica (void)
{
    printf("Digite as coordenadas e o sentido para mover a peca. Ex: 8,0, DIR \n");
    scan = scanf("%d, %d, %s", &x,&y, sentido);
    return scan;
}
//L� AS COORDENADAS E VERIFICA SE � VALIDO
int leitura (void)
{
    scan = verifica();
    //PAR�METROS PARA SER V�LIDO
    if(scan!=3 || x<=0 || y<=0)
    {

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
//MOVE A PE�A (OU N�O)
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
            gameover();
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
            gameover();
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
            gameover();
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
            gameover();
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
        printf("**** MOVIMENTO INVALIDO! TENTE DE NOVO ****  Score: %d pontos   Movimentos: %d     \n",pontos,mov);
        imprimevetor();
        __fpurge(stdin);
        leitura();
    }
    else if (m==0)
    {
        CLEAR
        if(match)
            printf("****** PECA MOVIDA COM SUCESSO! *******   Score: %d pontos   Movimentos: %d     \n",pontos,mov);
        else
            printf("************ MULTIPLAS!!! *************   Score: %d pontos   Movimentos: %d     \n",pontos,mov);
        imprimevetor();
        leitura();
    }
    else if (m==4)
    {
        CLEAR
        printf("*******************    GAME OVER!!   *********************\n");
        imprimevetor();
    }
    return 0;
}
//MENU DO JOGO
int menu(void)
{
    int opcao;

    printf("\n\n");
    printf("        Seja bem vindo a cidade dos doces! Insira seu nome (sem acentos!):\n\n");
    z = scanf("%[A-Z a-z 0-9,.]",nome);
    if (z==0)
    {
        printf ("                          Por favor, insira seu nome!");
        __fpurge(stdin);
        CLEAR
        menu();
    }
    CLEAR;
    printf("*****************************   Confeitos v1.0   ******************************\n");
    printf("\n\n");
    printf("               Ola %s! Esta pronto para uma doce aventura?\n\n                          Digite a opcao desejada:\n",nome);
    printf("\n\n");
    printf("                            1 - Jogar modo Match 3 \n");
    printf("                            2 - Jogar modo Saga\n");
    printf("                            3 - Pontuacoes\n");
    printf("                            4 - Instrucoes\n");
    printf("                            5 - Fechar o programa\n");
    scanf("%i",&opcao);
    if (opcao==1)
    {
        mov = 22;
        CLEAR
        match = 1;
        //CRIA UMA MATRIZ ALEAT�RIA
        criavetor();
//VERIFICACAO DAS TRIPLAS PARA NEUTRALIZ�O DO TABULEIRO
        jogada(1,1,"dir");
        pontos = 0;
        verificatriplahor();

//CRIA AS COORDENADAS LATERAIS DO TABULEIRO
        lc();
        printf("*************************   Confeitos v1.0   ******************************\n");
        //IMPRESS�O DA MATRIZ
        imprimevetor();
//LEITURA DAS COORDENADAS
        leitura();
    }
    else if (opcao==2)
    {
        mov = 20;
        CLEAR
        match = 0;
        //CRIA UMA MATRIZ ALEAT�RIA
        criavetor();
//CRIA AS COORDENADAS LATERAIS DO TABULEIRO
        lc();
        printf("*************************   Confeitos v1.0   ******************************\n");
        //IMPRESS�O DA MATRIZ
        imprimevetor();
//LEITURA DAS COORDENADAS
        leitura();
    }
    else if (opcao==3)
    {
        CLEAR
        learquivo();
        getchar();
        menu();
        return 0;
    }
    else if (opcao==4)
    {
        CLEAR
        arq = fopen("instructions", "r");
        if ((aux=fgetc(arq))==EOF)
        {
            printf ("Pressione ENTER para reiniciar\n");
            __fpurge(stdin);
            getchar();
            CLEAR
            menu();
        }
        else
        {
            while ((aux=fgetc(arq))!= EOF)
                putchar (aux);
        }
        return 0;
    }
    else if (opcao==5)
    {
        CLEAR;
        printf("*************************   Confeitos v1.0   ******************************\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("      Voce esta deixando nossa cidade, ate a proxima aventura %s!\n\n",nome);
        printf("\n\n\n\n\n\n\n\n");
        printf("-------------------------- FECHANDO PROGRAMA... ---------------------------\n");
        exit(0);
    }
    else if (opcao>5 || opcao<1)
    {
        printf("*****************  OPCAO INVALIDA! TENTE NOVAMENTE!  *********************");
        return 0;
    }
    CLEAR;
    __fpurge(stdin);
    return 0;
}
//VERIFICA A JOGADA
int jogada(int x, int y, char sentido[6])
{
    if ((tab[x][y] == tab[x][y-2] && tab[x][y] == tab[x][y-1]) || (tab[x][y+2] && tab[x][y] == tab[x][y+1]) || (tab[x][y] == tab[x+2][y] && tab[x][y] == tab[x+1][y])|| (tab[x][y] == tab[x-2][y] && tab[x][y] == tab[x-1][y]) || (tab[x][y] == tab[x-1][y] && tab[x][y] == tab[x+1][y]) )
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
    mov-=1;
    contagem();
    desce();
    return 0;
}
//REMOVE AS DEMAIS PECAS ADJACENTES (FORA DA JOGADA)  DO TABULEIRO
int desce(void)
{
    int desceu =0;
    for (i=9; i>=1; i--)
    {
        for(j=1; j<10; j++)
        {
            if(tab[i][j]==' ')
            {
                if(i == 1)
                {
                    r = rand() % 6;
                    tab[i][j] = doce[r];
                }
                else
                {
                    desceu = 1;
                    tab[i][j] = tab[i-1][j];
                    tab[i-1][j] = ' ';
                }
            }
        }
    }
    if (desceu)
        desce();

    verificatriplahor();
    verificatriplaver();
    return 0;
}
//VERIFICA AS TRIPLAS VERTICAIS
int verificatriplaver(void)
{
    for (j=1; j<10; j++)
    {
        for (i=1; i<8; i++)
        {

            if (tab[i][j]==tab[i+2][j])
            {
                do
                {
                    if (match)
                    {
                        r = rand() % 6;
                        tab[i+2][j] = doce[r];
                    }
                    else
                    {
                        tab[i+2][j] = ' ';
                        contagem();
                        desce();
                    }

                }
                while(tab[i+2][j] == tab[i][j]);
            }
        }
    }
    CLEAR
    return 0;

}
//VERIFICA PE�AS TRIPLAS HORIZONTAIS NO IN�CIO DO JOGO
int verificatriplahor(void)
{
    for (i=1; i<10; i++)
    {
        for (j=1; j<8; j++)
        {

            if (tab[i][j]==tab[i][j+2])
            {
                do
                {
                    if (match)
                    {
                        r = rand() % 6;
                        tab[i][j+2] = doce[r];
                    }
                    else
                    {
                        tab[i][j+2] = ' ';
                        contagem();
                        desce();
                    }
                }
                while(tab[i][j+2] == tab[i][j]);
            }
        }
    }
    CLEAR
    return 0;

}
//CONTA O N�MERO DE ESPA�OS E ADICIONA UM PONTO PARA CADA ESPA�O
int contagem(void)
{
    for (i=1; i<=O; i++)
    {
        for (j=1; j<=P; j++)
        {
            if (tab[i][j]== ' ')
                pontos+=1;
        }

    }
    return 0;
}
//FIM DO JOGO
int gameover(void)
{
    if (mov==0)
    {
        msg(4);
        z = 0;
        arq = fopen("score", "w");

        if (pontos>score[z])
        {
            score[z] = pontos;
            names[z] = nome;
        }
        else if (pontos>score[z+1])
        {
            score[z+1] = pontos;
            names[z+1] = nome;
        }
        else if (pontos>score[z+2])
        {
            score[z+2] = pontos;
            names[z+2] = nome;
        }
        else if (pontos>score[z+3])
        {
            score[z+3] = pontos;
            names[z+3] = nome;
        }
        else if (pontos>score[z+4])
        {
            score[z+4] = pontos;
            names[z+4] = nome;
        }

        for(z=0; z>=6; z++)
        {

            fprintf(arq,"%s",names[z]);
            fprintf(arq,"%d\n", score[z]);
        }


        fclose(arq);

    }

    else
        msg(0);
    return 0;

}

int learquivo(void)
{
    z = 0;
    s = 0;
    cont = 0;
    arq = fopen("score", "r");
    while (fgets(linha, 100, arq))
    {
        cont++;
        if (cont % 2 == 0)
        {
            score[z] = atoi(linha);
            printf("%d\n", score[z]);
            z++;
        }
        else
        {
            names[s] = linha;
            printf("%s",names[s]);
            s++;
        }
    }

    fclose(arq);
    return 0;
}
