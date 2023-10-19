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
poly* rear, * front;
poly* avail = NULL;
int compare(int, int);
poly* get_node();
void ret_node(poly*);
void cerase(poly**);
poly* create_polynomial();
void attach(int, int, poly**);
void cprint(poly*);
poly* cpadd(poly*, poly*);
poly* single_cpmul(poly*, poly*);
poly* cpmul(poly*, poly*);

int main() {
	a = create_polynomial();
	b = create_polynomial();

	d = cpmul(a, b);
	cprint(d);
}

int compare(int x, int y) {
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
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
	int coef = -999, expon = -999;
	poly* ptr = (poly*)malloc(sizeof(poly));
	poly* first_node_addr;

	// first node
	ptr->expon = -1;
	first_node_addr = ptr;
	rear = ptr; // for connenct to circular link

	printf("input -1 in expon to stop input.\n");
	while (true) {
		printf("input coef, expon = ");
		scanf_s("%d %d", &coef, &expon);

		if (expon >= 0)
			attach(coef, expon, &ptr);
		else if (expon == -1)
			break;
		else
			printf("negative expon is not acceptable.\n");
	}


	// connect the final node to first node
	ptr->link = first_node_addr;
	// move to the first node
	ptr = ptr->link;

	return ptr;
}

void attach(int coef, int expon, poly** ptr) {
	poly* node = (poly*)malloc(sizeof(poly));
	
	node->coef = coef;
	node->expon = expon;
	node->link = NULL;

	(*ptr)->link = node;
	(*ptr) = (*ptr)->link;
}

void cprint(poly* ptr) {
	// print after the first node,
	// while it reaches to the first node
	poly* p;

	for (p = ptr->link; p->expon != -1; p = p->link) {
		printf("%d %d \n", p->coef, p->expon);
	}
}

poly* cpadd(poly* a, poly* b) {
	// ���׽� a�� b : singly linked circular lists with a head node.
	// d = a + b�� ����� ��, d�� ��ȯ

	poly* starta, * d, * lastd;
	int sum;
	bool done = false;

	starta = a; 
	a = a->link; b = b->link; // a�� b�� head node�� skip
	d = get_node(); // ���� ���� head node �Ҵ�
	d->expon = -1; lastd = d;

	do {
		switch (compare(a->expon, b->expon)) {
		case -1:
			attach(b->coef, b->expon, &lastd);
			b = b->link;
			break;
		case 0:
			if (starta == a) done = true;
			else {
				sum = a->coef + b->coef;
				if (sum) attach(sum, a->expon, &lastd);
				a = a->link;
				b = b->link;
			}
			break;
		case 1:
			attach(a->coef, a->expon, &lastd);
			a = a->link;
			break;
		} 
	} while (!done);

	lastd->link = d;
	return d;
}

poly* single_cpmul(poly* a, poly* b) {
	// a�� �� �ϳ�, b�� ���׽�
	int coef, expon;
	poly* d, *lastd;
	
	d = get_node();
	d->expon = -1;
	lastd = d;

	for (b = b->link; b->expon != -1; b = b->link) {
		coef = (a->coef) * (b->coef);
		expon = (a->expon) + (b->expon);

		if(coef != 0) attach(coef, expon, &lastd);
	}

	lastd->link = d;
	return d;
}

poly* cpmul(poly* a, poly* b) {
	poly* temp;
	poly* d;
	poly* x;

	d = get_node();
	d->expon = -1;
	d->link = d;

	for (a = a->link; a->expon != -1; a = a->link) {
		x = single_cpmul(a, b);
		d = cpadd(d, x);
	}

	return d;
}