#include <stdio.h>
#include <stdbool.h>

#define N 8 // You can change N for different board sizes

// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check left side of the row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        printBoard(board);
        return true; // Return true to print all solutions
    }

    bool hasSolution = false;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            hasSolution = solveNQueens(board, col + 1) || hasSolution;

            board[i][col] = 0; // Backtrack
        }
    }
    return hasSolution;
}

int main() {
    int board[N][N] = {0};
    if (!solveNQueens(board, 0)) {
        printf("No solution exists\n");
    }
    return 0;
}
