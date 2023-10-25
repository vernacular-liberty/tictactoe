#include <stdio.h>
#include <stdlib.h>

void printBoard(char board[][3]){
    printf("-------------\n");
    int i;
    for(i = 0; i < 3; i++){
        printf("| %c | %c | %c |\n", board[i][0], board[i][1],board[i][2]);
        printf("-------------\n");
    }
}

void isNegative(int inputColumn, int inputRow){
    if(inputColumn == -1 || inputRow == -1) exit(0);
}

int isValidMove(char board[][3], int inputRow, int inputColumn) {
    // Check if the move is within the valid range (0 to 2)
    if (inputRow < 0 || inputRow > 2 || inputColumn < 0 || inputColumn > 2 || board[inputRow][inputColumn] != ' ') {
        printf("Incorrect value, try again.\n");
        return 0;
    }
    return 1; // Move is valid
}

int playerOneWon(char board[][3]){
    int won = 0;
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') won = 1;
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') won = 1;
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') won = 1;
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') won = 1;
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') won = 1;
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') won = 1;
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') won = 1;
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') won = 1;

    if (won == 1){
        printf("Player 1 is the winner.\n");
        printBoard(board);
    }
    return won;
}

int playerTwoWon(char board[][3]){
    int won = 0;
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') won = 1;
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') won = 1;
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') won = 1;
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') won = 1;
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') won = 1;
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') won = 1;
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') won = 1;
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') won = 1;
    if (won == 1){
        printf("Player 2 is the winner.\n");
        printBoard(board);
    }
    return won;
}

int main(){
    //initialize variables
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char play;
    int inGame = 0;

    while (play != 'n' && play != 'y'){
        printf("Output Play (y/n):\n");
        scanf("%c", &play);
        printf("You entered %c.\n", play);
        printf("Starting game with 3 x 3 board.\n");

        printf("Each player should enter\na row and col num (eg: 2 0).\n");

        while (inGame == 0){
            int inputRow;
            int inputColumn;
            int isValid1 = 0;
            int isValid2 = 0;

            //p1
            while (isValid1 == 0){
                printf("Player 1:\n");
                scanf(" %d %d", &inputRow, &inputColumn);
                isNegative(inputRow, inputColumn);
                if (isValidMove(board, inputRow, inputColumn) == 0) {
                    continue;
                } else {
                    isValid1 = 1;
                }
                printf("Player 1 entered %d %d.\n", inputRow, inputColumn);
                board[inputRow][inputColumn] = 'O';
                if (play == 'y') printBoard(board);
            }
            if (playerOneWon(board) == 1) break;

            //p2
            while (isValid2 == 0){
                printf("Player 2:\n");
                scanf(" %d %d", &inputRow, &inputColumn);
                isNegative(inputRow, inputColumn);
                if (isValidMove(board, inputRow, inputColumn) == 0){
                    continue;
                } else{
                    isValid2 = 1;
                }
                printf("Player 2 entered %d %d.\n", inputRow, inputColumn);
                board[inputRow][inputColumn] = 'X';
                if (play == 'y') printBoard(board);
            }
            if (playerTwoWon(board) == 1) break;
        }
    }
}