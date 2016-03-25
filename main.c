#include "global.h"
#include <stdlib.h>

double result;
extern void parse();
int main()
{
	result = 0;
	parse();          

	exit(0);
}