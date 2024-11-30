#include "papan.h"
#include <stdio.h>
#include <stdlib.h>

void initializeBoard(int board[u][u]) {
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            board[i][j] = 0;
            j++;
        }
        i++;
    }
    addNewTile(board, size);
    addNewTile(board, size);
}

void displayBoard(int board[u][u]) {
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            printf("%4d ", board[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

bool isGameOver(int board[u][u]) {
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            if (board[i][j] == 0) return false;
            if (i > 0 && board[i][j] == board[i - 1][j]) return false;
            if (j > 0 && board[i][j] == board[i][j - 1]) return false;
            j++;
        }
        i++;
    }
    return true;
}
void transpose(int *board[u][u]) {
        int i = 0;
        while (i < size) {
            int j = i + 1;
            while (j < size) {
                int temp = b[i][j];
                b[i][j] = b[j][i];
                b[j][i] = temp;
                j++;
            }
            i++;
        }
    }
void reverseRows(int *board[u][u]) {
        int i = 0;
        while (i < size) {
            int j = 0;
            while (j < size / 2) {
                int temp = b[i][j];
                b[i][j] = b[i][size - 1 - j];
                b[i][size - 1 - j] = temp;
                j++;
            }
            i++;
        }
    }
void check(int board[u][u], int *jumlahscore) {
        bool hasMoved = false;
        int i = 0;
        while (i < size) {
            int lastMergeCol = -1;
            int j = 1;
            while (j < size) {
                if (b[i][j] == 0) {
                    j++;
                    continue;
                }
                int k = j - 1;
                while (k >= 0 && b[i][k] == 0) k--;

                if (k >= 0 && b[i][k] == b[i][j] && lastMergeCol != k) {
                    b[i][k] *= 2;
                    b[i][j] = 0; //kembali
                    hasMoved = true;
                    lastMergeCol = k;
                    jumlahscore = b[i][k];
                } else if (k + 1 != j) {
                    b[i][k + 1] = b[i][j];
                    b[i][j] = 0;
                    hasMoved = true;
                }
                j++;
            }
            i++;
        }
        return hasMoved;
    }

bool move(int board[u][u], char direction) {
    bool moved = false;

    if (direction == 'w') {
        transpose(&board, size);
        moved = check(&board, size);
        transpose(&board, size);
    } else if (direction == 'a') {
        moved = check(&board, size);
    } else if (direction == 's') {
        transpose(&board, size);
        reverseRows(&board, size);
        moved = check(&board, size);
        reverseRows(&board, size);
        transpose(&board, size);
    } else if (direction == 'd') {
        reverseRows(&board, size);
        moved = check(&board, size);
        reverseRows(&board, size);
    }

    return moved;
}

void addNewTile(int *board[u][u]) {
    int empty[size * size][2];
    int emptyCount = 0;
    int choice = rand() % emptyCount;
        int randomValue = rand() % 10;
        int value = (randomValue < 9 ) ? 2 : 4;
        board[empty[choice][0]][empty[choice][1]] = value;
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            if (board[i][j] == 0) {
                empty[emptyCount][0] = value;
                empty[emptyCount][1] = value;
                emptyCount++;
            }
            j++;
        }
        i++;
    }
}

int tampScore(int jumlahscore) {
	printf("Score: %d", jumlahscore);
}
