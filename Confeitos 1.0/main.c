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
//IMPRESSÃO DA MATRIZ
    imprimevetor();
//LEITURA DAS COORDENADAS
    leitura();

    return 0;
}
