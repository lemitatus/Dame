#include <stdio.h>
#include <math.h>
#define feld 10
#define frei 254
#define p1 184
#define p2 169

int field[9][9];

void spielfeld(){

int x, y, e,i;
i=1;

for (y=1; y<=8; y++){       /* Buchstaben setzen */
  x=0;
  field[x][y]=(64+y);
  }

for (x=1; x<=8; x++){       /* Zahlen setzen */
  y=0;
  field[x][y]=(48+x);
  }
for(y=1; y<=8; y++){
  for (x=1; x<=8; x++){
    e=i%2;                          /* Abwechselndes setzen von Spielfeldfarben */
    i++;
    if (e == 1)
      field[x][y]=88;             /* 88 = 'X' -- 254 = 'Quadrat' */
    else
      field[x][y]=254;
  }
    i++;                                    /* Versatz der Z�hlervariable um 1 pro Druchlauf */
  }

}/*void Spielfeld*/
void ausgabe_konsole(){

int x, y;

for (y=0; y<=8; y++){                   /* Ausgabe des Arrays mit ASCII-Variablen */
  for (x=0; x<=8; x++){
    printf("%c ", field[x][y]);
  }
    printf("\n");
}

}/*void ausgabe_konsole*/


void spielzug(int player) {

  int start_1, ziel_1;
  char start_a, ziel_a;
  int start_a_i, ziel_a_i;

    printf("Spielstein waehlen\n");
    int go=1;

    while (go!=0) { //Spielstein?
      scanf("%c %d",&start_a ,&start_1);//Buchstabe Zahl
      start_a_i=start_a-96; //Buchstabe in Koordinatenzahl umgerechnet

      if (player == 1 && field [start_a_i][start_1]==p1) {
        go=1;
      }
      else if (player == 2 && field [start_a_i][start_1]==p2) {
        go=1;
      }
      else
      printf("Ausgewaehltes Feld enthaelt nicht ihren Spielstein, bitte neues Feld aussuchen\n");
      }//while go

    printf("Zielsposition waehlen\n");
    go=1;

    while (go!=0) { /*so lange Zielfeld waehlen, bis Zug moeglich ist*/
    scanf("%c %d",&ziel_a ,&ziel_1);
    ziel_a_i=ziel_a-96; //Buchstabe in Koordinatenzahl umgerechnet
    int check=(ziel_a_i+ziel_1) % 2;//Feldwerte addiert muss ungerade sein

    if (check!=0 || ziel_a_i<8 || ziel_1<8){//außerhalb oder wißes Feld
      printf("Feld ausserhalb des bespielbaren Feldes, neuer Versuch!\n", );
    }

    if (player==1 && field [ziel_a_i][ziel_1]==frei){ //gegenchecken richtiges leeres feld?...einfacher, möglicher Zug
      if (ziel_1==start_1+1 && ziel_a_i==start_a_i+1){
        field [ziel_a_i][ziel_1]=p1;
        field [start_a_i][start_1]=frei;
        go=1;
      }
      else if (ziel_1==start_1-1 && ziel_a_i==start_a_i+1){
        field [ziel_a_i][ziel_1]=p1;
        field [start_a_i][start_1]=frei;
        go=1;
      }
    }//if player1

    if (player==2 && field [ziel_a_i][ziel_1]==frei){ //gegenchecken richtiges leeres feld?...einfacher, möglicher Zug
      if (ziel_1==start_1+1 && ziel_a_i==start_a_i-1){
        field [ziel_a_i][ziel_1]=p2;
        field [start_a_i][start_1]=frei;
        go=1;
      }
      else if (ziel_1==start_1-1 && ziel_a_i==start_a_i-1){
        field [ziel_a_i][ziel_1]=p2;
        field [start_a_i][start_1]=frei;
        go=1;
      }
    }//if player2

    if (player==1 && field [ziel_a_i][ziel_1]==p2){ //Treffer
      if (ziel_1==start_1+1 && ziel_a_i==start_a_i+1 && field [ziel_a_i+1][ziel_1+1]==frei){//rechts unten
        field [ziel_a_i][ziel_1]=frei;
        field [start_a_i][start_1]=frei;
        field [ziel_a_i+1][ziel_1+1]=p1;
        printf("Weiterer Zug? Ja=1 Nein=0\n");
        int a;
        scanf("%d",&a);
        if (a==1)
          spielzug(player);
        else
        go=1;
      }
      else if (ziel_1==start_1-1 && ziel_a_i==start_a_i+1 && field [ziel_a_i+1][ziel_1-1]==frei){//links unten
        field [ziel_a_i][ziel_1]=frei;
        field [start_a_i][start_1]=frei;
        field [ziel_a_i+1][ziel_1-1]=p1;
        printf("Weiterer Zug? Ja=1 Nein=0\n");
        int a;
        scanf("%d",&a);
        if (a==1)
          spielzug(player);
        else
        go=1;
      }
    }//if player1

    if (player==2 && field [ziel_a_i][ziel_1]==p1){ /*Treffer*/
      if (ziel_1==start_1+1 && ziel_a_i==start_a_i-1 && field [ziel_a_i-1][ziel_1+1]==frei){ /*rechts oben */
        field [ziel_a_i][ziel_1]=frei;
        field [start_a_i][start_1]=frei;
        field [ziel_a_i-1][ziel_1+1]=p2;
        printf("Weiterer Zug? Ja=1 Nein=0\n");
        int a;
        scanf("%d",&a);
        if (a==1)
          spielzug(player);
        else
        go=1;
      }
      else if (ziel_1==start_1-1 && ziel_a_i==start_a_i-1 && field [ziel_a_i-1][ziel_1-1]==frei){ /*links oben */
        field [ziel_a_i][ziel_1]=frei;
        field [start_a_i][start_1]=frei;
        field [ziel_a_i-1][ziel_1-1]=p2;
        printf("Weiterer Zug? Ja=1 Nein=0\n");
        int a;
        scanf("%d",&a);
        if (a==1)
          spielzug(player);
        else
        go=1;
      }
    }//if player2
  }/*while go Ziel*/
}/*void spielzug*/


int main () {

/*hauptmenu();


feldaufbau();


ausgabe_bitmap();

spielschleife();
eingabe_konsole();
spielzug();
check_win();
*/
spielfeld();
ausgabe_konsole();
while (end!=0){
  player=1;
  spielzug(player);
  player=2;
  spielzug(player);
}


free(field);
return 0;
}
