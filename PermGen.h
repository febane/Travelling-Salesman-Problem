#include <stdio.h>
#include <stdlib.h>

typedef struct permGen {
	int *clock;
	int *check;
	int *perm;
	int dim;
} PermGen;

PermGen* criarPermGen(int n);
int step(PermGen* pg);
void reset(PermGen* pg);
void printPerm(PermGen* pg);
int *getPerm(PermGen* pg);
void liberarPerm(PermGen* pg);


