
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cyfish.h"

void printHexagonLine(int cols) {

    printf("\n");
    cols = (cols+1)/2;

     for (int i = 0; i < cols - 1; i++) {
        printf(" /      \\");
        printf("       ");
    }
    printf(" /      \\");
    printf("\n");

  for (int i = 0; i < cols - 1; i++) {
      printf("/        \\");
      printf("______");  
  }
  printf("/        \\");

    printf("\n");
      for (int i = 0; i < cols - 1; i++) {
        printf("\\        /");
        printf("      ");
    }printf("\\        /");
    printf("\n");
  for (int i = 0; i < cols - 1; i++) {
        printf(" \\______/ ");
        printf("      ");
    }printf(" \\______/ ");
}
void printboard(Cell** board,int rows, int cols){
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          int k=(j+(i*9))+1;
          printf("\x1B[%d;80H",k);	
            printf("Cell[%d][%d]: 🐟=%d, 🐧=%d, broken=%d, Player on is %d\n", i, j, board[i][j].fishes, board[i][j].penguin, board[i][j].broken, board[i][j].playeron);
        }
    }
}


Cell** initializeBoard(int rows, int cols) {
    srand(time(NULL)); // initialisation de rand()

    // Allouer dynamiquement le tableau sur le tas
    Cell** board = (Cell**)malloc(rows * sizeof(Cell*));
    for (int i = 0; i < rows; i++) {
        board[i] = (Cell*)malloc(cols * sizeof(Cell));
    }

    // Initialiser toutes les cellules avec des poissons aléatoires entre 1 et 3
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int luck= rand() % 2 + 1;	
            if(i==0 && j%2 !=0){
            board[i][j].fishes = 0;
            board[i][j].penguin = 0;
            board[i][j].broken = 0;
            board[i][j].playeron = 0;
            }
            else if(luck==1) {
            board[i][j].fishes = rand() % 3 + 1; // Entre 1 et 3 poissons
            board[i][j].penguin = 0;
            board[i][j].broken = 0;
            board[i][j].playeron = 0;
            }
            else{
            board[i][j].fishes = rand() % 2 + 2; // Entre 2 et 3 poissons
            board[i][j].penguin = 0;
            board[i][j].broken = 0;
            board[i][j].playeron = 0;
            }
        }
    }


    printboard(board,rows,cols);// a titre vérificatif

    // Retourner le pointeur vers le tableau
    return board;
}

// Fonction de libération de la mémoire allouée
void freeBoard(Cell** board, int rows) {
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
}

void printfishes(Cell** board,int rows, int cols){
  printf("\x1B[3;1H");
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(i==0){
        if(j%2==0){
          if(j==cols-1){
      if (board[i][j].fishes == 0){
          printf("/        \\");

        }
        else if(board[i][j].fishes == 1){
          printf("/   🐟   \\");

        }
        else if(board[i][j].fishes == 2){
          printf("/  🐟🐟  \\");

        }
        else if(board[i][j].fishes == 3){
          printf("/ 🐟🐟🐟 \\");

        }
          }
          else{
             if (board[i][j].fishes == 0){
          printf("/        \\");
          printf("______");
        }
        else if(board[i][j].fishes == 1){
          printf("/   🐟   \\");
          printf("______");
        }
        else if(board[i][j].fishes == 2){
          printf("/  🐟🐟  \\");
          printf("______");
        }
        else if(board[i][j].fishes == 3){
          printf("/ 🐟🐟🐟 \\");
          printf("______");
                }
          }	

        }
      }
      else{
        if(j%2==0){
        int y=4*i+3;
        int x=(j*8)+1;
        printf("\x1B[%d;%dH",y,x);
          if (board[i][j].fishes == 0){
            printf("/        \\");

          }
          else if(board[i][j].fishes == 1){
            printf("/   🐟   \\");

          }
          else if(board[i][j].fishes == 2){
            printf("/  🐟🐟  \\");

          }
          else if(board[i][j].fishes == 3){
            printf("/ 🐟🐟🐟 \\");

          }

        }
        else if(j%2==1){
    int y=(4*i)+1;
    int x=9+(8*(j-1));
    printf("\x1B[%d;%dH",y,x);
    if (board[i][j].fishes == 0){
      printf("/        \\");

    }
    else if(board[i][j].fishes == 1){
      printf("/   🐟   \\");

    }
    else if(board[i][j].fishes == 2){
      printf("/  🐟🐟  \\");

    }
    else if(board[i][j].fishes == 3){
      printf("/ 🐟🐟🐟 \\");

          }		
             }		
      }
    }
  }

}
void affichePenguin(Cell** board, int rows, int cols, int num_players,char** colors,Player* players,int* fishes) {


    srand(time(NULL)); // Initialize random number generator for different outcomes each run

    int penguins_per_player;
    if (num_players >= 5) {
        penguins_per_player = 1;
    } else if (num_players == 4) {
        penguins_per_player = 2;
    } else if (num_players == 3) {
        penguins_per_player = 3;
    } else if (num_players == 2) {
        penguins_per_player = 4;
    } else {
        penguins_per_player = 0; // Assuming no players or invalid input
    }

    int total_penguins = num_players * penguins_per_player;
    for (int i = 0; i < num_players; i++) {
        for(int j=0;j<penguins_per_player;j++){
            int newrows, newcols;
            do {
                newrows = rand() % rows;
                newcols = rand() % cols;
            } while (board[newrows][newcols].penguin != 0 || (newrows == 0 && newcols % 2 != 0) || board[newrows][newcols].broken == 1);

            int posx, posy;
            if (newcols % 2 == 0) {
                posx = 5 + (newcols * 8);
                posy = 4 + (newrows * 4);
            } else {
                posx = 13 + ((newcols - 1) * 8);
                posy = 6 + ((newrows - 1) * 4);
            }


            printf("\x1B[%d;%dH%s", posy, posx, colors[i]); // Display penguin with player-specific color
            board[newrows][newcols].penguin =  1;
            board[newrows][newcols].fishes = 1;
            board[newrows][newcols].playeron = i+1;
            fishes-=1;
            players[i].score+=1;

        }
    }
    printboard(board, rows, cols);
}




//case en haut ///////////////////////////////////////////////////////////////////
int verifyT(Cell **board, int crows, int ccols, int rows, int cols){
  //case en haut 
  if ((board[crows][ccols + 1].penguin ==0 && board[crows][ccols + 1].broken == 0)) {
      return 1;
  } 
  else {
      return 0;
  }

}

//case en bas///////////////////////////////////////////////////////////////////
int verifyL(Cell **board, int crows, int ccols, int rows, int cols){
  //case en bas
  if ((board[crows + 1][ccols].penguin ==0 && board[crows + 1][ccols].broken == 0)) {
      return 1;
  } 
  else {
      return 0;
  }
}
//case en haut a droite///////////////////////////////////////////////////////////////////

int verifyTR(Cell **board, int crows, int ccols, int rows, int cols){
  //case en haut a droite colonnes paire
  if(ccols%2==0){
       if ((board[crows][ccols + 1].penguin ==0 && board[crows][ccols + 1].broken == 0)) {
         return 1;
       } 
       else {
         return 0;
       }
     }

  else{
    //case en haut a droite colonnes impaire

     if ((board[crows-1][ccols + 1].penguin ==0 && board[crows][ccols + 1].broken == 0)) {
       return 1;
     } 
     else {
       return 0;
     }
  }
}


//case en bas a droite///////////////////////////////////////////////////////////////////

int verifyLR(Cell **board, int crows, int ccols, int rows, int cols){
  //case en bas à droite colonnes paire
  if(ccols%2==0){

    if ((board[crows+1][ccols + 1].penguin ==0 && board[crows+1][ccols + 1].broken == 0)) {
        return 1;
    } else {
        return 0;
    }
  }
    //case en bas à droite colonnes impaire

  else{
    if ((board[crows][ccols + 1].penguin ==0 && board[crows][ccols + 1].broken == 0)) {
      return 1;
    } 
    else {
      return 0;
    }
  }

}

//case en bas a gauche///////////////////////////////////////////////////////////////////

int verifyLL(Cell **board, int crows, int ccols, int rows, int cols){
    if(ccols%2==0){

      if ((board[crows+1][ccols - 1].penguin ==0 && board[crows+1][ccols - 1].broken == 0)) {
          return 1;
      } 
      else {
          return 0;
      }
    }
      //case en bas à gauche colonnes impaire

    else{
      if ((board[crows][ccols - 1].penguin ==0 && board[crows][ccols - 1].broken == 0)) {
        return 1;
      } 
      else {
        return 0;
      }
    }

}


int verifyTL(Cell **board, int crows, int ccols, int rows, int cols){
  if(ccols%2==0){

    if ((board[crows][ccols - 1].penguin ==0 && board[crows][ccols - 1].broken == 0)) {
      return 1;
    } 
    else {
      return 0;
    }
  }
        //case en bas à droite colonnes impaire

  else{
        if ((board[crows- 1][ccols - 1].penguin ==0 && board[crows- 1][ccols - 1].broken == 0)) {
          return 1;
        } 
        else {
          return 0;
        }
      }
 }




int possiblemove(Cell **board, int crows, int ccols, int rows, int cols) {
  ///// Cette fonction sert à compter le nombre de directions possibles d'un joueurs, je me suis rendu
  //compte apres 180 lignes qu'il aurait été plus judicieux de faires 6 autres fonctions du style verif en 
  //haut a gauche, en haut a droite, en bas a gauche voila...

  int posmove = 0;
  // cas de la première ligne/////////////////////////////////////////////////////////
  if (crows == 0) { 
    // cas de la première colonne de la première ligne
    if (ccols == 0) {
      //case en bas à droite
      posmove += verifyLR(board, crows, ccols, rows, cols);
      // case en dessous
      posmove += verifyL(board, crows, ccols, rows, cols);

    }

    //cases entre la première et la dernière colonne
    else if (ccols % 2 == 0 && ccols != 0 && ccols!=cols-1) {
      //case en bas a droite
      posmove += verifyLR(board, crows, ccols, rows, cols);

      //case en dessous
      posmove += verifyL(board, crows, ccols, rows, cols);

      //case en bas a gauche
      posmove += verifyLL(board, crows, ccols, rows, cols);

    } 
    // cas première ligne dernière colonne

    else {
      //case en dessous
      posmove += verifyL(board, crows, ccols, rows, cols);

      //case en bas a gauche
      posmove += verifyLL(board, crows, ccols, rows, cols);

    }
  }



  ///cas de la dernière ligne//////////////////////////////////////////////////////////////////////////
  else if(crows==rows-1){
   //cas de la première colonne
    if(ccols==0){
     //case en haut
      posmove += verifyT(board, crows, ccols, rows, cols);

      //case en haut a droite
      posmove += verifyTR(board, crows, ccols, rows, cols);

    }
    //cases entre la première et la dernière colonne sur la dernière ligne des colonnes paires
    else if (ccols % 2 == 0 && ccols != 0 && ccols!=cols-1){
      //case en haut a gauche
      posmove += verifyTL(board, crows, ccols, rows, cols);

      //case en haut
      posmove += verifyT(board, crows, ccols, rows, cols);

      //case en haut a droite
      posmove += verifyTR(board, crows, ccols, rows, cols);


    }
      //cases entre la première et la dernière colonne sur la dernière ligne des colonnes impaires
    else if (ccols % 2 != 0  && ccols!=cols-1){
      //case en haut a gauche
      posmove += verifyTL(board, crows, ccols, rows, cols);

      //case en haut
      posmove += verifyT(board, crows, ccols, rows, cols);

      //case en haut a droite
      posmove += verifyTR(board, crows, ccols, rows, cols);

      //case en bas a gauche
      posmove += verifyLL(board, crows, ccols, rows, cols);

      //case en bas a droite
      posmove += verifyLR(board, crows, ccols, rows, cols);


      }

    //cas dernière colonne
    else{
      //case en haut a gauche
      posmove += verifyTL(board, crows, ccols, rows, cols);

      //case en haut
      posmove += verifyT(board, crows, ccols, rows, cols);


    }

  }
  ///cas de la dernière première colonne//////////////////////////////////////////////////////////////////
  else if(ccols==0 && crows!=0 && crows!= rows-1){
    //case en haut
    posmove += verifyT(board, crows, ccols, rows, cols);

    //case en haut a droite
    posmove += verifyTR(board, crows, ccols, rows, cols);

    //case en bas a droite
    posmove += verifyLR(board, crows, ccols, rows, cols);
    //case en bas 
    posmove += verifyL(board, crows, ccols, rows, cols);

  }
  else if(ccols==cols-1 && crows!=0 && crows!= rows-1){
    //case en haut
    posmove += verifyT(board, crows, ccols, rows, cols);

    //case en haut a gauche
    posmove += verifyTL(board, crows, ccols, rows, cols);

    //case en bas a gauche
    posmove += verifyLL(board, crows, ccols, rows, cols);
    //case en bas 
    posmove += verifyL(board, crows, ccols, rows, cols);

  }
  else{
    //case en haut a gauche
    posmove += verifyTL(board, crows, ccols, rows, cols);

    //case en haut
    posmove += verifyT(board, crows, ccols, rows, cols);

    //case en haut a droite
    posmove += verifyTR(board, crows, ccols, rows, cols);

    //case en bas a gauche
    posmove += verifyLL(board, crows, ccols, rows, cols);

    //case en bas a droite
    posmove += verifyLR(board, crows, ccols, rows, cols);

    //case en bas
    posmove += verifyL(board, crows, ccols, rows, cols);

  }
  return posmove;
}




void printGameBoard(Cell** board,int rows, int cols, Player* players, int num_players,char** colors,int* fishes) {
    int a = (4 * rows) + 2;

    // Affichage de la zone de jeu
    printf("\x1B[1;1H");
  int size=cols;
   if(size%2!=0){
    size = (size+1)/2;
    }
    else if(size%2==0){
    size=(size/2);
    }
    for (int i = 0; i < size-1; i++) {
        printf("  ______  ");
        printf("      ");
    }printf("  ______");

    for (int i = 0; i < rows; i++) {
        printHexagonLine(cols);
    }
    affichePenguin(board, rows, cols, num_players,colors,players,fishes);
    printfishes(board,rows,cols);
    printf("\x1B[4;130H       👑");
    printf("\x1B[5;130H Bob : ");
    printf("\x1B[5;137H\x1B[48;2;255;128;0m🐧\x1B[0m");

    // Affichage des noms et scores des joueurs
    printf("\x1B[%d;0H\n", a);
    printf("Joueurs :\n");

    for (int i = 0; i < num_players; i++) {
        printf("Joueur %d : %s\n", i + 1, players[i].player_name);
    }
    printf("\n");
}


void movepenguin(Cell** board,int rows, int cols,char** colors,Player players,int* fishes){

    int oldrows =0;
    int oldcols =0;
    int newrows =0;
    int newcols =0;
    int player_index;
   ///////////////////////////choix du pingouin/////////
    printf("\x1B[30;1H"); 
    do{

    printf("\x1B[K");
    printf("sur quelle ligne se situe le penguin que voulez vous deplacer ?\n");
    scanf("%d",&oldrows);
    printf("\x1B[F\x1B[K");
    printf("\x1B[E"); // Déplace le curseur vers la ligne suivante

    printf("\x1B[K");
    printf("sur quelle colonne situe le penguin que voulez vous deplacer ?\n");
    scanf("%d",&oldcols);
    printf("\x1B[F\x1B[K");
    printf("\x1B[E"); // Déplace le curseur vers la ligne suivante
    
    printf("\x1B[3;140H %d,%d",board[oldrows][oldcols].playeron , players.id_player+1);
    printf("\x1B[34;1H"); 
    if(board[oldrows][oldcols].penguin==0 || board[oldrows][oldcols].playeron != players.id_player+1){
        printf("\x1B[4F");
    }
    }while (board[oldrows][oldcols].penguin==0 || board[oldrows][oldcols].playeron != players.id_player+1);
    player_index = board[oldrows][oldcols].playeron -1 ; // verif pingouin et bon joueur
  
    board[oldrows][oldcols].penguin =0;// met la case sans pingouin et la casse
    board[oldrows][oldcols].broken =1;
  
    int playerID = board[oldrows][oldcols].playeron;
    board[oldrows][oldcols].playeron =0;


    do{
      do{
      printf("\x1B[K");
      printf("sur quelle ligne voulez vous deplacer votre penguin ?\n"); 
      scanf("%d",&newrows);
      printf("\x1B[F\x1B[K");
      printf("\x1B[E"); 
      if (newrows > rows-1 || newrows < 0) {
    printf("\x1B[2F");

      }   
      }while (newrows > rows-1 || newrows < 0);

      do{
      printf("\x1B[K");
      printf("sur quelle colonne voulez vous deplacer votre penguin ?\n");
      scanf("%d",&newcols);
      printf("\x1B[F\x1B[K");
      printf("\x1B[E"); // Déplace le curseur vers la ligne suivante
      if (newcols > cols-1 || newcols < 0 ) {
    printf("\x1B[2F");

      } 
      }while (newcols > cols-1 || newcols < 0);
      
        if(board[newrows][newcols].penguin ==1 || board[newrows][newcols].broken ==1 ){
    printf("\x1B[4F");       
        }
    }while (board[newrows][newcols].penguin ==1 || (newrows==0 && newcols%2!=0) || board[newrows][newcols].broken ==1 ); // verif qu'il n'y a pas déja un pingouin
    players.score += board[newrows][newcols].fishes;
    board[newrows][newcols].penguin =1;// met un pingouin sur la nouvelle case
    board[newrows][newcols].playeron = playerID;
    fishes -= board[newrows][newcols].fishes;

    if(oldcols%2==0){
        int posxx= (5+(oldcols*8));
        int posyy= (4+(oldrows*4));  
  printf("\x1B[%d;%dH",posyy-2,posxx-2);
  printf("🌊🌊🌊");
  printf("\x1B[%d;%dH",posyy-1,posxx-3);
  printf("🌊🌊🌊🌊");
  printf("\x1B[%d;%dH",posyy,posxx-3);
  printf("🌊🌊🌊🌊");
  printf("\x1B[%d;%dH",posyy+1,posxx-2);
  printf("🌊🌊🌊");

    }

    else{
            oldcols = oldcols-1;
        int posxx= (13+(oldcols*8));
        int posyy= (6+((oldrows-1)*4));
        printf("\x1B[%d;%dH",posyy-2,posxx-2);
  printf("🌊🌊🌊");
  printf("\x1B[%d;%dH",posyy-1,posxx-3);
  printf("🌊🌊🌊🌊");
  printf("\x1B[%d;%dH",posyy,posxx-3);
  printf("🌊🌊🌊🌊");
  printf("\x1B[%d;%dH",posyy+1,posxx-2);
  printf("🌊🌊🌊");


    }
     board[newrows][newcols].penguin =  1;
     if (newcols % 2 == 0) {
        int posx = 5 + (newcols * 8);
        int posy = 4 + (newrows * 4);
        printf("\x1B[%d;%dH%s", posy, posx, colors[player_index]);
    } else {
        newcols -= 1;
        int posx = 13 + (newcols * 8);
        int posy = 6 + ((newrows - 1) * 4);
        printf("\x1B[%d;%dH%s", posy, posx, colors[player_index]);
    }
        printboard(board,rows,cols);
}
