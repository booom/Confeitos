#include <stdio.h>
#include <stdlib.h> //rand(); e srand();
#include <conio.h>
#include "funcoes.h"


int main()
{
//CRIA UMA MATRIZ ALEATÓRIA
    criavetor();
//CRIA AS COORDENADAS LATERAIS DO TABULEIRO
    lc();
    printf("*************************   Confeitos v1.0   ******************************\n");
    printf("Pressione ENTER para imprimir o tabuleiro!\n");
    getchar();
    //IMPRESSÃO DA MATRIZ
    imprimevetor();
    printf("Agora, pressione ENTER para inciar o jogo!\n");
//LEITURA DAS COORDENADAS
    leitura();

    return 0;
}
