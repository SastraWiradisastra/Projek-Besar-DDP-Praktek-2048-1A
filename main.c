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
#include "display.h"

int main() {
    int board[u][u];
    char input;
    bool moved;

    for(;;)
    {
        printf("\e[?25l");
        system("cls");
        displayTitle();
        displayMainMenu();
        input = getch();

        init(board);
        switch(input)
        {
            case 'p':
                while (true) 
                {
                    system("cls");
                    displayTitle();
                    printf("\n\tTekan (h) untuk panduan kontrol\n");
                    printf("\n\tTekan (b) untuk kembali ke main menu\n");
                    displayBoard(board);

                    if (isGameOver(board) == true) {
                        extern int jumlahskor;
                        dataplayer finalscore;
                        finalscore.skor = jumlahskor;
                        jumlahskor = 0;
                        
                        printf("\n\tGame Over!\n");
                        printf("\tSkor terkakhir\t\t: %d\n", finalscore.skor);
                        printf("\tMasukan nama anda (Maks. 15 karakter)\t: ");
                        scanf("%s", finalscore.nama);
                        
                        inputscore(finalscore);

                        printf("\t\n#===============================#");
                        printf("\t\n| Skor telah berhasil disimpan! |");
                        printf("\t\n#===============================#\n");
                        sleep(1);

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
                    else if(input == 'r' || input == 'R')
                    {
                        extern int jumlahskor;
                        jumlahskor = 0;
                        init(board);
                    }
                    else if(input == 'b' || input == 'B')
                        break;
                    else if(input == 'h' || input == 'H')
                    {
                        while(input != 'b')
                        {
                            system("cls");
                            displayTitle();
                            printf("\n\t\b\bTekan (b) untuk kembali ke game\n");
                            displayHelpMenu();
                            input = getch();
                    
                            if(input != 'b')
                            {
                                printf("\nInput invalid! Silahkan coba lagi.");
                                sleep(1);
                            }
                        }
                    }
                    else
                    {
                        printf("\t\nInput invalid! Silahkan coba lagi.");
                        sleep(1);
                        continue;
                    }
                }
                break;
            case 'h':
                while(input != 'b')
                {
                    system("cls");
                    displayTitle();
                    printf("\n\t\b\b\bTekan (b) untuk kembali ke main menu\n\n");
                    tampil();
                    input = getch();
                    
                    if(input != 'b')
                    {
                        printf("\nInput invalid! Silahkan coba lagi.");
                        sleep(1);
                    }
                }
                break;
            case 'q':
                system("cls");
                exit(0);
            default:
                printf("\nInput invalid! Silahkan coba lagi.");
                sleep(1);
                break;
        }
    }
    return 0;
}
