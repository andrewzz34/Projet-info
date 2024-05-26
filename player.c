#include <stdio.h>
#include <string.h>
#include "cyfish.h"
void setupPlayers(Player* players, int num_players, char** colors) {
    char buffer[PLAYER_NAME_BUFFER + 1]; // +1 for newline
    for (int i = 0; i < num_players; i++) {
        while (1) {
            printf("Enter name for player %d (up to 49 characters): ", i + 1);
            if (fgets(buffer, sizeof(buffer), stdin)) {
                // Check if input was too long
                if (buffer[strlen(buffer) - 1] != '\n') {
                    printf("Name entered is too long. Please enter a name up to 49 characters.\n");
                    clear_input_buffer(); // Clear remaining characters in the input buffer
                    continue; // Prompt for input again
                }

                // Remove newline character if present
                buffer[strcspn(buffer, "\n")] = 0;

                if (strlen(buffer) > MAX_NAME_LENGTH) {
                    printf("Name entered is too long. Please enter a name up to 49 characters.\n");
                    continue; // Prompt for input again
                }

                strcpy(players[i].player_name, buffer);
                break; // Exit the while loop
            } else {
                clear_input_buffer(); // Just in case fgets failed due to an error
                printf("Input error. Please try again.\n");
            }
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

        // Display the player with their color
        printf("Player %d: %s %s\n", i + 1, colors[i], players[i].player_name);
    }
}
