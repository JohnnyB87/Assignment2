//
// Created by John on 26/03/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "game.h"


const char SPACE = ' ';
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';

void playGame() {
    printf("Xs and Os!\n");
    struct game* pGameInfo = (struct game*)malloc(sizeof(struct game));
    int row;
    int col;
    char* name1 = _argv[1];
    char* name2 = _argv[2];

    printf("name1: %s   name2: %s \n\n",name1,name2);


    initialiseGame(pGameInfo, name1, name2);
    while(!pGameInfo->finished) {
        printStatus(pGameInfo);
        processMove(pGameInfo, &row, &col);

    }

    printStatus(pGameInfo);

    free(pGameInfo);
}

void initialiseGame(struct game* pGameInfo, char* name1, char* name2){
    if(pGameInfo == NULL){
        printf("ERROR: Null pointer Exception\n");
        return;
    }
    pGameInfo->finished = False;
    pGameInfo->status = P1TURN;
    pGameInfo->noOfGoes = 0;
    int first = whoGoesFirst();
    printf("First: %d\n\n", first);
    if(first == 0) {
        strcpy(pGameInfo->playerNames[0], name1);
        strcpy(pGameInfo->playerNames[1], name2);
    }else{
        strcpy(pGameInfo->playerNames[0], name2);
        strcpy(pGameInfo->playerNames[1], name1);
    }
    printf("Player1: %s  player2: %s \n\n\n",pGameInfo->playerNames[0], pGameInfo->playerNames[1]);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            pGameInfo->board[i][j] = SPACE;
        }
    }

}

void drawBanner(){
    for(int i=0;i<15;i++){
        printf("\n");
    }
    printf("------------\nGAME STATUS\n------------\n");
}

void displayBoard(char board[3][3]){
    drawBanner();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c",board[i][j]);
            if(j<2){
                printf("|");
            }
        }
        printf("\n");
        if(i<2){
            printf("-----\n");
        }
    }
}

void printStatus(struct game* pGameInfo){
    displayBoard(pGameInfo->board);
    printf("\n");
    if(pGameInfo->finished == False){
        if(pGameInfo->status == P1TURN) {
            printf("%s's Turn", pGameInfo->playerNames[0]);
        }
        else{
            printf("%s's Turn", pGameInfo->playerNames[1]);
        }
    }
    else{
        if(pGameInfo->status == P1WON) {
            printf("Well done %s. You Won. ", pGameInfo->playerNames[0]);
        }
        else if(pGameInfo->status == P2WON){
            printf("Well done %s. You Won. ", pGameInfo->playerNames[1]);
        }
        else{
            printf("Game Over. It ended in a DRAW");
        }
    }
}

void displayBoardPositions(){
    printf("\n\n");
    int count = 0;
    while(count < 9){
        printf("%d", count);
        if(count % 3 != 2){
            printf("|");
        }else  if(count < 8){
            printf("\n-----\n");
        }
        count++;
    }
    printf("\n");
}

void getRowCol(int posNum, int* row, int* col){
    *row = posNum/3;
    *col = posNum%3;
}

int getUserInput(){
    int n;
    while(True) {
        printf("Enter a number (0 - 8):");
        scanf("%d", &n);
        if (n >=0 && n <= 8) {
            return n;
        } else {
            printf("ERROR: Invalid Number\n");
            char d = (char) n;
            while(d != '\n'){
                d = (char) getchar();
            }
            continue;
        }
    }
}

boolean checkValidity(struct game *pGameInfo, int choice, int *row, int* col){
    getRowCol(choice,row,col);
    if(pGameInfo->board[*row][*col] == SPACE){
       return True;
    }
    return False;
}

void processMove(struct game *pGameInfo, int *row, int* col){
    boolean valid = False;
    int choice;
    while(valid == False) {
        displayBoardPositions();
        choice = getUserInput();
        valid = checkValidity(pGameInfo, choice, row, col);
        printf("\nChosen Number: %d Already Selected: %s\n",
               choice, valid ? "False" : "True");
    }
    pGameInfo->noOfGoes++;
    if(pGameInfo->status == P1TURN){
        pGameInfo->board[*row][*col] = X_SYMBOL;
        if(pGameInfo->noOfGoes > 4 && checkForWinner(pGameInfo, row, col,X_SYMBOL)){
            pGameInfo->status = P1WON;
            pGameInfo->finished = True;
            return;
        }
        pGameInfo->status = P2TURN;
    }else{
        pGameInfo->board[*row][*col] = O_SYMBOL;
        if(pGameInfo->noOfGoes > 4 && checkForWinner(pGameInfo, row, col,O_SYMBOL)){
            pGameInfo->status = P2WON;
            pGameInfo->finished = True;
            return;
        }
        pGameInfo->status = P1TURN;
    }
    if(pGameInfo->noOfGoes == 9){
        pGameInfo->finished =True;
        pGameInfo->status = DRAW;
    }

}

int whoGoesFirst(){
    int r;
    srand(time(0));
    r = rand() % 2;
    return r;

}

boolean checkForWinner(struct game* pGameInfo, int *row, int* col, char c){
    // check rows
    printf("ROWS\n");
    for(int i=0;i<3;i++){
        printf("board[%d][%d]: %c\n",*row,i, pGameInfo->board[*row][i]);
        if(pGameInfo->board[*row][i] != c){
            break;
        }
        else if(i == 2){
            return True;
        }
    }

    // check columns
    printf("COLUMNS\n");
    for(int i=0;i<3;i++){

        printf("board[%d][%d]: %c\n",i,*col, pGameInfo->board[i][*col]);
        if(pGameInfo->board[i][*col] != c){
            break;
        }
        else if(i == 2){
            return True;
        }
    }

    // check diagonal
    printf("DIAGONAL\n");
    if(*col == *row) {
        for (int i = 0; i < 3; i++) {
            printf("board[%d][%d]: %c\n",i,i, pGameInfo->board[i][i]);
            if (pGameInfo->board[i][i] != c) {
                break;
            }
            else if (i == 2) {
                return True;
            }
        }
    }

    // check reverse diagonal
    printf("REVERSE DIAGONAL\n");
    if((*col + *row) == 2) {
        for (int i = 0; i < 3; i++) {
            printf("board[%d][%d]: %c\n",i,2-i, pGameInfo->board[i][i-2]);
            if (pGameInfo->board[i][2-i] != c) {
                break;
            }
            else if (i == 2) {
                return True;
            }
        }
    }
    return False;
}