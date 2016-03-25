#include "global.h"
#include <string.h>
#define LASTENTRY 2

entry symtable[LASTENTRY + 1] = {
	0, 0,
	"pow",POW,
	"sin",SIN,

};
extern void error(char *m);
int lookup(char s[])
{
	int p;
	for (p = LASTENTRY; p > 0; p--)
		if (strcmp(symtable[p].lexptr, s) == 0)
			return p;
	return 0;
}

