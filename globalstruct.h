#ifndef GLOBALSTRUCT_H
#define GLOBALSTRUCT_H

typedef struct papan {
	int tiles [MAXWIDHT][MAXLEN];
};

typedef struct scoring {
	int currScore;
	int highScore;
	int penambahanPoin;
};

typedef struct koordinat {
	int x, y;
};

#endif
