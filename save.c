#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//deklarasi tipe data baru bernama dataplayer
typedef struct {int skor; char nama[15];} dataplayer;

void inputscore(dataplayer input)
{
    FILE* forinput = fopen("datahighscore.txt", "a+");

    if(forinput == NULL)
    {
        perror("File tidak bisa diakses");
        exit(1);
    }

    fprintf(forinput, "%d %s\n", input.skor, input.nama);
    fclose(forinput);
}

void tampil()
{
    dataplayer tampscore;

    FILE* filein = fopen("datahighscore.txt", "r");

    if(filein == NULL)
    {
        perror("File tidak dapat dibuka");
        exit(1);
    }

    printf("Score\tNama");

    while(!feof(filein))
    {
        fscanf(filein, "%d %s", &tampscore.skor, &tampscore.nama);
        printf("%d\t%s\n", tampscore.skor, tampscore.nama);
    }

    fclose(filein);
}

void sorting()
{
    //input local
    long i = 0, j;
    dataplayer yangdibaca, temp;
    FILE* baca = fopen("datahighscore.txt","r+");

    if (baca == NULL)
    {
        perror("File tidak bisa diakses");
        sleep(3);
        return;
    }

    while(!feof(baca))
    {
        fseek(baca, (i*(sizeof(dataplayer)+1))+i, SEEK_SET);
        fscanf(baca, "%d %s", &yangdibaca.skor, &yangdibaca.nama);
            j = i;
            while (!feof)
            {
                j++;
                fseek(baca, (j*(sizeof(dataplayer)+1))+j, SEEK_SET);
                fscanf(baca, "%d %s", &temp.skor, &temp.nama);

                if((yangdibaca.skor < temp.skor) || (yangdibaca.skor == temp.skor))
                {
                    fseek(baca, (i*(sizeof(dataplayer)+1))+i, SEEK_SET);
                    fprintf(baca, "%d %s", temp.skor, temp.nama);
                    fseek(baca, (j*(sizeof(dataplayer)+1))+j, SEEK_SET);
                    fprintf(baca, "%d %s", yangdibaca.skor, yangdibaca.nama);
                    strcpy(yangdibaca.nama, temp.nama);
                }

                if(i < j)
                {
                    fseek(baca, 0, SEEK_SET);
                    i++;
                }
            }
    }

    fclose(baca);
    tampil();
}
