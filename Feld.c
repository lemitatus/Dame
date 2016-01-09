#include <stdio.h>
#include <math.h>


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
/*
    field[0][0]=43;
    field[0][9]=43;
    field[9][0]=43;
    field[9][9]=43;
*/
for(y=1; y<=8; y++){
    for (x=1; x<=8; x++){
            e=i%2;                          /* Abwechselndes setzen von Spielfeldfarben */
            i++;
            if (e == 1)
                field[x][y]=88;             /* 88 = 'X' -- 254 = 'Quadrat' */
            else
                field[x][y]=254;
        }
    i++;                                    /* Versatz der Zählervariable um 1 pro Druchlauf */
    }

}
void ausgabe_konsole(){

    int x, y;

    for (y=0; y<=8; y++){                   /* Ausgabe des Arrays mit ASCII-Variablen */
        for (x=0; x<=8; x++){
            printf("%c ", field[x][y]);
        }
        printf("\n");
    }

}





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
free(field);
return 0;
}


