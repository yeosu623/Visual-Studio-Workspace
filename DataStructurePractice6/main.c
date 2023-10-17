#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ERROR -999;

typedef struct _node {
	int data;
	struct _node* link;
}node;

int top = -1;
int front_q = -1, rear_q = -1;

void insert_front(node**, int);
void print_list(node**);
void insert_last(node**, int);
int search(node**, int);
int delete_front(node**);
int delete_element(node**, int);
void push(node**, int);
int pop(node**);
void add_q(node**, int);
int delete_q(node**);
void invert(node**);
void merge(node**, node**);
void sort(node**);
void swap(int*, int*);

int main() {
	int i;
	int input = 0;
	node* A = NULL;
	node* B = NULL;

	while (true) {
		printf("input data in A : ");
		scanf_s("%d", &input);

		if (input == -1) break;
		else insert_last(&A, input);
	}
	while (true) {
		printf("input data in B : ");
		scanf_s("%d", &input);

		if (input == -1) break;
		else insert_last(&B, input);
	}

	printf("A = ");
	print_list(&A);
	printf("B = ");
	print_list(&B);

	merge(&A, &B);
	printf("A+B = ");
	print_list(&A);

	sort(&A);
	printf("sorted A+B = ");
	print_list(&A);
}

void insert_front(node** A, int data) {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->link = *A;

	*A = temp;
}

void print_list(node** A) {
	node* ptr;

	for (ptr = *A; ptr != NULL; ptr = ptr->link)
		printf("%d ", ptr->data);

	printf("\n");
}

void insert_last(node** A, int data) {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;

	node* ptr;
	if (*A == NULL) {
		*A = temp;
	}
	else {
		for (ptr = *A; ptr->link != NULL; ptr = ptr->link);

		ptr->link = temp;
	}
}

int search(node** A, int data) {
	int nodeNum = 0;
	node* ptr;

	if (*A == NULL) {
		printf("Node A is empty.\n");
		return ERROR;
	}
	else {
		for (ptr = *A; ptr->data != data; ptr = ptr->link) {
			nodeNum++;

			if (ptr->link == NULL) {
				printf("Node A has not %d.\n", data);
				return ERROR;
			}
		}
		return nodeNum;
	}
}

int delete_front(node** A) {
	node* prevA;
	int data;

	if (*A == NULL) {
		printf("Node A is already empty.\n");
		return ERROR;
	}
	else {
		data = (*A)->data;
		prevA = *A;

		*A = (*A)->link;
		free(prevA);

		return data;
	}
}

int delete_element(node** A, int data) {
	node* prevA = NULL;
	node* ptr;

	if (*A == NULL) {
		printf("Node A is already empty.");
		return ERROR;
	}
	else {
		for (ptr = *A; ptr->data != data; ptr = ptr->link) {
			prevA = ptr;

			if (ptr->link == NULL) {
				printf("Node A has not %d.\n", data);
				return ERROR;
			}
		}
		
		if (ptr == *A) { // first node
			prevA = *A;

			*A = (*A)->link;
			free(prevA);

			return data;
		}
		else if (ptr->link == NULL) { // last node
			prevA->link = NULL;
			free(ptr);

			return data;
		}
		else { // middle node
			prevA->link = ptr->link;
			free(ptr);

			return data;
		}
	}
}

void push(node** A, int data) {
	top++;
	insert_front(A, data);
}

int pop(node** A) {
	delete_front(A);
	top--;
}

void add_q(node** A, int data) {
	rear_q++;
	insert_last(A, data);
}

int delete_q(node** A) {
	front_q++;
	delete_front(A);
}

void invert(node** A) {
	node* ptr = *A;
	node* ptr_next = NULL;
	node* linkdata = NULL;

	while (ptr != NULL) {
		ptr_next = ptr->link;
		ptr->link = linkdata;
		linkdata = ptr;

		ptr = ptr_next;
	}

	*A = linkdata;
}

void merge(node** merger, node** mergee) {
	node* ptr;

	for (ptr = *merger; ptr->link != NULL; ptr = ptr->link);
	ptr->link = *mergee;
}

void sort(node** A) {
	int i = 0, j, min;
	int len = 0;
	int* data;
	node* ptr;

	// get length of linked list
	for (ptr = *A; ptr != NULL; ptr = ptr->link)
		len++;

	// get all data from linked list
	data = (int*)malloc(sizeof(int) * len);

	for (ptr = *A; ptr != NULL; ptr = ptr->link)
		data[i++] = ptr->data;

	// sort data
	for (i = 0; i < len - 1; i++) {
		min = i;
		for (j = i + 1; j < len; j++)
			if (data[j] < data[min])
				min = j;

		swap(&data[i], &data[min]);
	}

	// input sorted data in the linked list
	i = 0;

	for (ptr = *A; ptr != NULL; ptr = ptr->link)
		ptr->data = data[i++];

	// free dynamic allocated array
	free(data);
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}