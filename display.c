#include <stdio.h>

// Untuk modul display papan dan display highscore ada di file masing-masing

void displayTitle()
{
    printf("\n  _______  ________  ___   ___  ________     ");
    printf("\n /  ___  \\|\\   __  \\|\\  \\ |\\  \\|\\   __  \\    ");
    printf("\n/__/|_/  /\\ \\  \\|\\  \\ \\  \\\\_\\  \\ \\  \\|\\  \\   ");
    printf("\n|__|//  / /\\ \\  \\\\\\  \\ \\______  \\ \\   __  \\  ");
    printf("\n    /  /_/__\\ \\  \\\\\\  \\|_____|\\  \\ \\  \\|\\  \\ ");
    printf("\n   |\\________\\ \\_______\\     \\ \\__\\ \\_______\\ ");
    printf("\n    \\|_______|\\|_______|      \\|__|\\|_______|\n");
}

void displayMainMenu()
{
    printf("\n\t  #=========(2048)=========#\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  |\t(p) Play\t   |\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  |\t(h) Highscore\t   |\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  |\t(q) Quit\t   |\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  #========================#\n");
}

void displayPlayMenu()
{
    printf("\n\t  #=========(2048)=========#\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  |\t(n) New game\t   |\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  |\t(l) Load previous game\t   |\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  |\t(b) Back to main menu\t   |\n");
    printf("\t  |\t\t\t   |\n");
    printf("\t  #========================#\n");
}

void displayHelpMenu()
{
    printf("\n\t\b\b#=========#======================#");
    printf("\n\t\b\b| Kontrol | Kegunaan             |");
    printf("\n\t\b\b#=========#======================#");
    printf("\n\t\b\b|   (w)   | Menggerakan ke atas  |");
    printf("\n\t\b\b|   (a)   | Menggerakan ke kiri  |");
    printf("\n\t\b\b|   (s)   | Menggerakan ke bawah |");
    printf("\n\t\b\b|   (d)   | Menggerakan ke kanan |");
    printf("\n\t\b\b|   (r)   | Mengulang game       |");
    printf("\n\t\b\b#=========#======================#\n");
}

void displayWin()
{
    printf("\n\t██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗██╗██╗");
    printf("\n\t╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║██║██║");
    printf("\n\t ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║██║██║");
    printf("\n\t  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║╚═╝╚═╝");
    printf("\n\t   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║██╗██╗");
    printf("\n\t   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝╚═╝\n");
}

void displayGameOver()
{
    printf("\n\t ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ ");
    printf("\n\t██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗");
    printf("\n\t██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝");
    printf("\n\t██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██ ");
    printf("\n\t╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║");
    printf("\n\t ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");    
}
