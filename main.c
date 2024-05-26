#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cyfish.h"

int main() {
    int rows, cols;
    Player* players = NULL;
    int num_players;

    system("clear");
    do {
        printf("Enter the number of players (2 to 6): ");
        scanf("%d", &num_players);
    } while (num_players < 2 || num_players > 6);

    players = malloc(sizeof(Player) * num_players);
    if (players == NULL) {
        printf("Erreur malloc joueur\n");
        exit(1);
    }

    setupPlayers(players, num_players);



    // Fixation de la taille du plateau de jeu
    printf("Nombre de lignes du plateau de jeu : ");
    scanf("%d", &rows);
    printf("Nombre de colonnes du plateau de jeu (nombre impaire recquis): ");
    scanf("%d", &cols);
    if (cols%2==0){
    cols +=1;
    }


    // Vérification de la validité de la taille du plateau de jeu
    if (rows < 1 || cols < 1 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Taille du plateau invalide. Veuillez choisir des dimensions entre 1 et 9.\n");
        free(players);
        return 1;
    }
    system("clear");

    Cell** board = initializeBoard(rows, cols);
    /////count number fish
    int numberfish=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        numberfish += board[i][j].fishes;
        }
    }
    int* pointfishes = NULL;
    pointfishes = &numberfish;
    char* colors[MAX_PLAYERS] = {
        "\x1B[48;2;135;206;235m🐧\x1B[0m", // Blue
        "\x1B[48;2;255;165;0m🐧\x1B[0m",   // Orange
        "\x1B[48;2;124;252;0m🐧\x1B[0m",   // Green
        "\x1B[48;2;255;0;255m🐧\x1B[0m",   // Magenta
        "\x1B[48;2;255;255;0m🐧\x1B[0m",   // Yellow
        "\x1B[48;2;0;255;255m🐧\x1B[0m"    // Cyan
    };
    // Affichage de la zone de jeu
    printGameBoard(board,rows, cols, players, num_players,colors,pointfishes);


  /////////////////DEBUT DU JEU//////////////////////////

  
  
    ///boucle de jeu
    /*
    int totalmove=1;
    while(numberfish >0 && totalmove>0){
    int totalmove=0;
    for (int i = 0; i < num_players; i++){

          if(players[i].penguins!=0){
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                  if(board[i][j].playeron==i+1){
                    
                   totalmove += possiblemove(board, i, j,rows, cols);
                  
                  }
                }
            }
           }
    }
    
    }
    if(totalmove==0){
	     int max=0;
	     for (int i = 0; i < num_players; i++){
	      if (players[max].score<players[i].score){
	      	max=i;
	      }
	     }
		 printf("\x1B[45;1H victory of player %d ",players[max].id_player +1);
		 exit(2);
    }
    else{
        for (int i = 0; i < num_players; i++){
    	movepenguin(board,rows, cols,colors,players[i],pointfishes);
    	} 
    }
    printf("\x1B[20;1H"); 
        for (int k = 0; k < num_players; k++) {
        printf("Joueur %d : %s score %d\n", k + 1, players[k].player_name,players[k].score);
        }
    }

  
  }
    
*/
	int totalmove = 1;
while (numberfish > 0 && totalmove > 0) {
    totalmove = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].penguins != 0) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (board[i][j].playeron == i + 1) {
                        totalmove += possiblemove(board, i, j, rows, cols);
                    }
                }
            }
        }
    }
    if (totalmove == 0) {
        int max = 0;
        for (int i = 0; i < num_players; i++) {
            if (players[max].score < players[i].score) {
                max = i;
            }
        }
        printf("\x1B[45;1H victory of player %d ", players[max].id_player + 1);
         free(players);
         freeBoard(board, rows);

        exit(2);
    }
    else {
        for (int i = 0; i < num_players; i++) {
            movepenguin(board, rows, cols, colors, players[i], pointfishes);
        }
    }
    totalmove = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].penguins != 0) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (board[i][j].playeron == i + 1) {
                        totalmove += possiblemove(board, i, j, rows, cols);
                    }
                }
            }
        }
    }
    if (totalmove == 0) {
        int max = 0;
        for (int i = 0; i < num_players; i++) {
            if (players[max].score < players[i].score) {
                max = i;
            }
        }
        printf("\x1B[45;1H victory of player %d ", players[max].id_player + 1);
         free(players);
         freeBoard(board, rows);

        exit(2);
    }
    /*
    printf("\x1B[25;1H");
	for (int k = 0; k < num_players; k++) {
    printf("Joueur %d : %s score %d\n", k + 1, players[k].player_name, players[k].score);
    }
    */


}

    ////////////////////////FIN DU JEU/////////////////////////
  
    int a = (4 * rows) + 10;
    printf("\x1B[%d;0H\n", a);

    free(players);
    freeBoard(board, rows);


    return 0;


}
