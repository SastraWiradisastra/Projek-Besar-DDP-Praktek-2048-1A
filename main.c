/*
oleh qinthara azizah tsurayya
- ukuran board input user
- tile baru acak
- tile baru bisa 2/4
*/

#include <stdio.h>
#include <stdlib.h>
#include "papan.h"

int main() {
    int size;
    char input;
    bool moved;
    initializeBoard(board, size);

    while (true) {
        system("cls"); //"cls" windows, "clear" linux
        displayBoard(board, size);

        if (isGameOver(board, size)) {
            printf("Game Over! Try again.\n");
            break;
        }

        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &input);

        moved = move(board, size, input);
        if (moved) {
            addNewTile(board, size);
        }
    }

    i = 0; 
    while (i < size) {
        free(board[i]);
        i++;
    }
    free(board);

    return 0;
}
