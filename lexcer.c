#include "global.h"


char lexbuf[BSIZE];
int lineno = 1;
double tokenval = NONE;    /* todo : double support*/

extern int lookup(char s[]);
extern void error(char *m);

int lexan()
{
	int t;
	while (1) {
		t = getchar();
		if (t == ' ')
			;
		else if (t == '\n') {
			lineno++;
			return DONE;
		}

		else if (isdigit(t)) {     /*num case*/
			ungetc(t, stdin);
			scanf_s("%lf", &tokenval);
			return NUM;
		}
		else if (isalpha(t)) {       /*pow & sin case*/
			int p, b = 0;
			while (isalpha(t)) {
				lexbuf[b++] = t;
				t = getchar();
				if (b >= BSIZE)
					error("comiler error:no enough space in lexbuf");
			}
			lexbuf[b] = '\0';
			if (t != EOF)
				ungetc(t, stdin);
			p = lookup(lexbuf);
			if (p == 0)
				error("unknown command");
			tokenval = p;
			return symtable[p].token;
		}
		else if (t == EOF)     /*EOF case*/
			return DONE;
		else {                    /* operand case */
			tokenval = NONE;
			return t;
		}
	}
}