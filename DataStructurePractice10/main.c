#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* create_node(int);

int main() {
	printf("10.1. ���� ����Ʈ ������ �����⼺ �׷��� ����\n");
	printf("��� ����(n): ");
	int n;
	scanf("%d", &n);
	struct node** graph = (struct node**)calloc(n, sizeof(struct node*));

	while (1) {
		int vi, vj;
		printf("���� ����(vi vj) : ");
		scanf("%d %d", &vi, &vj);

		if (vi == -1 && vj == -1) break;
		else {
			
		}
	}
}

struct node* create_node(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->next = NULL;

	return node;
}