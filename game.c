//
// Created by John on 26/03/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//#define CONST_VARS
#include "game.h"


const char SPACE = '-';
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';

void playGame() {
    printf("Xs and Os!\n");
    struct game* pGameInfo = malloc(sizeof(struct game));

    char* name1 = "John";
    char* name2 = "Emma";

    initialiseGame(pGameInfo, name1, name2);
    printf("size: %d\n", sizeof(pGameInfo));

    for(int i=0;i<2;i++){
        printf("Name%d: %s\n",i+1, pGameInfo->playerNames[i]);
    }

    printf("status: %d  Finished: %d",pGameInfo->status,pGameInfo->finished);



//    drawBanner();
//    displayBoard(pGameInfo->board);

    initialiseGame(pGameInfo, "John", "Annie");
    pGameInfo->board[0][0] = X_SYMBOL; // top left X
    pGameInfo->board[2][2] = O_SYMBOL; // bottom right o

//    displayBoard(pGameInfo->board);
//
//    printStatus(pGameInfo);
//    displayBoardPositions();

    printf("\n\n");
    int row;
    int col;
//    for(int i=0;i<9;i++) {
////        getRowCol(i, &row, &col);
//        boolean testBool = checkValidity(pGameInfo, i, &row, &col);
//        printf("Position num: %d  row: %d  col: %d  Valid: %s\n",i,row,col,testBool ? "True" : "False");
//    }
//
//    int test = getUserInput();
//    printf("%d",test);

    processMove(pGameInfo,&row,&col);
    displayBoard(pGameInfo->board);
    processMove(pGameInfo,&row,&col);
    displayBoard(pGameInfo->board);
    free(pGameInfo);
}

void initialiseGame(struct game* pGameInfo, char* name1, char* name2){
    pGameInfo->finished = False;
    pGameInfo->status = P1TURN;
    strcpy(pGameInfo->playerNames[0],name1);
    strcpy(pGameInfo->playerNames[1],name2);
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
    printf("\n\n");
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
        choice = getUserInput();
        valid = checkValidity(pGameInfo, choice, row, col);
        printf("\nChosen Number: %d Already Selected: %s\n",
               choice, valid ? "False" : "True");
    }
    if(pGameInfo->status == P1TURN){
        pGameInfo->board[*row][*col] = X_SYMBOL;
        pGameInfo->status = P2TURN;
    }else{
        pGameInfo->board[*row][*col] = O_SYMBOL;
        pGameInfo->status = P1TURN;
    }
}