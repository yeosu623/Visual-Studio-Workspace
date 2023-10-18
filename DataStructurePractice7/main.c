#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct _poly {
	int coef;
	int expon;
	struct _poly* link;
}poly;

poly* a, * b, * d;
poly* avail = NULL;
poly* get_node();
void ret_node(poly*);
void cerase(poly**);
poly* create_polynomial();
void attach(int, int, poly**);
void cprint(poly*);

int main() {

}

poly* get_node() {
	// ��밡���� �ϳ��� ��带 ���� ����Ʈ�� malloc()�� �̿��Ͽ� ��ȯ
	poly* node;
	if (avail != NULL) {
		node = avail;
		avail = avail->link;
	}
	else
		node = (poly*)malloc(sizeof(poly));

	return node;
}

void ret_node(poly* ptr) {
	// ptr�� ����Ű�� ��带 ���� ����Ʈ�� ��ȯ
	ptr->link = avail;
	avail = ptr;
}

void cerase(poly** ptr) {
	// ptr�� ����Ű�� ���� ����Ʈ�� ��ȯ
	poly* temp;

	if (*ptr) {
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

poly* create_polynomial() {

}

void attach(int coef, int expon, poly** ptr) {
	poly* node;

	if (*ptr) {
		node->coef = coef;
		node->expon = expon;
		
	}
	else

}

void cprint(poly* ptr) {

}