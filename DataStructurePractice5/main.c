#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Postfix calculator
#define MAX_EXPR 50
typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, logicalnot, power, eos, operand
} precedence;
/* isp and icp arrays -- index is value of precedence 
lparen, rparen, plus, minus, times, divide, mod, logicalnot, eos */
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 15, 16, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 15, 16, 0 };

int pow_int(int, int);
void postfix(char*, char*);
int eval(char*);
precedence getToken(char*, char*, int*);
char printToken(precedence);
void printStack_int_token();

// stack_int
int max_stack_size_int = 20; // 초기값
int max_stack_size_char = 20; // 초기값
int* stack_int;
int top_int = -1;
char* stack_char;
int top_char = -1;
void printStack_int();
void printStack_char();
void push_int(int);
void push_char(char);
int pop_int();
char pop_char();

int main() {
	stack_int = (int*)malloc(sizeof(int) * max_stack_size_int);
	stack_char = (char*)malloc(sizeof(char) * max_stack_size_char);
	
	/* 
	When you write expression, enclose number with ` and end the expression by ;
	Space will be ignored.
	EX) "`1`+`2`*`3`;"
	*/
	char expr[MAX_EXPR] = "!                                   `1    0   0`;";
	char new_expr[MAX_EXPR];
	int result;

	postfix(expr, new_expr);
	result = eval(new_expr);
	printf("result = %d\n", result);
}

void printStack_int() {
	int i;

	printf("stack_int = ");
	for (i = 0; i <= top_int; i++)
		printf("%d ", stack_int[i]);
	printf("\n");
}

void printStack_char() {
	int i;

	printf("stack_char = ");
	for (i = 0; i <= top_char; i++)
		printf("%c ", stack_char[i]);
	printf("\n");
}

void push_int(int item) {
	if (top_int >= max_stack_size_int - 1) {
		max_stack_size_int *= 2;
		stack_int = (int*)realloc(stack_int, sizeof(int) * max_stack_size_int);
		printf("stack_int extended. now stack_int size : %d\n", max_stack_size_int);
	}
	stack_int[++top_int] = item;
}

void push_char(char item) {
	if (top_char >= max_stack_size_char - 1) {
		max_stack_size_char *= 2;
		stack_char = (char*)realloc(stack_char, sizeof(char) * max_stack_size_char);
		printf("stack_char extended. now stack_char size : %d\n", max_stack_size_char);
	}
	stack_char[++top_char] = item;
}

int pop_int() {
	if (top_int == -1) {
		printf("stack_int is empty! pop_int doesn't be operated.\n");
		return;
	}
	return stack_int[top_int--];
}

char pop_char() {
	if (top_char == -1) {
		printf("stack_char is empty! pop_char doesn't be operated.\n");
		return;
	}
	return stack_char[top_char--];
}

int pow_int(int base, int exponent) {
	int i;
	int result = 1;
	for (i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}

void postfix(char* expr, char* new_expr) {
	/*
	output the postfix of the expression.
	The expression string, the stack_int, and top_int are global.
	*/
	printf("postfix() operated.\n");

	char symbol;
	precedence token;
	int i, j;
	int n = 0;
	int idx = 0;
	top_int = -1;

	/* eliminate spaces between expression */
	for (i = 0; i < MAX_EXPR; i++) {
		if (expr[i] == ' ') {
			for (j = i; j < MAX_EXPR - 1; j++) {
				expr[j] = expr[j + 1];
				i--;
			}
		}
	}

	push_int(eos); /* place eos on stack_int */
	for (token = getToken(expr, &symbol, &n); token != eos; token = getToken(expr, &symbol, &n)) {
		if (token == operand) {
			new_expr[idx++] = symbol;
			do {
				token = getToken(expr, &symbol, &n);
				new_expr[idx++] = symbol;
			} while (symbol != '`');
		}
		else if (token == rparen) {
			/* unstack_int tokens until left parenthesis */
			while (stack_int[top_int] != lparen)
				new_expr[idx++] = printToken(pop_int());
			pop_int(); /* discard the left parenthesis */
		}
		else {
			/* remove and print symbols whose isp is greater than or equal to the current token's icp */
			while (isp[stack_int[top_int]] >= icp[token])
				new_expr[idx++] = printToken(pop_int());
			push_int(token);
		}

		printStack_int_token();
		printf("new_expr = ");
		for(int i = 0; i < idx; i++)
			printf("%c ", new_expr[i]);
		printf("\n");
	}
	while ((token = pop_int()) != eos) {
		new_expr[idx++] = printToken(token);

		printStack_int_token();
		printf("new_expr = ");
		for (int i = 0; i < idx; i++)
			printf("%c ", new_expr[i]);
		printf("\n");
	}
	new_expr[idx] = ';'; // place eos on final index.
}

int eval(char* expr) {
	/*
	evaluate a postfix expression, expr, maintained as a global variable.
	'\0' is the end of the expression.
	The stack_int and top_int of the stack_int are global variables.
	getToken is used to return the token type and the character symbol.
	Operands are assumed to be single character digits.
	*/
	printf("eval() operated.\n");

	precedence token;
	char symbol;
	int i;
	int op1, op2;
	int digit[9], digits = 0, sign = 1, number = 0; /* use for identify number */
	int result = 1; /* use for power calculation */
	int n = 0; /* counter for the expression string */
	top_int = -1;

	token = getToken(expr, &symbol, &n);
	while (token != eos) {
		if (token == operand) {
			/*
			operand has two meaning.
			number char is literally number,
			` is identifier for number.
			*/
			digits = 0;
			sign = 1; // 1 = plus, -1 = minus
			number = 0;
			/* get digit one by one in an array. */
			token = getToken(expr, &symbol, &n);
			while (symbol != '`') {

				if (symbol == '-') {
					sign = -1;
				}
				if ('0' <= symbol && symbol <= '9') {
					digit[digits++] = symbol - '0';
				}
				token = getToken(expr, &symbol, &n);
			}

			/* integrate digits on one number. */
			for (i = 0; i < digits; i++) {
				number += (digit[i] * pow_int(10, digits - 1 - i));
			}
			number = (sign == 1) ? (number) : (number * -1);
			push_int(number);

		}
		else if (token == logicalnot) {
			op1 = pop_int();
			push_int(!op1);
		}
		else {
			/* pop_int two operands, perform operation, and push_int result to the stack_int */
			op2 = pop_int(); /* stack_int delete */
			op1 = pop_int();
			switch (token) {
				case plus: push_int(op1 + op2);
					break;
				case minus: push_int(op1 - op2);
					break;
				case times: push_int(op1 * op2);
					break;
				case divide: push_int(op1 / op2);
					break;
				case mod: push_int(op1 % op2);
					break;
				case power:
					result = 1;
					for (i = 0; i < op2; i++)
						result *= op1;
					push_int(result);
					break;
			}
		}
		printStack_int();
		token = getToken(expr, &symbol, &n);
	}
	return pop_int(); /* return result */
}

precedence getToken(char* expr, char* symbol, int* n) {
	/*
	get the next token, symbol is the character representation, which is returned,
	the token is represented by its enumerated value, which is returned in the function name.
	*/
	*symbol = expr[(*n)++];
	switch (*symbol) {
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '/': return divide;
		case '*': return times;
		case '%': return mod;
		case '!': return logicalnot;
		case '^': return power;
		case ';': return eos;
		default : return operand; /* no error checking, default is operand */
	}
}

char printToken(precedence token) {
	switch (token) {
		case lparen:	return '(';
		case rparen:	return ')';
		case plus:		return '+';
		case minus:		return '-';
		case times:		return '*';
		case divide:	return '/';
		case mod:		return '%';
		case logicalnot:return '!';
		case power:		return '^';
		case eos:		return ';';
	}
}

void printStack_int_token() {
	int i;

	printf("stack_int = ");
	for (i = 0; i <= top_int; i++) {
		switch (stack_int[i]) {
			case lparen:	printf("( "); break;
			case rparen:	printf(") "); break;
			case plus:		printf("+ "); break;
			case minus:		printf("- "); break;
			case times:		printf("* "); break;
			case divide:	printf("/ "); break;
			case mod:		printf("% "); break;
			case logicalnot:printf("! "); break;
			case power:		printf("^ "); break;
			case eos:		printf("; "); break;
		}
	}
	printf("\t");
}