#include "funcoes.h"

int main()
{

menu();
//CRIA UMA MATRIZ ALEAT�RIA
    criavetor();
//VERIFICACAO DAS TRIPLAS PARA NEUTRALIZ�O DO TABULEIRO
    verificatripla();
//CRIA AS COORDENADAS LATERAIS DO TABULEIRO
    lc();
    printf("*************************   Confeitos v1.0   ******************************\n");
    getchar();
    //IMPRESS�O DA MATRIZ
    imprimevetor();
    printf("Agora, pressione ENTER para inciar o jogo!\n");
//LEITURA DAS COORDENADAS
    leitura();

    return 0;
}
