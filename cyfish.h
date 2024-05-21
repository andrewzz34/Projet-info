#ifndef CYFISH_H_
#define CYFISH_H_

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_PLAYERS 6
#define MAX_NAME_LENGTH 49
#define PLAYER_NAME_BUFFER 50 

typedef struct {
    char player_name[PLAYER_NAME_BUFFER];
    int score;
    int penguins; 
} Player;

void setupPlayers(Player * players, int num_players);
void printHexagonLine(int num_hexagons);
void printGameBoard(int rows, int cols, Player * players, int num_players);

#endif
