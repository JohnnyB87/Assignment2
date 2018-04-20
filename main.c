#include <stdio.h>
#include <mem.h>
#include "game.h"

int main(int argc, char* argv[]) {
    for(int i=0;i<argc;i++){
        printf("------%s\n", argv[i]);
    }
    printf("argc: %d\n",argc);

    char pName1[MAX_NAME_LEN] = {NULL};
    char pName2[MAX_NAME_LEN] = {NULL};
    if(argc > 2) {
        strcpy(pName1,argv[1]);
        strcpy(pName2,argv[2]);
        printf("pNAME1: %s   pName2: %s   argv[1]: %s   argv[2]: %s\n\n",pName1,pName2,argv[1],argv[2]);
    }

    playGame(pName1,pName2);
    return 0;
}