#include <stdio.h>
#include "game.h"

int main(int argc, char* argv[]) {
    for(int i=0;i<argc;i++){
        printf("------%s\n", argv[i]);
    }
    printf("argc: %d\n",argc);
    playGame();
    return 0;
}