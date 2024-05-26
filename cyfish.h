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
    int id_player; 
} Player;

typedef struct {
    int fishes; // Nombre de poissons sur la case
    int penguin; // Identifiant du pingouin sur la case, 0 si aucun
    int broken; // Indique si la case est occupée (1 pour oui, 0 pour non)
    int playeron;
} Cell;

void setupPlayers(Player* players, int num_players);
void printHexagonLine(int num_hexagons);
void printGameBoard(Cell** board,int rows, int cols, Player* players, int num_players,char** colors,int* fishes);
void printboard(Cell** board,int rows, int cols);
Cell** initializeBoard(int rows, int cols);
void freeBoard(Cell** board, int rows);
void printfishes(Cell** board,int rows, int cols);
void affichePenguin(Cell** board, int rows, int cols, int num_players,char** colors,Player* players,int* fishes);
int verifyT(Cell **board, int crows, int ccols, int rows, int cols);
int verifyTR(Cell **board, int crows, int ccols, int rows, int cols);
int verifyTL(Cell **board, int crows, int ccols, int rows, int cols);
int verifyL(Cell **board, int crows, int ccols, int rows, int cols);
int verifyLR(Cell **board, int crows, int ccols, int rows, int cols);
int verifyLL(Cell **board, int crows, int ccols, int rows, int cols);
int possiblemove(Cell **board, int crows, int ccols, int rows, int cols);




#endif
