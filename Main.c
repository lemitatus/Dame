#include <stdio.h>
#include <math.h>
#define feld 10


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
