#include <time.h> //time();
#include <math.h> // abs();
#include <string.h>//strcmpi(); O I � POR SER "CASE-INSENSITIVE"
#include <ctype.h>//isdigit();

#if defined(WINNT)
#define CLEAR system("cls");
#elif defined(LINUX)
#define CLEAR system("CLEAR");
#else
#error "Plataforma Incompat�vel"
#endif // DEFINE SE � LINUX OU WINDOWS PARA USAR O COMANDO CLEAR

#define O 10
#define P 10
int i, j, r, x, y, m, scan;
char confeito;
char criavetor ();
char tab[O][P];
char sentido[6];
int msg();
int lc();
int leitura();
int mover();
int imprimevetor();
int jogada();



