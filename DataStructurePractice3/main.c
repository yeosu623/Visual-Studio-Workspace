#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct _polynomial {
	int coef;
	int expon;
}polynomial;

void printPolynomial(polynomial*);
void printSign(polynomial*, int);
void printAbsCoef(polynomial*, int);
void printExp(polynomial*, int);
polynomial* padd(polynomial*, polynomial*);
polynomial* pmul(polynomial*, polynomial*);
polynomial* single_mul(polynomial, polynomial*);

int main() {
	polynomial* A, * B, *C, * D;
	A = (polynomial*)malloc(sizeof(polynomial) * 10); // X^2 - 5
	B = (polynomial*)malloc(sizeof(polynomial) * 10); // 3X^2 - X + 4
	C = (polynomial*)malloc(sizeof(polynomial) * 10); // X^2 + 5
	D = (polynomial*)malloc(sizeof(polynomial) * 10);

	A[0].coef = 1;
	A[0].expon = 2;
	A[1].coef = -5;
	A[1].expon = 0;
	A[2].expon = -1; // 다항식의 끝

	B[0].coef = 3;
	B[0].expon = 2;
	B[1].coef = -1;
	B[1].expon = 1;
	B[2].coef = 4;
	B[2].expon = 0;
	B[3].expon = -1; // 다항식의 끝

	C[0].coef = 1;
	C[0].expon = 2;
	C[1].coef = 5;
	C[1].expon = 0;
	C[2].expon = -1; // 다항식의 끝

	D = pmul(A, A);
	printPolynomial(D);
}

void printPolynomial(polynomial* p) {
	int i = 0;
	while(!(p[i].expon == -1)) {
		if (p[i].coef == 0) { i++;  continue; }

		if (i != 0 || p[0].coef < 0) printSign(p, i);
		if (abs(p[i].coef) != 1 || p[i].expon == 0) printAbsCoef(p, i);
		if (p[i].expon != 0) printf("X");
		if (p[i].expon >= 2) printExp(p, i);
		i++;
	}
}

void printSign(polynomial* p, int i) {
	if (p[i].coef >= 0) printf(" + ");
	else printf(" - ");
}

void printAbsCoef(polynomial* p, int i) {
	printf("%d", abs(p[i].coef));
}

void printExp(polynomial* p, int i) {
	printf("^%d", p[i].expon);
}

polynomial* padd(polynomial* A, polynomial* B) {
	polynomial* D = (polynomial*)malloc(sizeof(polynomial) * 10);
	polynomial* pA = &A[0];
	polynomial* pB = &B[0];
	polynomial* pD = &D[0];

	while (!(pA->expon == -1 && pB->expon == -1)) {
		if (pA->expon > pB->expon) {
			pD->coef = pA->coef;
			pD->expon = pA->expon;

			pA++;
			pD++;
		}
		else if (pA->expon == pB->expon) {
			pD->coef = pA->coef + pB->coef;
			pD->expon = pA->expon;

			pA++;
			pB++;
			pD++;
		}
		else if (pA->expon < pB->expon) {
			pD->coef = pB->coef;
			pD->expon = pB->expon;

			pB++;
			pD++;
		}
	}

	pD->expon = -1;
	return D;
}

polynomial* pmul(polynomial* A, polynomial* B) {
	int i;
	int lengthA = 0;
	polynomial* Ci;
	polynomial* D;

	while (A[lengthA].expon != -1) lengthA++;
	Ci = (polynomial*)malloc(sizeof(polynomial) * 10);
	D = (polynomial*)malloc(sizeof(polynomial) * 10);
	D[0].expon = -1;

	for (i = 0; i < lengthA; i++) {
		Ci = single_mul(A[i], B);
		D = padd(D, Ci);
	}

	return D;
}

polynomial* single_mul(polynomial Ai, polynomial* B) {
	int i;
	int lengthB = 0;
	polynomial* D;

	while (B[lengthB].expon != -1) lengthB++;
	D = (polynomial*)malloc(sizeof(polynomial) * lengthB);

	for (i = 0; i < lengthB; i++) {
		D[i].expon = Ai.expon + B[i].expon;
		D[i].coef = Ai.coef * B[i].coef;
	}

	D[lengthB].expon = -1;
	return D;
}