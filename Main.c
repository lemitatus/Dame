#include <stdio.h>

#define feld 43 /* + */
#define frei 45 /* - */
#define p1 35 /* # */
#define p2 38 /* & */
#define p1_king 40
#define p2_king 41

int a1,a2,b1,b2;
int kords [4];
int field[9][9];

int check_zug_p1_Koenig() {
  if (field[kords[0]][kords[1]]==p1_king){ /*Startfeld MUSS p1 enthalten*/
    if (field[kords[2]][kords[3]]==field[kords[0]-1][kords[1]-1]){ /*oben links*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p2 && field[kords[2]-1][kords[3]-1]==frei)
        return 4; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p2_king && field[kords[2]-1][kords[3]-1]==frei)
        return 4; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]+1][kords[1]-1]){ /*oben rechts*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p2 && field[kords[2]+1][kords[3]-1]==frei)
        return 5; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p2_king && field[kords[2]+1][kords[3]-1]==frei)
        return 5; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]-1][kords[1]+1]){ /*unten links*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p2 && field[kords[2]-1][kords[3]+1]==frei)
        return 2; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p2_king && field[kords[2]-1][kords[3]+1]==frei)
        return 2; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]+1][kords[1]+1]){ /*unten rechts*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p2 && field[kords[2]+1][kords[3]+1]==frei)
        return 3; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p2_king && field[kords[2]+1][kords[3]+1]==frei)
        return 3; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
    }
    else
      return 0; /*Absicherung falscher Zug*/
  } /*if field == p1*/
  else
    return 0; /*Startfeld ist nicht p1*/
} /*check_zug_p1_Koenig*/
int check_zug_p1() {
  if (field[kords[0]][kords[1]]==p1){ /*Startfeld MUSS p1 enthalten*/
    if (field[kords[2]][kords[3]]==field[kords[0]-1][kords[1]+1]){ /*unten links*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p2 && field[kords[2]-1][kords[3]+1]==frei)
        return 2; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p2_king && field[kords[2]-1][kords[3]+1]==frei)
        return 2; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]+1][kords[1]+1]){ /*unten rechts*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p2 && field[kords[2]+1][kords[3]+1]==frei)
        return 3; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p2_king && field[kords[2]+1][kords[3]+1]==frei)
        return 3; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
    }
    else
      return 0; /*Absicherung falscher Zug*/
  } /*if field == p1*/
  else
    return 0; /*Startfeld ist nicht p1*/
} /*check_zug_p1_Koenig*/
int check_zug_p2_Koenig() {
  if (field[kords[0]][kords[1]]==p2_king){ /*Startfeld MUSS p1 enthalten*/
    if (field[kords[2]][kords[3]]==field[kords[0]-1][kords[1]-1]){ /*oben links*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p1 && field[kords[2]-1][kords[3]-1]==frei)
        return 4; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p1_king && field[kords[2]-1][kords[3]-1]==frei)
        return 4; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]+1][kords[1]-1]){ /*oben rechts*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p1 && field[kords[2]+1][kords[3]-1]==frei)
        return 5; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p1_king && field[kords[2]+1][kords[3]-1]==frei)
        return 5; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]-1][kords[1]+1]){ /*unten links*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p1 && field[kords[2]-1][kords[3]+1]==frei)
        return 2; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p1_king && field[kords[2]-1][kords[3]+1]==frei)
        return 2; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]+1][kords[1]+1]){ /*unten rechts*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p1 && field[kords[2]+1][kords[3]+1]==frei)
        return 3; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p1_king && field[kords[2]+1][kords[3]+1]==frei)
        return 3; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
    }
    else
      return 0; /*Absicherung falscher Zug*/
  } /*if field == p1*/
  else
    return 0; /*Startfeld ist nicht p1*/
} /*check_zug_p1_Koenig*/
int check_zug_p2() {
  if (field[kords[0]][kords[1]]==p2){ /*Startfeld MUSS p1 enthalten*/
    if (field[kords[2]][kords[3]]==field[kords[0]-1][kords[1]-1]){ /*oben links*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p1 && field[kords[2]-1][kords[3]-1]==frei)
        return 4; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p1_king && field[kords[2]-1][kords[3]-1]==frei)
        return 4; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
    else if (field[kords[2]][kords[3]]==field[kords[0]+1][kords[1]-1]){ /*oben rechts*/
      if (field[kords[2]][kords[3]]==frei)
        return 1; /*freies Feld > zug setzen */
      else if (field[kords[2]][kords[3]]==p1 && field[kords[2]+1][kords[3]-1]==frei)
        return 5; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else if (field[kords[2]][kords[3]]==p1_king && field[kords[2]+1][kords[3]-1]==frei)
        return 5; /*gegner Stein Feld + dahinter frei > zug setzen und Stein eliminieren*/
      else
        return 0; /*falscher Zug*/
      }
  } /*if field == p1*/
  else
    return 0; /*Startfeld ist nicht p1*/
} /*check_zug_p1_Koenig*/

void scan() {
  int *ptr;
  ptr=kords;
  scanf("%d%d%d%d",&a1 ,&a2 ,&b1 ,&b2);

  *ptr=a1;
  *(ptr+1)=a2;
  *(ptr+2)=b1;
  *(ptr+3)=b2;

}
void spielfeld() {
  int x,y,z;

  for (y=1;y<9;y++){
    for (x=1;x<9;x++){
        z=(x+y) % 2;
        if (z==0) {
          field[x][y]=feld;
        }

        else if(z==1){
          if(y<4){
            field[x][y]=p1;
          }
          else if(y>5){
            field[x][y]=p2;
          }
          else
          field[x][y]=frei;
        }/*if z==1*/
    }
  }
}/*spielfeld*/
void ausgabe_konsole () {
  int x,y,z=1;
  printf("\n");
  printf("  1 2 3 4 5 6 7 8\n");
  for (y=1;y<9;y++){
    printf("%d",z);
    z++;
    for (x=1;x<9;x++){
      printf(" %c",field[x][y]);
    }
    printf("\n");
  }
}
void spielzug (int player) {
    char a;
    printf("Spieler:%d\n",player );
    printf("Spielstein waehlen\n");

    scan();
    printf("Zahlen angenommen %d, %d, %d, %d \n",kords[0] ,kords[1], kords[2], kords[3]);

    if (field[kords[0]][kords[1]]==p1){
      switch (check_zug_p1()) {
        case 0:
          spielzug(player);
          break;
        case 1:   /*freies Feld > einfach setzen */
          if ((kords[3])==8) /*ende erreicht > King stein */
            field [kords[2]][kords[3]]=p1_king;
          else
            field [kords[2]][kords[3]]=p1;

          field [kords[0]][kords[1]]=frei;
          ausgabe_konsole();
          break;

        case 2:   /*besiegen unten links*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          if ((kords[3]+1)==8)  /*ende erreicht > King stein */
            field [kords[2]-1][kords[3]+1]=p1_king;
          else
            field [kords[2]-1][kords[3]+1]=p1;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;

          case 3:   /*besiegen unten rechts*/
            field [kords[2]][kords[3]]=frei;
            field [kords[0]][kords[1]]=frei;
            if ((kords[3]+1)==8)  /*ende erreicht > King stein */
              field [kords[2]+1][kords[3]+1]=p1_king;
            else
              field [kords[2]+1][kords[3]+1]=p1;
            ausgabe_konsole();
            printf("Weiterer Zug? y/n\n"); /*121/110*/
            scanf("%c",&a);
            if (a==121)
              spielzug(player);
            else
                break;
      }
    }
    else if (field[kords[0]][kords[1]]==p1_king){
      switch (check_zug_p1_Koenig()) {
        case 0:
          spielzug(player);
          break;
        case 1:   /*freies Feld > einfach setzen */
          field [kords[2]][kords[3]]=p1_king;
          field [kords[0]][kords[1]]=frei;
          ausgabe_konsole();
          break;
        case 2:   /*besiegen u links */
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]-1][kords[3]+1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
        case 3:   /*besiegen u rechts */
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]+1][kords[3]+1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
        case 4:   /*besiegen o links*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]-1][kords[3]-1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
        case 5:   /*besiegen o rechts*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]+1][kords[3]-1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;

      }
    }
    else if (field[kords[0]][kords[1]]==p2){
      switch (check_zug_p2()) {
        case 0:
          spielzug(player);
          break;
        case 1:   /*freies Feld > einfach setzen */
          if ((kords[3])==1) /*ende erreicht > King stein */
            field [kords[2]][kords[3]]=p2_king;
          else
            field [kords[2]][kords[3]]=p2;

          field [kords[0]][kords[1]]=frei;
          ausgabe_konsole();
          break;
        case 4:   /*besiegen o links*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          if ((kords[3]-1)==1)  /*ende erreicht > King stein */
            field [kords[2]-1][kords[3]-1]=p2_king;
          else
            field [kords[2]-1][kords[3]-1]=p2;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
        case 5:   /*besiegen o rechts*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          if ((kords[3]-1)==1)  /*ende erreicht > King stein */
            field [kords[2]+1][kords[3]-1]=p2_king;
          else
            field [kords[2]+1][kords[3]-1]=p2;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
      }
    }
    else if (field[kords[0]][kords[1]]==p2_king){
      switch (check_zug_p1()) {
        case 0:
          spielzug(player);
          break;
        case 1:   /*freies Feld > einfach setzen */
          if ((kords[3])==8) /*ende erreicht > King stein */
            field [kords[2]][kords[3]]=p1_king;
          else
            field [kords[2]][kords[3]]=p1;

          field [kords[0]][kords[1]]=frei;
          ausgabe_konsole();
          break;
        case 2:   /*besiegen u links*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]-1][kords[3]+1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
        case 3:   /*besiegen u rechts*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]+1][kords[3]+1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
        case 4:   /*besiegen o links*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]-1][kords[3]-1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
        case 5:   /*besiegen o rechts*/
          field [kords[2]][kords[3]]=frei;
          field [kords[0]][kords[1]]=frei;
          field [kords[2]+1][kords[3]-1]=p1_king;
          ausgabe_konsole();
          printf("Weiterer Zug? y/n\n"); /*121/110*/
          scanf("%c",&a);
          if (a==121)
            spielzug(player);
          else
            break;
      }
    }
    else{
      printf("falscher Zug\n");
      spielzug(player);
    }
}/*void spielzug*/
void spielschleife() {
    int end=0, player=1;

    while (end==0)
    {
        switch (player)
        {
            case 1:
                spielzug(player);
                player=2;
                ausgabe_konsole();
                end=check_win();
                break;
            case 2:
                spielzug(player);
                player=1;
                ausgabe_konsole();
                end=check_win();
                break;
            default:
                break;
        }
    }
}
void hauptmenu () {
    int x;
    printf("\nWillkomen zum Spiel Dame! Bitte wählen Sie einen Menüpunkt aus!\n (1) Neues Spiel\n (2) Design\n (3) Beenden \n");
    scanf ("%d", &x);
    switch (x)
    {
        case 1:
            ausgabe_konsole();
            spielschleife();
            break;
   /*     case 2:
            design();
            break;  */
        case 3:
            return;

        default:
            break;
    }
}
int check_win() {
    int x,y;
    int stein1,stein2;
    for (y=0; y<=10; y++)
    {
        for (x=0; x<=10; x++)
        {
            if (field[x][y]==p1)
            {
                stein1=1;
            }
            else if (field[x][y]==p2)
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

main () {
spielfeld();
hauptmenu();
return 0;
}
