#include "connect4.h"

int main() {

    int currentPlayer; // 0 for human, 1 for computer
    int column;
    int timePlaying = 1;
    int startingPlayer; // 0 for human, 1 for computer
    int colorChoise; //choise of turn at the start of the game
    do
    {  //each game 
        clearConsole();
        initializeGrid();
        do { // safety defining of colors, to not get any wrong information
            printf("Choose your color([0] - Yellow, [1] - Red): ");
            scanf("%d", &colorChoise);
        } while (colorChoise != 1 && colorChoise != 0);

        if(timePlaying == 1){
            do { // safety defining of starting choise, to not get any wrong information
                printf("Choose the first player([0] - You, [1] - Computer): ");
                scanf("%d", &currentPlayer);
            } while (currentPlayer != 1 && currentPlayer != 0);
            startingPlayer = currentPlayer;
        }
        else {
            setTurn(&startingPlayer);
            currentPlayer = startingPlayer;
        }

        do  { //each turn
            displayGrid();
            if (currentPlayer) {
                column = recommendColumn();
                printf("Computer's turn (%s), column %d\n", ((colorChoise) ? "Yellow" : "Red"), column);
            } 
            else {
                printf("Your turn (%s), enter column number (1-7): ", ((colorChoise) ? "Red" : "Yellow"));
                scanf("%d", &column);
            }

            if (isMovePossible(column)) {
                dropDisc(column, ((currentPlayer) ?  slots[1-colorChoise] : slots[colorChoise]));
                setTurn(&currentPlayer);
            } else {
                printf("Invalid move! Try again.\n");
            }
        } while (!isGameOver() && !isGridFull());

        displayGrid();

        if (isGameOver()) printf("Game over! %s won!\n", ((currentPlayer) ? "You" : "Computer"));
        else printf("It's a draw!\n");

        do { // safety checking want to restart, to not get any wrong information
            printf("Do you want to play again?([0] - No, [1] - Yes): ");
            scanf("%d", &wantToRestart);
        } while (wantToRestart != 1 && wantToRestart != 0);
        ++timePlaying;
    } while (wantToRestart);
    clearConsole();
    printf("Thank you for playing!");
    return 0;
}
