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
	// 사용가능한 하나의 노드를 가용 리스트나 malloc()을 이용하여 반환
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
	// ptr이 가리키는 노드를 가용 리스트에 반환
	ptr->link = avail;
	avail = ptr;
}

void cerase(poly** ptr) {
	// ptr이 가리키는 원형 리스트를 반환
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