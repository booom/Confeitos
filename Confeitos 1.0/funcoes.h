#include <stdio.h>//prinf, scanf...
#include <stdlib.h>//rand(); e srand();
#include <time.h> //time();
#include <math.h> // abs();
#include <string.h>//strcasemp(); "CASE-INSENSITIVE"
#include <ctype.h>//isdigit();

#define CLEAR system("clear");//FUNÇÃO PARA LIMPAR A TELA
#define O 10
#define P 10

char confeito;
char tab[O][P];
char sentido[6];
int i, j, r, x, y, m, z, scan;
int criavetor ();
int msg();
int lc();
int leitura();
int mover();
int imprimevetor();
int jogada();
int verificatripla();



