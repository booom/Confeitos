#include "funcoes.h"

int main()
{

menu();
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
    printf("Agora, pressione ENTER para inciar o jogo!\n");
//LEITURA DAS COORDENADAS
    leitura();

    return 0;
}
