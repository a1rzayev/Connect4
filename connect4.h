//includes
#include <stdbool.h>

//defined constants
#define RED_DISKS 21
#define YELLOW_DISKS 21
#define ROWS 6
#define COLUMNS 7 

//alignment that use for show direction of collected align elements
enum AlignmentEnum{
    N = 0,//North
    NE = 45,//North-East
    E = 90,//East
    SE = 135,//South-East
    S = 180,//South
    SW = 225,//South-West
    W = 270,//West
    NW = 315//North-West
};

//value of slot, placing in grid
enum SlotEnum {
    Empty = 32,//32 is a space in ASCII
    Red = 42,//42 is '*' in ASCII
    Yellow = 111//111 is 'o' in ASCII
};

//enum of turns
// enum TurnEnum {
//     RedTurn = 42,//42 is '*' in ASCII
//     YellowTurn = 111//111 is 'o' in ASCII
// };

// typedef struct(class) used for recognise in-game situation
typedef struct {
    enum AlignmentEnum alignment;
    int length; 
} Alignment;

bool isPlaying = true; //if the game is played
enum SlotEnum computerColor; 
enum SlotEnum playerColor;
enum SlotEnum turn; //turn in game
enum SlotEnum grid[ROWS][COLUMNS]; //grid of slots(6x7)
Alignment computerAlignments[21];
Alignment playerAlignments[21];

//shows grid
void showGrid(){
    printf(" ");
    for (int c = 0; c < COLUMNS; ++c) printf(" %d", c+1);

    for (int i = ROWS-1; i >= 0; --i) {
        printf("\n");
        printf("%d ", i+1);
        for (int j = 0; j < COLUMNS; ++j) printf("%c ", (char)grid[i][j]);
        printf("%d", i+1);
    }

    printf("\n ");
    for (int c = 0; c < COLUMNS; ++c) printf(" %d", c+1);
}

//initializes grid
void initGrid(){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            grid[i][j] = Empty;
        } 
    }
}

//checks if move is possible
bool isPossibleMove(int column){
    if (grid[5][column] == Empty) return true;
    return false;
}

//drops a disc
bool dropDisk(int column){
    if(isPossibleMove(column-1)){
        for (int row = 0; row < ROWS; ++row) {
            if(grid[row][column-1] == Empty){
                grid[row][column-1] = turn;
                break;
            }
        }  
        return true;
    }
    return false;
}

//sets turn
void setTurn(){
    if(turn == Yellow) turn == Red;
    else turn == Yellow;
}

//
Alignment checkAlignment(){
    Alignment alignment;
    alignment.length = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if(grid[i][j] != Empty) {
                for(int d = 0; d < 360; d = d+45){
                    //for(int r )
                }
                while (isPossibleMove(j) && grid[i][j] == turn) {
                    alignment.length++;
                    // row += dRow;
                    // col += dCol;
                }
            }
        }
    }
    return alignment;
}
