#include <stdio.h>
#include <stdlib.h> //rand(); e srand();
#include <conio.h>
#include "funcoes.h"


int main()
{
//CRIA UMA MATRIZ ALEAT�RIA
    criavetor();
//CRIA AS COORDENADAS LATERAIS DO TABULEIRO
    lc();
//IMPRESS�O DA MATRIZ
    imprimevetor();
//LEITURA DAS COORDENADAS
    leitura();

    return 0;
}
