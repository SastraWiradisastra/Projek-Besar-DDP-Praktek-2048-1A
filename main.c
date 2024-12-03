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
    int board[u][u];
    char input;
    bool moved;

    init(board);

    while (true) {
        system("cls"); //"cls" windows, "clear" linux

        if (isGameOver(board)) {
            printf("Game Over!\n");
            break;
        }

        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &input);

        moved = move(board, input);
        if (moved) {
            addNewTile(board);
        }
    }

    return 0;
}
