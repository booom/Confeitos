#include <time.h> //time();
#include <math.h> // abs();
#include <string.h>//strcmp();
#include <ctype.h>//isdigit();
#if defined(WINNT)
#define CLEAR system("cls");
#elif defined(LINUX)
#define CLEAR system("CLEAR");
#else
#error "Plataforma Incompatível"
#endif // DEFINE SE É LINUX OU WINDOWS PARA USAR O COMANDO CLEAR
#define O 10
#define P 10
int i, j, r, x, y,m;
char criavetor ();
char imprimevetor();
char tab[O][P];
char sentido[4];
char msg();
char lc();
char mover();
char confeito;



