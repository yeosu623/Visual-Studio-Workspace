// 학번: 21911981    
// 이름: 정수열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};

// 함수를 추가하면, 여기에 정의할 것
int get_list_length(char[]);
struct node* make_list(char[]);
void print_list(struct node*);
struct node* add(struct node*, struct node*);
struct node* single_multiply(struct node*, int, int);
struct node* multiply(struct node*, struct node*);

void main()
{
	char fname[40];
	char first[1000], second[1000];
	struct node* A, * B, * C, * D;
	FILE* fp;

	printf("파일 이름? ");
	gets_s(fname);
	fp = fopen(fname, "r");
	fscanf(fp, "%s%s", first, second);

	A = make_list(first);
	B = make_list(second);
	C = add(A, B);
	D = multiply(A, B);

	printf("첫번째 수 = ");
	print_list(A);
	printf("\n두번째 수 = ");
	print_list(B);
	printf("\n두 수의 합 = ");
	print_list(C);
	printf("\n두 수의 곱 = ");
	print_list(D);
}

// 여기에 나머지 함수들을 구현
int get_list_length(char str[]) {
	int length = 0;

	while (str[length++] != '\0');
	return length - 1;
}

struct node* make_list(char str[]) {
	int i;
	int data;
	int length = get_list_length(str);
	struct node* start = NULL;
	struct node* node = NULL;
	struct node* node_prev = NULL;

	for (i = 0; i < length; i++) {
		node = (struct node*)malloc(sizeof(struct node));
		node->data = str[length - 1 - i] - '0';
		node->link = NULL;

		if (start == NULL) start = node;
		else node_prev->link = node;

		node_prev = node;
	}

	return start;
}

void print_list(struct node* start) {
	int i = 0;
	int j;
	int list_reversed[1000];
	struct node* ptr = NULL;

	for (ptr = start; ptr != NULL; ptr = ptr->link)
		list_reversed[i++] = ptr->data;

	for (j = 0; j < i; j++) {
		printf("%d", list_reversed[i - 1 - j]);
	}
}

struct node* add(struct node* startA, struct node* startB) {
	int data;
	int carry = 0;
	struct node* ptrA = startA;
	struct node* ptrB = startB;
	struct node* node = NULL;
	struct node* node_prev = NULL;
	struct node* startR = NULL;

	while (ptrA != NULL || ptrB != NULL) {

		if (ptrA != NULL && ptrB != NULL) {
			data = ptrA->data + ptrB->data;
			ptrA = ptrA->link;
			ptrB = ptrB->link;
		}
		else if (ptrA == NULL && ptrB != NULL) {
			data = ptrB->data;
			ptrB = ptrB->link;
		}
		else if (ptrA != NULL && ptrB == NULL) {
			data = ptrA->data;
			ptrA = ptrA->link;
		}

		node = (struct node*)malloc(sizeof(struct node));

		if (data + carry < 10) {
			node->data = data + carry;
			carry = 0;
		}
		else {
			node->data = (data + carry) - 10;
			carry = 1;
		}

		node->link = NULL;
		if (startR == NULL) startR = node;
		else node_prev->link = node;

		node_prev = node;
	}

	if (carry == 1) {
		node = (struct node*)malloc(sizeof(struct node));
		node->data = 1;
		node->link = NULL;
		node_prev->link = node;

		carry = 0;
	}

	return startR;
}

struct node* single_multiply(struct node* formula, int num, int attach_zero) {
	int data;
	int carry = 0;
	struct node* node = NULL;
	struct node* node_prev = NULL;
	struct node* start = NULL;
	struct node* ptr = formula;

	while (ptr != NULL) {
		data = ptr->data * num;

		ptr = ptr->link;

		node = (struct node*)malloc(sizeof(struct node));

		if (data + carry < 10) {
			node->data = data + carry;
			carry = 0;
		}
		else {
			node->data = (data + carry) % 10;
			carry = (data + carry) / 10;
		}

		node->link = NULL;
		if (start == NULL) start = node;
		else node_prev->link = node;

		node_prev = node;
	}

	if (carry > 0) {
		node = (struct node*)malloc(sizeof(struct node));
		node->data = carry;
		node->link = NULL;
		node_prev->link = node;

		carry = 0;
	}

	if (attach_zero > 0) {
		while (attach_zero-- != 0) {
			node = (struct node*)malloc(sizeof(struct node));
			node->data = 0;
			node->link = start;
			start = node;
		}
	}

	return start;
}

struct node* multiply(struct node* startA, struct node* startB) {
	int attach_zero = 0;
	struct node* ptrB = startB;
	struct node* R1 = NULL;
	struct node* R2 = NULL;

	for (ptrB = startB; ptrB != NULL; ptrB = ptrB->link) {
		R1 = single_multiply(startA, ptrB->data, attach_zero++);
		R2 = add(R1, R2);
	}

	return R2;
}