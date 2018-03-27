//
// Created by John on 26/03/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "game.h"

const char SPACE = '-';
const char X = 'X';
const char Y = 'Y';

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



    drawBanner();
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