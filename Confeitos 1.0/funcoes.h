#include <stdio.h>//prinf, scanf...
#include <stdio_ext.h>//__fpurge() LIMPA O BUFFER
#include <stdlib.h>//rand(); e srand();
#include <time.h> //time();
#include <string.h>//strcasemp(); "CASE-INSENSITIVE"
// #include <ctype.h>//isdigit();
// #include <math.h> // abs();

#define CLEAR system("clear");//FUNÇÃO PARA LIMPAR A TELA
#define O 10
#define P 10
FILE *arq;

char confeito, aux;
char tab[O][P];
char sentido[6];
int i, j, r, x, y, m, z, scan, pontos, match;
int mov;
int menu();
int jogada(int x, int y, char sentido[6]);
int mover(int x, int y, char sentido[6]);
int verificatriplahor(void);
int verificatriplaver(void);
int contagem(void);
int desce(void);
int criavetor (void);
int verifica (void);
int leitura (void);
int lc(void);
int imprimevetor(void);
int msg(int m);
int gameover();

