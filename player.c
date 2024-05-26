#include <stdio.h>
#include <string.h>
#include "cyfish.h"
void setupPlayers(Player* players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d (up to 49 characters): ", i + 1);
        scanf("%49s", players[i].player_name); // Limite l'entrée pour éviter le débordement de tampon
        while (getchar() != '\n');

        if (strlen(players[i].player_name) > MAX_NAME_LENGTH) {
            printf("Name entered is too long. Please enter a name up to 49 characters.\n");
            scanf("%49s", players[i].player_name); // Limite l'entrée pour éviter le débordement de tampon
        }

        players[i].score = 0;
        players[i].id_player = i;

      

        if (num_players == 2) {
            players[i].penguins = 4;
        } else if (num_players == 3) {
            players[i].penguins = 3;
        } else {
            players[i].penguins = 2;
        }
    }
}
