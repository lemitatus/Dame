#include <stdio.h>
#include <math.h>
#define feld 10
#define frei 254
#define p1 184
#define p2 169
#define SVG_HEIGHT 64
#define SVG_WIDTH 64


int field[9][9];


void svg_start(int width, int height)   /*Beginn der SVG Annimation*/
{
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\"\n");
    printf("     xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n");
    printf("     xmlns:ev=\"http://www.w3.org/2001/xml-events\"\n");
    printf("     version=\"1.1\"\n");
    printf("     baseProfile=\"full\"\n");
    printf("     width=\"%d\"\n", width);
    printf("     height=\"%d\">\n\n", height);
}

void svg_end()  /*Ende der SVG Annimation*/
{
    printf("</svg>\n");
}

void svg_text_number(int x, int y, char Feld) {
  printf("<text x=\"%d\" y=\"%d\">%c</text>\n", x, y, Feld);
}

void hauptmenu ()
{
    int x;
    printf("\nWillkomen zum Spiel Dame! Bitte wählen Sie einen Menüpunkt aus!\n (1) Neues Spiel\n (2) Design\n (3) Beenden ");
    scanf ("%d", &x);
    switch (x)
    {
        case 1:
            spielschleife();
            break;
        case 2:
            design();
            break;
        case 3:
            return;

        default:
            break;
    }

}


void spielschleife()
{
    while (end!=0)
    {
        switch (player)
        {
            case 1:
                spielzug();
                player=2
                break;
            case 2:
                spielzug();
                player=1

            default:
                break;
        }
        if (check_win()>1)
        {
            end=0;
        }
    }
}



int check_win()
{
    int x,y;
    int stein1,stein2;
    int field[x][y];
    for (y=0; y<=10; y++)
    {
        for (x=0; x<=10; x++)
        {
            if (field[x][y]==184)
            {
                stein1=1;
            }
            else if (field[x][y]==169)
            {
                stein2=1;
            }
        }
    }
    if (stein1==0)
    {
        printf("\n Spieler 2 hat gewonnen!");
        return 2;
    }
    else if (stein2==0)
    {
        printf("\n Spieler 1 hat gewonnen!");
        return 1;
    }
    return 0;
}

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
      printf("Feld ausserhalb des bespielbaren Feldes, neuer Versuch!\n");
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
int player;
int end;
svg_start(SVG_HEIGHT, SVG_WIDTH);

hauptmenu();
feldaufbau();

ausgabe_konsole();
ausgabe_bitmap();

spielschleife();
eingabe_konsole();
spielzug();
check_win();

spielfeld();
ausgabe_konsole();
while (end!=0){
  player=1;
  spielzug(player);
  player=2;
  spielzug(player);
}
svg_end();
return 0;
}
