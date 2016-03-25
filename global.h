#include <stdio.h>
#include <ctype.h>
#define BSIZE 128 /*size of buffer*/
#define NONE -1

#define NUM 256
#define POW 257
#define SIN 258
#define ID 259
#define DONE 260

double tokenval;
int lineno;

typedef struct {
	char *lexptr;
	int token;
}entry;
entry symtable[];