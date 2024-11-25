#ifndef PAPAN_H
#define PAPAN_H

#include <stdbool.h>
#define u 4

void init(int board[u][u]);
void displayBoard(int board[u][u]);
bool move(int board[u][u], char direction);
void addNewTile(int *board[u][u]);
bool isGameOver(int *board[u][u]);

#endif
