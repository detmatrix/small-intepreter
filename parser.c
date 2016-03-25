#include "global.h"
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
int lookahead;
void match(int t);
extern void parse();
double expr();
double term();
double factor();
extern int lexan();
extern void error(char *m);
extern double result;
double update(double v1, double v2, char op) {
	switch (op)
	{
	case'+':return v1 + v2; break;
	case'-':return v1 - v2; break;
	case'*':return v1 * v2; break;
	case'/':if (v2 != 0) return v1 / v2;
			else error("divided by zero"); return 0;
			break;
	default:error("unknown command"); return 0;
		break;
	}
}


extern void parse()
{

	lookahead = lexan();
	while (lookahead != DONE) {
		result += expr();
		match(';');
		printf(" =%lf\n", result);
	}
}

double expr()
{
	double t, val_1, val_2, result_exp = 0;
	result_exp = val_1 = term();
	while (1) {
		switch (lookahead) {
		case '+':case'-':
			t = lookahead;
			match(lookahead);
			val_2 = term();
			result_exp = update(val_1, val_2, t);   /*to do*/
			continue;
		default:
			return result_exp;
		}
	}
}

double term()
{
	double t, val_1, val_2, result_term = 0;
	val_1 = factor();
	result_term = val_1;
	while (1) {
		switch (lookahead) {
		case '*':case '/':
			t = lookahead;
			match(lookahead);
			val_2 = factor();
			result_term = update(val_1, val_2, t);
			continue;
		default:

			return result_term;
		}
	}
}
double factor()
{
	double val_1, val_2, result_factor = 0;
	switch (lookahead) {
	case '(':
		match('('); result_factor = expr(); match(')'); return result_factor;
	case NUM:
		result_factor = tokenval; match(NUM); return result_factor;
	case POW:
		match(POW); match('('); val_1 = tokenval; match(NUM); match(','); val_2 = tokenval; match(NUM); match(')');
		result_factor = pow(val_1, val_2);
		return result_factor;
	case SIN:
		match(SIN); match('('); val_1 = tokenval; match(NUM);  match(')'); 
		result_factor = sin(val_1);/*todo : double case*/
		return result_factor;
	default:
		error("syntax error"); return 0;    /*unnecessary to return value*/
	}
}

void match(int t)
{
	if (lookahead == t)
		lookahead = lexan();
	else error("syntax error");
} 
