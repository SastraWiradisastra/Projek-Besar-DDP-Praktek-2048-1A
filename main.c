/*
oleh qinthara azizah tsurayya
- ukuran board input user
- tile baru acak
- tile baru bisa 2/4
*/
#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include "papan.h"
#include "save.h"

int main() {
    int board[u][u];
    char input;
    bool moved;

    for(;;)
    {
        printf("\e[?25l");
        system("cls");
        printf("\n==============(2048)=============\n");
        printf("|\t(p) Play\t\t|\n");
        printf("|\t(h) Display Highscore\t|\n");
        printf("|\t(q) Quit\t\t|\n");
        printf("=================================\n");
        input = getch();

        init(board);
        switch(input)
        {
            case 'p':
                while (true) 
                {
                    system("cls"); //"cls" windows, "clear" linux
                    displayBoard(board);

                    if (isGameOver(board) == true) {
                        extern int jumlahskor;
                        printf("Game Over!\n");
                        printf("Skor terkakhir: %d\n", jumlahskor);
                        sleep(3);
                        break;
                    }

                    input = getch();

                    if (input == 'w' || input == 'a' || input == 's' || input == 'd' ||
                        input == 'W' || input == 'A' || input == 's' || input == 'D') {
                        moved = move(board, input);
                        if (moved) {
                            addNewTile(board);
                        }
                    }
                    else if(input == 'b' || input == 'B')
                    {
                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("Invalid move! Please enter w/a/s/d.\n");
                        sleep(1);
                        continue;
                    }
                }
                break;
            case 'h':
                system("cls");
                sorting();
                break;
            case 'q':
                system("cls");
                exit(0);
            default:
                system("cls");
                printf("Input invalid, silahkan coba lagi.");
                sleep(1);
                break;
        }
    }
    return 0;
}

