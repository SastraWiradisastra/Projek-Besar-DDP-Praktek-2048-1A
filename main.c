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
                static bool win = false, cont = false;
                while (true) 
                {            
                    system("cls");
                    displayTitle();
                    printf("\n\tTekan (h) untuk panduan kontrol\n");
                    printf("\n\tTekan (b) untuk kembali ke main menu\n");
                    displayBoard(board);
                    char player_name[maks];
                    int score = 0;
                    printf("Masukkan nama Anda: ");
                    fgets(player_name, maks, stdin);
                    player_name[strcspn(player_name, "\n")] = 0; //nah

                    if (isWin(board) == true && win == false)
                    {
                        win = true;
                        system("cls");
                        displayWin();
                        printf("\tLanjutkan permainan (y/n)?\n");
                        input = getch();

                        while(input != 'y')
                        {
                            if(input == 'n')
                            {
                                return cont = true;
                                break;
                            }
                            else
                            {
                                printf("\t\nInput invalid! Silahkan coba lagi.");
                                input = getch();
                                continue;
                            }
                        }

                        if(input == 'y')
                            continue;
                    }

                    if (isGameOver(board) == true || cont == true) {
                        extern int jumlahskor;
                        dataplayer finalscore;
                        finalscore.skor = jumlahskor;
                        jumlahskor = 0;
                        
                        system("cls");
                        displayGameOver();
                        printf("\tSkor terkakhir\t\t: %d\n", finalscore.skor);
                        printf("\tMasukan nama anda\t: ");
                        scanf("%s", finalscore.nama);

                        inputscore(finalscore);

                        printf("\n\t#===============================#");
                        printf("\n\t| Skor telah berhasil disimpan! |");
                        printf("\n\t#===============================#\n");
                        
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
                    else if(input == 'r' || input == 'R')
                    {
                        extern int jumlahskor;
                        jumlahskor = 0;
                        init(board);
                    }
                    else if(input == 'b' || input == 'B')
                    {
                        extern int jumlahskor;
                        jumlahskor = 0;
                        break;
                    }
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
