#include <stdio.h>

// Check if it's safe to place a number in a cell
int isSafe(int board[9][9], int row, int col, int num) {
    // Check if the number is not already present in the current row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    // Check if the number is not already present in the current 3x3 subgrid
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Solve the Sudoku puzzle using backtracking
int solveSudoku(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            board[row][col] = 0;
                            return 1;
                        }
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (solveSudoku(board)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
