#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_recursiveSearch = 0; // recursiveSearch �� �� �� ȣ���ߴ��� ���� ���� ����. ȣ�� �Ŀ��� �ݵ�� 0���� ���� �ʱ�ȭ �� ��!!
int count_print_inorder_short = 0; // print_inorder_short �� �� �� ȣ���ߴ��� ���� ���� ����. ȣ�� �Ŀ��� �ݵ�� 0���� ���� �ʱ�ȭ �� ��!!
typedef struct node* treePointer;
struct node {
	int key;
	double value;
	struct node* lchild;
	struct node* rchild;
};

void insert(treePointer*, int, double); // ���� ���α׷� 5.17. �����ڷ� 5�� Page 73
treePointer modifiedSearch(treePointer, int); // �����ڷ� 5�� Page 74
treePointer recursiveSearch(treePointer, int); // ���� ���α׷� 5.15. �����ڷ� 5�� Page 69
void print_inorder(treePointer); // �����ڷ� 5�� Page 20 ����
int count_node(treePointer); // �����ڷ� 5�� Page 33
int count_depth(treePointer); // �����ڷ� 5�� Page 33 ����
int count_leaf(treePointer); // �����ڷ� 5�� Page 35
int MAX(int, int); // �� ���ڸ� �޾Ƽ� �� ū ���ڸ� ��ȯ�ϴ� �Լ�

treePointer get_sample_data(); // �ڷᱸ���ǽ� ���� 9.1�� ���� �����ͼ�
treePointer make_bst(int); // �ڷᱸ���ǽ� ���� 9.3�� ���� �����ͼ�

void print_9_2(treePointer); // ���� 9.2 ��� ���
void print_9_3(); // ���� 9.3 ��� ���

int main() {
	printf("9.1. 12���� (key, value)���� �����Ͽ� ���� Ž�� Ʈ�� ����\n");
	treePointer A = get_sample_data();
	printf("���� �Ϸ�\n\n");

	printf("9.2. ������ ���� �˻� Ʈ������ key���� Ȱ���� �˻�\n");
	print_9_2(A);

	printf("9.3. n���� ��带 ���� ����Ʈ�� �����ð� �� ��� ��, ����(����), �ܸ� ��� �� ����\n");
	print_9_3();

	free(A);
}

void insert(treePointer* node, int k, double theItem) { // node �Ű������� ���������� �ӿ� ����
	/* Ʈ�� �� ��尡 k�� ������ ������ �ƹ� �ϵ� ���� ����.
	�׷��� ���� ���� data = (k, theItem)�� �� ��带 ÷�� */
	treePointer ptr; // ���� �߰��� ���
	treePointer search_result = modifiedSearch(*node, k); // key ����� NULL�� ����. key�� ������ �˻� ����� ������ ��带 ��ȯ
	if (search_result || !(*node)) { // �˻� ����� key�� ���ų�, �ƿ� Ʈ���� ���� ���

		// ���ο� ��� ����
		ptr = (treePointer)malloc(sizeof(struct node));
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

treePointer modifiedSearch(treePointer root, int key) {
	/* key�� ������ ��� NULL�� ����.
	key�� �������� ���� ���, �˻� �˰��򿡼� �湮�� ������ ��忡 ���� �����͸� ��ȯ */
	for (treePointer ptr = root; ptr != NULL;) {
		if (ptr->key == key) // ������ �����ϴ� Ű�� �Է� : �ߺ� ���� �̹Ƿ� NULL�� ��ȯ
			return NULL;
		if (key < ptr->key) { // ���� �� key�� ���� Ʈ������ ����Ű�� �ִ� ����� key���� ���� ���
			if (ptr->lchild == NULL) return ptr; // ������ ����̹Ƿ� ��ȯ
			else ptr = ptr->lchild; // �ڽ��� ������ �ڽ��� ����Ų �ڿ� �ٽ� for ������ ����.
		}
		else { // ���� if�� ������ �����ϴ�.
			if (ptr->rchild == NULL) return ptr;
			else ptr = ptr->rchild;
		}
	}
	return NULL; // ������ ��带 ��ȯ�ؾ� �ϴµ�, �˰��� ������ �־ ������ NULL�� ��ȯ
}

treePointer recursiveSearch(treePointer root, int key) {
	// key�� �����ϰ� �ִ� ����� �����͸� return
	// �ش�Ǵ� ��尡 ���� ���, return NULL
	// Recursive version 

	count_recursiveSearch++; // ���� ����

	if (!root) return NULL;
	if (key == root->key) return root;
	if (key < root->key)  return recursiveSearch(root->lchild, key);
	else                  return recursiveSearch(root->rchild, key);
}

void print_inorder(treePointer ptr) {
	// ���� Ž�� Ʈ���� inorder ������� key, value ���
	if (ptr) {
		print_inorder(ptr->lchild);
		printf("%d %.6f\n", ptr->key, ptr->value);
		print_inorder(ptr->rchild);
	}
}

int count_node(treePointer ptr) {
	int count = 0;
	if (ptr != NULL)
		count = 1 + count_node(ptr->lchild) + count_node(ptr->rchild);
	return count;
}

int count_depth(treePointer ptr) {
	int depth = 0;
	if (ptr != NULL)
		depth = 1 + MAX(count_depth(ptr->lchild), count_depth(ptr->rchild));
	return depth;
}

int count_leaf(treePointer ptr) {
	int count = 0;

	if (ptr != NULL) {
		if (ptr->lchild == NULL &&
			ptr->rchild == NULL) // �ܸ� ���
			return 1;
		else count = count_leaf(ptr->lchild) + count_leaf(ptr->rchild);
	}
	return count;
}

int MAX(int a, int b) {
	return (a > b) ? a : b;
}

treePointer get_sample_data() {
	/* �ڷᱸ���ǽ� ���� 9.1.
	* 12���� (key, value) ���� �����Ͽ� ���� Ž�� Ʈ���� �߰�
	* 
	�ǽ� ������� 9.1. �� ���� key, value ���� ����
	key : 10, 6, 15, 8, 18, 12, 3, 14, 9, 20, 5, 2
	value : 1.0 / key
	*/
	treePointer root = NULL;

	insert(&root,  10,	1.0 / 10);
	insert(&root,   6,	1.0 / 6);
	insert(&root,  15,	1.0 / 15);
	insert(&root,   8,	1.0 / 8);
	insert(&root,  18,	1.0 / 18);
	insert(&root,  12,	1.0 / 12);
	insert(&root,   3,	1.0 / 3);
	insert(&root,  14,	1.0 / 14);
	insert(&root,   9,	1.0 / 9);
	insert(&root,  20,	1.0 / 20);
	insert(&root,   5,	1.0 / 5);
	insert(&root,   2,	1.0 / 2);

	return root;
}

treePointer make_bst(int n) {
	/* �ڷᱸ���ǽ� ���� 9.3.
	* n�� ���ڷ� �޾�, n����
	* key : ( rand() / (0x7fff * 1.0) ) * 100,000,000
	* value : 1.0 / key
	* ���� ���� Ž�� Ʈ���� �߰��ϴ� �Լ� make_bst(int n)�� �ۼ�
	* 
	* ���� : 
	* rand() ������ ������ 0 ~ 32,767
	* 0x7fff�� 32,767
	* ���� key�� 0 ~ 100,000,000 ������ ���ڸ� 32,768 ���� ������ �ɰ� ���ڰ� ����.
	*/

	int key;
	double value;
	treePointer root = NULL;

	srand(time(NULL)); // rand()���� ������ �����ϱ� ���� �õ� ���� �ʱ�ȭ

	for (int i = 0; i < n; i++) {
		key = (rand() / (0x7fff * 1.0) ) * 100000000;
		value = 1.0 / key;

		insert(&root, key, value);
	}

	return root;
}

void print_9_2(treePointer A) {
	int key;
	treePointer resultNode = NULL;
	while (1) {
		// �˻��� key�� �Է�
		printf("ã���� �ϴ� key ���� �Է��ϼ���. : ");
		scanf("%d", &key);

		// -1 �Է½� ����
		if (key == -1) {
			printf("\n\n"); break;
		}

		// �˻� ��� ���
		resultNode = recursiveSearch(A, key);
		if (resultNode) {
			printf("count : %d, key : %d�� value : %.6f\n", count_recursiveSearch, resultNode->key, resultNode->value);
			count_recursiveSearch = 0; // �ʱ�ȭ�� �ؼ�, ������ �˻� Ƚ���� �� �� ���
		}
		else {
			printf("key : %d ��尡 �����ϴ�.\n", key);
			count_recursiveSearch = 0;
		}
	}
}

void print_9_3() {
	int n;
	int theNumberOfNodes, theNumberOfDepths, theNumberOfLeafs;
	int print_count = 0;
	clock_t start, stop; // ���α׷� ���� �ð��� ��µ� ���Ǵ� ����
	double duration;
	treePointer resultTree = NULL; // �����˻�Ʈ�� B
	treePointer resultNode = NULL;

	while (1) {
		// n�� �Է�
		printf("n���� ��带 ���� �����˻� Ʈ�� ���� (n) : ");
		scanf("%d", &n);

		// -1 �Է½� ����
		if (n == -1) break;


		// Ʈ�� ���� �� Ʈ���� ���� ���
		start = clock();
		resultTree = make_bst(n);
		stop = clock();

		duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
		theNumberOfNodes = count_node(resultTree);
		theNumberOfDepths = count_depth(resultTree);
		theNumberOfLeafs = count_leaf(resultTree);


		/* �����˻�Ʈ���� ó�� 2��, ������ 3���� key - value �ָ� ���
		*
		* ���� 9.3���� key�� ������ 0 ~ 100,000,000 �̹Ƿ�
		* �̸� �̿��Ͽ� ����� ���
		*/
		print_count = 0;

		printf("�����˻�Ʈ�� : \n");
		printf("(key        value   )\n");
		for (int targetKey = 0; targetKey < 100000000; targetKey++) {
			resultNode = recursiveSearch(resultTree, targetKey);

			if (resultNode) { // �ش�Ǵ� ��尡 �ְ�
				if (print_count == 0 || // ó�� 2��, ������ 3���� �ش��ϴ� key ���
					print_count == 1 ||
					print_count == theNumberOfNodes - 1 ||
					print_count == theNumberOfNodes - 2 ||
					print_count == theNumberOfNodes - 3
					)
				{ // ����� ����ϰ� ��� ī��Ʈ�� ���δ�.
					printf("(%-9d, %.6f)\n", resultNode->key, resultNode->value);
					print_count++;
				}
				else if (print_count == 2) { // �߰��� ...... ���
					printf("......\n");
					print_count++;
				}
				else print_count++; // �߰����� ī��Ʈ�� ���δ�.
			}
		}

		// �����˻�Ʈ���� ���� ���
		printf("�����˻�Ʈ���� �����ð� : %.3f\n", duration);
		printf("�����˻�Ʈ���� ��� �� : %d\n", theNumberOfNodes);
		printf("�����˻�Ʈ���� ����(����) : %d\n", theNumberOfDepths);
		printf("�����˻�Ʈ���� �ܸ���� �� : %d\n\n", theNumberOfLeafs);

		// �޸� �ʱ�ȭ
		free(resultTree);
	}
}