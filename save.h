#ifndef SAVE_H
#define SAVE_H
#define maks 10
typedef struct {
    int skor; 
    char nama[15];
} dataplayer;

void inputscore(dataplayer input);
void save_score(const char *player, int score);
void tampil();
void sorting();

#endif
