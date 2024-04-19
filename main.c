#include <stdio.h>
#include "connect4.h"

int main(){
    do {
        int colorChoise = 0; //choise of turn at the start of the game
        int turnChoise = 0; //choise of turn at the start of the game
        do { // safety defining of colors, to not get any wrong information
            printf("Choose your color([1] - Yellow, [2] - Red): ");
            scanf("%d", &colorChoise);
        } while (colorChoise != 1 && colorChoise != 2);
        if (colorChoise == 1){
            playerColor = Yellow;
            computerColor = Red;
        } 
        else {
            playerColor = Red;
            computerColor = Yellow;
        } 

        do { // safety defining of starting choise, to not get any wrong information
            printf("Choose the first player([1] - You, [2] - Computer): ");
            scanf("%d", &turnChoise);
        } while (turnChoise != 1 && turnChoise != 2);
        if(turnChoise == 1) turn = playerColor;
        else turn = computerColor;

        initGrid();
        dropDisk(2);
        dropDisk(2);
        showGrid();
        setTurn();
        isPlaying = false;
    } while (isPlaying);
    return 0;
}