#include <stdio.h>
#include "cyfish.h"

void printHexagonLine(int num_hexagons) {
    printf("\n");

    for (int i = 0; i < num_hexagons; i++) {
        printf(" /      \\ ");
        printf("      ");
    }
    printf("\n");
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < num_hexagons-1; j++) {
            printf("/        \\");
            printf("______");  
        }
        printf("/        \\");
    }
    printf("\n");
    for (int i = 0; i < num_hexagons; i++) {
        printf("\\        /");
        printf("      ");
    }
    printf("\n");
    for (int i = 0; i < num_hexagons; i++) {
        printf(" \\______/ ");
        printf("      ");
    }
}

void printGameBoard(int rows, int cols, Player * players, int num_players) {
    int a = (4 * rows) + 2;

    // Affichage de la zone de jeu
    printf("\x1B[1;1H");
    for (int i = 0; i < cols; i++) {
        printf("  ______  ");
        printf("      ");
    }

    for (int i = 0; i < rows; i++) {
        printHexagonLine(cols);
    }
    printf("\x1B[3;5H\x1B[48;2;255;128;0m🐧\x1B[0m");

    // Affichage des noms et scores des joueurs
    printf("\x1B[%d;0H\n", a);
    printf("Joueurs :\n");

    for (int i = 0; i < num_players; i++) {
        printf("Joueur %d : %s\n", i + 1, players[i].player_name);
    }
    printf("\n");
}
