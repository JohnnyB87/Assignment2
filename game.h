//
// Created by John on 26/03/2018.
//
#ifndef GAME_H
#define GAME_H
#define MAX_NAME_LEN 50

enum Bool{False, True};
enum status {P1TURN, P2TURN, P1WON, P2WON, DRAW};
typedef enum Bool boolean;

//extern const char SPACE = '-';
//extern const char X_SYMBOL = 'X';
//extern const char O_SYMBOL = 'O';

struct game {
    char board[3][3];
    char playerNames[2][MAX_NAME_LEN];
    int status;
    boolean finished;
};

void playGame();
void initialiseGame(struct game* pGameInfo, char* name1, char* name2);
void drawBanner();
void displayBoard(char board[3][3]);
void printStatus(struct game* pGameInfo);
void displayBoardPositions();
void getRowCol(int posNum, int* row, int* col);
#endif