/*
oleh qinthara azizah tsurayya
- ukuran board input user
- tile baru acak
- tile baru bisa 2/4
*/
#include "papan.h"

int main() {
    int board[u][u];
    char input;
    bool moved;

    init(board);

    while (true) {
        system('clear'); //"cls" windows, "clear" linux
        displayBoard(board);

        if (isGameOver(board)) {
            printf("Game Over!\n");
            break;
        }

        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &input);
        if ((input != 'w' && input != 'a' && input != 's' && input != 'd') && (input != 'W' && input != 'A' && input != 'S' && input != 'D')) {
        printf("Invalid move! Please enter w/a/s/d.\n");
        continue;
        }

        moved = move(board, input);
        if (moved) {
            addNewTile(board);
        }
    }

    return 0;
}
