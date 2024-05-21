#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cyfish.h"

int main() {
    Player * players = NULL;
    int * num_players = NULL;
    num_players = malloc(sizeof(int));
    if(num_players == NULL) {
        printf("erreur malloc num_players\n");
        exit(1);
    }
    system("clear");
    do {
        printf("Enter the number of players (2 to 6): ");
        scanf("%d", num_players);
    } while (*num_players < 2 || *num_players > 6);

    players = malloc(sizeof(Player) * (*num_players));
    if(players == NULL) {
    	printf("Erreur malloc joueur\n");
    	exit(1);
    }
    int rows, cols;
    setupPlayers(players, *num_players);
    // Fixation de la taille du plateau de jeu
    printf("Nombre de lignes du plateau de jeu : ");
    scanf("%d", &rows);
    printf("Nombre de colonnes du plateau de jeu : ");
    scanf("%d", &cols);
    

    // Vérification de la validité de la taille du plateau de jeu
    if (rows < 1 || cols < 1 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Taille du plateau invalide. Veuillez choisir des dimensions entre 1 et 9.\n");
        return 1;
    }

    // Affichage de la zone de jeu
    printGameBoard(rows, cols, players, *num_players);

    int a = (4 * rows) + 10;
    printf("\x1B[%d;0H\n", a);
    
    free(players);
    free(num_players);
    return 0;
}

