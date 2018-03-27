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

    //struct game* pGameInfo = malloc(sizeof(struct game));
    struct game* pGameInfo = malloc(sizeof(struct game));//initialiseGame();//= malloc(sizeof(struct game));

    char *name1 = "John";
    char *name2 = "Emma";

    initialiseGame( pGameInfo, name1, name2);
    printf("size: %d\n", sizeof(pGameInfo));

    for(int i=0;i<2;i++){
        printf("Name%d: ",i+1);
        for(int j=0;j<5;j++){
            printf("%c--",pGameInfo->playerNames[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c",pGameInfo->board[i][j]);
        }
        printf("\n");
    }
    free(pGameInfo);
}

void initialiseGame(struct game* pGameInfo, char* name1, char* name2){
    pGameInfo->finished = False;
    pGameInfo->status = (int)malloc(sizeof(int));
    *pGameInfo->playerNames[0] = (char)malloc(sizeof(name1));
    *pGameInfo->playerNames[1] = (char)malloc(sizeof(name2));
    *pGameInfo->playerNames[0] = *name1;
    *pGameInfo->playerNames[1] = *name2;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            pGameInfo->board[i][j] = SPACE;
        }
    }

}