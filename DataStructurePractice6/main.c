#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ERROR -999;

typedef struct _node {
	int data;
	struct _node* link;
}node;

void insert_front(node**, int);
void print_list(node**);
void insert_last(node**, int);
int search(node**, int);
int delete_front(node**);
int delete_element(node**, int);

int main() {
	int i;
	int result;
	node* A = NULL;

	for (i = 0; i < 10; i++) {
		insert_last(&A, i*2);
	}
	print_list(&A);
	printf("\n");

	int n = delete_element(&A, 18);
	printf("deleted = %d\n", n);
	print_list(&A);
	printf("\n");
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