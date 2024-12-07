#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//deklarasi tipe data baru bernama dataplayer
typedef struct {
    int skor; 
    char nama[15];
} dataplayer;

void inputscore(dataplayer input)
{
    FILE* forinput = fopen("datahighscore.txt", "ab+");

    if(forinput == NULL)
    {
        perror("File tidak bisa diakses");
        exit(1);
    }

    fwrite(&input, sizeof(dataplayer), 1, forinput);
    fclose(forinput);
}

void sorting(dataplayer data[], int y)
{
    dataplayer tmpData;
    int a, b;

    for(a = 0; a < y-1; a++)
    {
        for(b = 0;  b < y-1; b++)
        {
            if(data[b+1].skor > data[b].skor)
            {
                tmpData = data[b];
                data[b] = data[b+1];
                data[b+1] = tmpData;
            }
        }
    }
}

void tampil()
{
    dataplayer tampscore[100];
    int x, y = 0;

    FILE* filein = fopen("datahighscore.txt", "rb");

    if(filein == NULL)
    {
        perror("File highscore tidak ditemukan!");
        sleep(1);
        return; 
    }
    else
    {
        while(fread(&tampscore[y], sizeof(dataplayer), 1, filein))
            y++;

        fclose(filein);

        sorting(tampscore, y);
        
        printf("\t\b\b\b#=================================#\n");
        printf("\t\b\b\b|           Leaderboard           |\n");
        printf("\t\b\b\b#=================================#\n\n");
        printf("\t\b\b\b#====#=================#==========#\n");
        printf("\t\b\b\b| No | Nama            | Skor     |\n");
        printf("\t\b\b\b#====#=================#==========#\n");
        for(x = 0; x < y; x++)
            printf("\t\b\b\b| %-2d | %-15s | %-8d |\n", x+1, tampscore[x].nama, tampscore[x].skor);
        printf("\t\b\b\b#====#=================#==========#\n");
    }

    fclose(filein);
}
