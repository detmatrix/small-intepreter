#include"global.h"
#include <stdlib.h>
void error(char *m)
{
	fprintf(stdout, "line %d: %s\n", lineno, m);
	exit(1);
}