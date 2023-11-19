#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
struct node {
	int key;
	double value;
	struct node* lchild;
	struct node* rchild;
};

void insert(treePointer*, int, double); // ���� ���α׷� 5.17
treePointer modifiedSearch(treePointer, int);
void print_inorder(treePointer ptr);
treePointer get_sample_data();

int main() {
	treePointer A = get_sample_data();
	print_inorder(A);
}

void insert(treePointer* node, int k, double theItem) { // node �Ű������� ���������� �ӿ� ����
	/* Ʈ�� �� ��尡 k�� ������ ������ �ƹ� �ϵ� ���� ����.
	�׷��� ���� ���� data = (k, theItem)�� �� ��带 ÷�� */
	treePointer ptr; // ���� �߰��� ���
	treePointer search_result = modifiedSearch(*node, k); // key ����� NULL�� ����. key�� ������ �˻� ����� ������ ��带 ��ȯ
	if (search_result || !(*node)) { // �˻� ����� key�� ���ų�, �ƿ� Ʈ���� ���� ���

		// ���ο� ��� ����
		ptr = (treePointer)malloc(sizeof(*ptr));
		if (!ptr) {
			fprintf(stderr, "Insufficient memory");
			exit(1);
		}

		// ���ο� ��忡 �� ����
		ptr->key = k;
		ptr->value = theItem;
		ptr->lchild = ptr->rchild = NULL;

		// ���ο� ��� ��ġ ����
		if (*node) { // ���ο� ��尡 �ڽ����� ���� ���
			if (k < search_result->key) search_result->lchild = ptr; // ���ο� ��尡 ���ʿ� ���ԵǴ� ���
			else search_result->rchild = ptr; // ���ο� ��尡 �����ʿ� ���ԵǴ� ���
		}
		else *node = ptr; // ���ο� ��尡 root�� �Ǵ� ���
	}
}

treePointer modifiedSearch(treePointer node, int k) {
	/* key�� ������ ��� NULL�� ����.
	key�� �������� ���� ���, �˻� �˰��򿡼� �湮�� ������ ��忡 ���� �����͸� ��ȯ */
	for (treePointer ptr = node; ptr != NULL;) {
		if (ptr->key == k)
			return NULL;
		if (k < ptr->key) {
			if (ptr->lchild == NULL) return ptr;
			else ptr = ptr->lchild;
		}
		else {
			if (ptr->rchild == NULL) return ptr;
			else ptr = ptr->rchild;
		}
	}
	return NULL;
}

void print_inorder(treePointer ptr) {
	// ���� Ž�� Ʈ���� inorder ������� key, value ���
	if (ptr) {
		print_inorder(ptr->lchild);
		printf("%d %.1f\n", ptr->key, ptr->value);
		print_inorder(ptr->rchild);
	}
}

treePointer get_new_node() {
	treePointer node = (treePointer)malloc(sizeof(struct node));
	node->key = -1;
	node->value = -1.0;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}

treePointer get_sample_data() {
	// 12���� (key, value) ���� �����Ͽ� ���� Ž�� Ʈ���� �߰�
	// key ���� 1~12�� �׽�Ʈ
	// value ���� 1~12�� �׽�Ʈ
	treePointer root = get_new_node();
	treePointer A = get_new_node();
	treePointer B = get_new_node();
	treePointer C = get_new_node();
	treePointer D = get_new_node();
	treePointer E = get_new_node();
	treePointer F = get_new_node();
	treePointer G = get_new_node();
	treePointer H = get_new_node();
	treePointer I = get_new_node();
	treePointer J = get_new_node();
	treePointer K = get_new_node();

	for (int i = 1; i <= 12; i++) {
		insert(&root, i, (double)i);
	}

	return root;
}