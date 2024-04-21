#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 6
#define COLUMNS 7
#define EMPTY_SLOT ' '
#define RED_DISC '*'
#define YELLOW_DISC 'o'

char slots[] = {YELLOW_DISC, RED_DISC, EMPTY_SLOT};
bool wantToRestart;
char grid[ROWS][COLUMNS];

void clearConsole() {
    printf("\033[2J\033[1;1H");
}

void initializeGrid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) 
            grid[i][j] = EMPTY_SLOT;
    }
}

void displayGrid() {
    printf("  1 2 3 4 5 6 7\n");
    for (int i = 0; i < ROWS; ++i) {
        printf("%d ", i + 1); // Print row number
        for (int j = 0; j < COLUMNS; ++j) printf("%c ", grid[i][j]); // Print grid content
        printf("%d\n", i + 1); // Print row number
    }
    // Print bottom column numbers
    printf("  1 2 3 4 5 6 7\n\n");
}


bool isMovePossible(int column) {
    return column >= 1 && column <= COLUMNS && grid[0][column - 1] == EMPTY_SLOT;
}

void dropDisc(int column, char disc) {
    int row = ROWS - 1;
    while (grid[row][column - 1] != EMPTY_SLOT) {
        --row;
    }
    grid[row][column - 1] = disc;
}

int countAlignedDisc(int row, int column, char disc) {
    int count = 0;

    // Check horizontally
    for (int i = column - 3; i <= column + 3; ++i) {
        if (i >= 0 && i + 3 < COLUMNS && grid[row][i] == disc && grid[row][i + 1] == disc &&
            grid[row][i + 2] == disc && grid[row][i + 3] == disc) {
            ++count;
        }
    }

    // Check vertically
    for (int i = row - 3; i <= row + 3; ++i) {
        if (i >= 0 && i + 3 < ROWS && grid[i][column] == disc && grid[i + 1][column] == disc &&
            grid[i + 2][column] == disc && grid[i + 3][column] == disc) {
            ++count;
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int i = -3; i <= 3; ++i) {
        if (row + i >= 0 && row + i + 3 < ROWS && column + i >= 0 && column + i + 3 < COLUMNS &&
            grid[row + i][column + i] == disc && grid[row + i + 1][column + i + 1] == disc &&
            grid[row + i + 2][column + i + 2] == disc && grid[row + i + 3][column + i + 3] == disc) {
            ++count;
        }
    }

    // Check diagonally (top-right to bottom-left)
    for (int i = -3; i <= 3; ++i) {
        if (row - i >= 0 && row - i - 3 < ROWS && column + i >= 0 && column + i + 3 < COLUMNS &&
            grid[row - i][column + i] == disc && grid[row - i - 1][column + i + 1] == disc &&
            grid[row - i - 2][column + i + 2] == disc && grid[row - i - 3][column + i + 3] == disc) {
            ++count;
        }
    }
    return count;
}

int recommendColumn() {
    srand(time(NULL));
    int column;
    do {
        column = rand() % COLUMNS;
    } while (!isMovePossible(column));
    return column;
}

bool isGameOver() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (grid[i][j] != EMPTY_SLOT) {
                char disc = grid[i][j];
                if (countAlignedDisc(i, j, disc) > 0) 
                    return true;
            }
        }
    }
    return false;
}

bool isGridFull() {
    for (int i = 0; i < COLUMNS; ++i) {
        if (grid[0][i] == EMPTY_SLOT) 
            return false;
    }
    return true;
}

void setTurn(int *turn){
    *turn = 1 - *turn;
}
