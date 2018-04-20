#include <stdio.h>
#include "game.h"

int main(int argc, char* argv[]) {
    for(int i=0;i<argc;i++){
        printf("------%s\n", argv[i]);
    }
    printf("argc: %d\n",argc);

    char* pName1 = NULL;
    char* pName2 = NULL;
    if(argc > 2) {
        pName1 = argv[1];
        pName2 = argv[2];
    }

    playGame(pName1,pName2);
    return 0;
}