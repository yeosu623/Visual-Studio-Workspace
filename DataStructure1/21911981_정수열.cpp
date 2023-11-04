// 21911981, 정수열

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _polynomial {
	int coef;
	int expon;
}polynomial;
polynomial* terms;
int avail = 0;

void printPolynomial(polynomial*, int);
void printSign(polynomial*, int);
void printAbsCoef(polynomial*, int);
void printExp(polynomial*, int);

int main() {
	char fname[50];
	int i, j;
	int nA, nB, nResult;
	int input_data;
	int lead_expon;
	int lead_avail;
	FILE* fp;
	polynomial* polyA;
	polynomial* polyB;
	polynomial* polyPreResult;
	polynomial* polyResult;


	printf("입력 파일 이름? ");
	gets_s(fname, sizeof(fname));
	fopen_s(&fp, fname, "r");
	if (fp == NULL) { printf("파일이 존재하지 않습니다.\n"); return 0; }

	fscanf_s(fp, "%d", &nA);
	polyA = (polynomial*)malloc(sizeof(polynomial) * nA);
	terms = (polynomial*)malloc(sizeof(polynomial) * nA);
	for (i = 0; i < nA; i++) {
		fscanf_s(fp, "%d", &input_data);
		polyA[i].coef = input_data;
		terms[avail].coef = input_data;

		fscanf_s(fp, "%d", &input_data);
		polyA[i].expon = input_data;
		terms[avail].expon = input_data;

		avail++;
	}

	fscanf_s(fp, "%d", &nB);
	polyB = (polynomial*)malloc(sizeof(polynomial) * nB);
	realloc(terms, sizeof(polynomial) * (nA + nB));
	for (i = 0; i < nB; i++) {
		fscanf_s(fp, "%d", &input_data);
		polyB[i].coef = input_data;
		terms[avail].coef = input_data;

		fscanf_s(fp, "%d", &input_data);
		polyB[i].expon = input_data;
		terms[avail].expon = input_data;

		avail++;
	}

	polyPreResult = (polynomial*)malloc(sizeof(polynomial) * (nA * nB));
	for (i = 0; i < nA; i++) {
		for (j = 0; j < nB; j++) {
			polyPreResult[j + (i * nB)].coef = polyA[i].coef * polyB[j].coef;
			polyPreResult[j + (i * nB)].expon = polyA[i].expon + polyB[j].expon;
		}
	}

	polyResult = (polynomial*)malloc(sizeof(polynomial) * (nA * nB));
	for (i = 0; i < (nA * nB); i++)
		polyResult[i].coef = 0;

	lead_expon = polyA[0].expon + polyB[0].expon;
	lead_avail = 0;
	while (lead_expon >= 0) {
		for (i = 0; i < (nA * nB); i++) {
			if (polyPreResult[i].expon == lead_expon) {
				polyResult[lead_avail].expon = lead_expon;
				polyResult[lead_avail].coef += polyPreResult[i].coef;
			}
		}

		lead_avail++;
		lead_expon--;
	}
	nResult = lead_avail;
	realloc(polyResult, sizeof(polynomial) * nResult);

	printf("첫 번째 다항식 : ");
	printPolynomial(polyA, nA);
	printf("\n");
	printf("두 번째 다항식 : ");
	printPolynomial(polyB, nB);
	printf("\n");
	printf("다항식의 곱 : ");
	printPolynomial(polyResult, nResult);
	printf("\n");

	return 0;
}

void printPolynomial(polynomial* p, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (p[i].coef == 0) continue;

		if (i != 0 || p[0].coef < 0) printSign(p, i);
		if (abs(p[i].coef) != 1 || p[i].expon == 0) printAbsCoef(p, i);
		if (p[i].expon != 0) printf("X");
		if (p[i].expon >= 2) printExp(p, i);
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