#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define u 4

int jumlahskor = 0;

void addNewTile(int board[u][u]);

void init(int board[u][u]) {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            board[i][j] = 0;
            j++;
        }
        i++;
    }
    addNewTile(board);
    addNewTile(board);
}

void displayBoard(int board[u][u]) {
    int i = 0;
    printf("\n\t#======#======#======#======#\n");
    while (i < 4) {
        int j = 0;
        printf("\t|      |      |      |      |\n");
        printf("\t|");
        while(j < 4)
        {
            if(board[i][j] != 0)
                printf(" %-4d |", board[i][j]);
            else
                printf("      |");
            j++;
        }
        printf("\n\t|      |      |      |      |\n");
        printf("\t#======#======#======#======#\n");
        i++;
    }
    
    printf("\n\t#=============#=============#\n");
    printf("\t| Skor        | %11d |", jumlahskor);
    printf("\n\t#=============#=============#\n");
}

bool isGameOver(int board[u][u]) {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            if (board[i][j] == 0) {return false;}
            if (i > 0 && board[i][j] == board[i - 1][j]) {return false;}
            if (j > 0 && board[i][j] == board[i][j - 1]) {return false;}
            j++;
        }
        i++;
    }
    return true;
}

bool isWin(int board[u][u]) {
	int i = 0;
	while (i < 4) {
		int j = 0;
		while (j < 4) {
			if (board[i][j] == 2048) {return true;}
			j++;
		}
		i++;
	}
	return false;
}

bool check(int board[u][u]) {
    bool hasMoved = false;
    for (int i = 0; i < u; i++) {
        int lastMergeCol = -1;
        for (int j = 1; j < u; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            int k = j - 1;
            while (k >= 0 && board[i][k] == 0) k--;

            if (k >= 0 && board[i][k] == board[i][j] && lastMergeCol != k) {
                board[i][k] *= 2; 
                board[i][j] = 0; 
                hasMoved = true;
                lastMergeCol = k;
                jumlahskor += board[i][k];
            } else if (k + 1 != j) {
                board[i][k + 1] = board[i][j];
                board[i][j] = 0;
                hasMoved = true;
            }
        }
    }
    return hasMoved;
}

void transpose(int board[u][u]) {
    for (int i = 0; i < u; i++) {
        for (int j = i + 1; j < u; j++) {
            int temp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = temp;
        }
    }
}

void reverseRows(int board[u][u]) {
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < u / 2; j++) {
            int temp = board[i][j];
            board[i][j] = board[i][u - 1 - j];
            board[i][u - 1 - j] = temp;
        }
    }
}

bool move(int board[u][u], char direction) {
    bool moved = false;

    if (direction == 'w' || direction == 'W') {
        transpose(board);
        moved = check(board);
        transpose(board);
    } else if (direction == 'a' || direction == 'A') {
        moved = check(board);
    } else if (direction == 's' || direction == 'S') {
        transpose(board);
        reverseRows(board);
        moved = check(board);
        reverseRows(board);
        transpose(board);
    } else if (direction == 'd' || direction == 'D') {
        reverseRows(board);
        moved = check(board);
        reverseRows(board);
    }

    return moved;
}

void addNewTile(int board[u][u]) {
    int empty[u * u][2]; 
    int emptyCount = 0;

    for (int i = 0; i < u; i++) {
        for (int j = 0; j < u; j++) {
            if (board[i][j] == 0) {
                empty[emptyCount][0] = i;
                empty[emptyCount][1] = j; 
                emptyCount++;
            }
        }
    }

    if (emptyCount == 0) {
        return;
    }
    
    int choice = rand() % emptyCount;
    int randomValue = rand() % 10;
    int value = (randomValue < 9) ? 2 : 4; 
    board[empty[choice][0]][empty[choice][1]] = value;
}
