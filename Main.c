#include <stdio.h>
#include <math.h>
#define feld 10




int main () {

hauptmenu();

spielfeld(feld);
feldaufbau();

ausgabe_konsole();
ausgabe_bitmap();

spielschleife();
eingabe_konsole();
spielzug();
check_win();


}
