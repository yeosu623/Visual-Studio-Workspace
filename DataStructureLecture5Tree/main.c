#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 500
#define MAX_QUEUE_SIZE 500
#define MAX_ELEMENTS 500 // maximum heap size + 1
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

int top = -1;
int front = 0, rear = 0;
struct node* stack[MAX_STACK_SIZE];
struct node* queue[MAX_QUEUE_SIZE];

// normal node
typedef struct node* tree_pointer;
struct node {
	int data;
	struct node* left_child;
	struct node* right_child;
};

// logical node (Page 36~38)
typedef enum { not, and, or , true, false } logical;
struct logical_node {
	struct logical_node* left_child;
	struct logical_node* right_child;
	logical data;
	short int value;
};

// thread node (Page 39~53)
// ���� : �����ڷῡ�� �̸��� thread_tree�̳�, �̸��� ���ϼ��� ���� ���Ƿ� �̸��� thread_node�� �ٲپ���.
struct thread_node {
	short int left_thread; // true or false
	struct thread_node* left_child; // left_thread = true : thread
	// left_thread = false: left child
	char data;
	struct thread_node* right_child; // right_thread�� ���� ����
	short int right_thread; // true or false
};

// (max) heap (Page 59~65)
typedef struct _element {
	int key;
	int data;
}element;
element heap[MAX_ELEMENTS];
int n = 0;

// ��� �Լ�
void push(struct node*);
void addq(struct node*);
struct node* pop();
struct node* deleteq();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void iter_inorder(struct node*);
void level_order(struct node*);
tree_pointer copy(struct node*);
tree_pointer swap_tree(struct node*);
int equal(struct node*, struct node*);
int get_node_count(struct node*);
int get_depth(struct node*);
int get_leaf_count(struct node*);
void post_order_eval(struct logical_node*, int);
struct thread_node* insucc(struct thread_node*);
struct thread_node* inpred(struct thread_node*);
void tinorder(struct thread_node*);
void tpreorder(struct thread_node*); // ���� �ȵ�. Page 51
void tpostorder(struct thread_node*); // ���� �ȵ�. Page 52
struct thread_node* find_parent(struct thread_node*); // ���� �ȵ�. Page 53
void insert_right(struct thread_node* parent, struct thread_node* child);
void insert_left(struct thread_node* parent, struct thread_node* child);
void insert_max_heap(int, int*);
void delete_max_heap(int*);

// ���⼭���ʹ� ��ƿ��Ƽ �Լ�
int MAX(int a, int b);
struct node* new_node(int);
struct logical_node* new_logical_node(logical, short int);
struct thread_node* new_thread_node(char, short int, short int);
struct node* get_sample_tree(int);
struct logical_node* get_sample_logical_tree(int);
struct thread_node* get_sample_thread_tree(int);

// main �Լ�
int main() {
	struct node* A = get_sample_tree(0);
	inorder(A);
}

/******************************/
// ��� �Լ�
/******************************/
void push(struct node* item)
{ // ���ÿ� ���ο� �׸��� �߰�
	if (top >= MAX_STACK_SIZE - 1) {
		printf("ERROR : stack is full!!");
		return;
	}
	stack[++top] = item;
}

struct node* pop()
{ // ���� top�� �׸��� return
	if (top == -1) {
		printf("ERROR : stack is empty!!");
		return NULL;
	}
	return stack[top--];
}

void addq(struct node* item)
{ // Queue�� ���ο� �׸��� �߰�
	if (rear >= MAX_QUEUE_SIZE - 1) {
		printf("ERROR : queue is full!!");
		return;
	}
	queue[++rear] = item;
}

struct node* deleteq()
{ // Queue�� �׸��� return
	if (front == rear) {
		printf("ERROR : queue is empty!!");
		return NULL;
	}
	return queue[++front];
}

void inorder(struct node* ptr) {
	if (ptr) {
		inorder(ptr->left_child);
		printf("%c ", ptr->data);
		inorder(ptr->right_child);
	}
}

void preorder(struct node* ptr) {
	if (ptr) {
		printf("%c ", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}

void postorder(struct node* ptr) {
	if (ptr) {
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%c ", ptr->data);
	}
}

void iter_inorder(struct node* node) {
	// ������ �̿��Ͽ� ���ȯ������ inorder traversal ����
	top = -1; // ���� �ʱ�ȭ

	for (;;) {
		for (; node; node = node->left_child)
			push(node); // ���� ������
		node = pop();
		if (!node) break; // ������ �� ��� ����
		printf("%c ", node->data);
		node = node->right_child;
	}
}

void level_order(struct node* ptr) {
	// ť�� �̿��Ͽ� level ������� ���� Ʈ�� ��ȸ
	front = 0, rear = 0; // ť �ʱ�ȭ

	if (!ptr) return; // empty tree
	addq(ptr); // add root node
	for (;;) {
		ptr = deleteq(); // get the current level nodes sequencely
		if (ptr == NULL) break;  // queue empty
		printf("%c ", ptr->data); // ���� ����� data ���
		if (ptr->left_child)
			addq(ptr->left_child);
		if (ptr->right_child)
			addq(ptr->right_child);
	}
}

tree_pointer copy(struct node* original) {
	// original Ʈ���� ������ ���ο� ���� Ʈ���� ��ȯ
	struct node* temp;
	if (original) {
		temp = (struct node*)malloc(sizeof(struct node));
		temp->left_child = copy(original->left_child);
		temp->right_child = copy(original->right_child);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}

tree_pointer swap_tree(struct node* original) {
	// original Ʈ������ root�� �������� ���ʰ� �������� ���� �ٲ� Ʈ���� �����ؼ� ��ȯ�Ѵ�.
	struct node* temp;
	if (original) {
		temp = (struct node*)malloc(sizeof(struct node));
		temp->right_child = swap_tree(original->left_child);
		temp->left_child = swap_tree(original->right_child);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}

int equal(struct node* first, struct node* second) {
	/* first�� second Ʈ���� �ٸ� ��� FALSE�� ��ȯ,
	   Ʈ���� ������ ���, TRUE�� ��ȯ */

	return
		// ������ �� ���� �� �ϳ��� true��� true�̴�.
		(!first && !second) // 1. �� Ʈ���� ���� ����ִ� Ʈ���� ���.
		|| // OR
		(first && // 2. first Ʈ���� �ְ�
			second && // second Ʈ���� �ְ�
			(first->data == second->data) && // �� Ʈ���� root�� data�� ����
			equal(first->left_child, second->left_child) && // �� Ʈ���� root->left_child ���� �ٽ� Ȯ���غ���
			equal(first->right_child, second->right_child)); // �� Ʈ���� root->right_child ���� �ٽ� Ȯ���غ���.
}

int get_node_count(struct node* ptr) {
	int count = 0;
	if (ptr != NULL)
		count = 1 + get_node_count(ptr->left_child) + get_node_count(ptr->right_child);
	return count;
}

int get_depth(struct node* ptr) {
	int depth = 0;
	if (ptr != NULL)
		depth = 1 + MAX(get_depth(ptr->left_child), get_depth(ptr->right_child));
	return depth;
}

int get_leaf_count(struct node* ptr) {
	int count = 0;

	if (ptr != NULL) {
		if (ptr->left_child == NULL &&
			ptr->right_child == NULL) // �ܸ� ���
			return 1;
		else count = get_leaf_count(ptr->left_child) + get_leaf_count(ptr->right_child);
	}
	return count;
}

void post_order_eval(struct logical_node* node, int set_this_parameter_to_one_to_print_result) {
	// ���� Ʈ���� ����ϱ� ���� postorder()�� ����
	if (node) {
		post_order_eval(node->left_child, 0);
		post_order_eval(node->right_child, 0);
		switch (node->data) {
		case not: node->value = !node->right_child->value; break;
		case and : node->value = node->left_child->value && node->right_child->value; break;
		case or : node->value = node->left_child->value || node->right_child->value; break;
		case true: node->value = 1; break; // �ܸ� ���
		case false: node->value = 0; // �ܸ� ���
		}
	}

	if (set_this_parameter_to_one_to_print_result == 1)
		printf("logical calculation result = %d\n", node->value);
}

struct thread_node* insucc(struct thread_node* ptr) {
	/* Threaded bianry tree���� ptr�� ����Ű�� ����� inorder successor�� ���� */
	/* ���� ����
	1. ptr�� root�� �� ���, ���� ���� �ܸ� ��带 �����Ѵ�. (root)
	2. ptr�� �ܸ� ��尡 �� ���, if() ���� �������� �ʾƼ� inorder successor�� �����Ѵ�. (Page 42�� ������ ���, H�� �ش�)
	3. ptr�� �Ϲ� ��尡 �� ���, if() ���� �����ϰ� ptr->right_child �������� �ٽ� �����Ͽ� ���� ���� �ܸ� ������ ����.
	(Page 42�� ������ ���, D�� �ش�)

	4. tinorder()�� �������� ���, 2,3���� �ݺ��Ǹ鼭 ���� ��ȸ�� �Ͼ��.
	*/
	struct thread_node* temp = ptr->right_child;

	if (!ptr->right_thread) // right_child�� child pointer
		while (!temp->left_thread) // ���� ������ ����
			temp = temp->left_child;
	return temp;
}

struct thread_node* inpred(struct thread_node* ptr) {
	// Threaded bianry tree���� ptr�� ����Ű�� ����� inorder predecessor�� ����
	struct thread_node* temp = ptr->left_child;
	if (!ptr->left_thread) {
		while (!temp->right_thread)
			temp = temp->right_child;
	}
	return temp;
}

void tinorder(struct thread_node* node) {
	// Threaded binary tree�� inorder traversal
	struct thread_node* temp = node;

	for (;;) {
		temp = insucc(temp);
		if (temp == node)
			break;
		printf("%c ", temp->data);
	}
}

void tpreorder(struct thread_node* node) {
	// Threaded binary tree�� preorder traversal
	printf("�������� ���� �Լ��Դϴ�.\n");
}

void tpostorder(struct thread_node* node) {
	// Threaded binary tree�� postorder traversal
	printf("�������� ���� �Լ��Դϴ�.\n");
}

struct thread_node* find_parent(struct thread_node* node) {
	// Threaded binary tree���� �Ű������� ���� node�� parent�� ��ȯ�մϴ�.
	printf("�������� ���� �Լ��Դϴ�.\n");
	return NULL;
}

void insert_right(struct thread_node* parent, struct thread_node* child) {
	// Threaded binary tree���� parent�� �����ʿ� child �߰�
	struct thread_node* temp;

	// child�� �������� ��������.
	// child�� �������� parent ������ ����
	child->right_child = parent->right_child;
	child->right_thread = parent->right_thread;
	// child�� ������ �ݵ�� parnet�� thread�� ����Ų��.
	child->left_child = parent;
	child->left_thread = 1;

	// parent ���� ����
	// parent�� �������� �ݵ�� child�� ����Ų��.
	parent->right_child = child;
	parent->right_thread = 0;
	// parent�� ������ �״�� �����Ѵ�.
	;

	// ������ parent�� ����Ǿ��� �����带 child�� �����Ű���� ����
	// ������ parent->right_thread�� ���� ��쿡��, ������ parent�� �����ʿ� ��尡 ����Ǿ��ִٴ� �ǹ��̴�.
	// ���� child�� �����ʿ� ��尡 ����Ǿ� �ִٴ� ���� �ȴ�.
	if (!child->right_thread) {
		temp = insucc(child); // ptr�� �Ϲ� ��尡 �� ���, if() ���� �����ϰ� ptr->right_child �������� �ٽ� �����Ͽ� ���� ���� �ܸ� ������ ����.
		temp->left_child = child; // ������ parent�� ����Ǿ��� �����带 child�� �����Ѵ�.
	}
}

void insert_left(struct thread_node* parent, struct thread_node* child) {
	// Threaded binary tree���� parent�� ���ʿ� child �߰�
	struct thread_node* temp;

	child->left_child = parent->left_child;
	child->left_thread = parent->left_thread;
	child->right_child = parent;
	child->right_thread = 1;

	parent->left_child = child;
	parent->left_thread = 0;

	if (!child->left_thread) {
		temp = inpred(child);
		temp->right_child = child;
	}
}

void insert_max_heap(element item, int* n) {
	// ��� ���� *n�� max heap�� item ���� �߰�
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full. \n");
		exit(1);
	}
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2]; // parent�� ���� �Ʒ��� �̵�
		i /= 2;
	}
	heap[i] = item;
}

void delete_max_heap(int* n) {

}

/***********************/
// ��ƿ��Ƽ �Լ� ����
/***********************/
int MAX(int a, int b) {
	return (a > b) ? a : b;
}

struct node* new_node(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

struct logical_node* new_logical_node(logical data) {
	struct logical_node* node = (struct logical_node*)malloc(sizeof(struct logical_node));
	node->data = data;
	node->value;
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

struct thread_node* new_thread_node(char data, short int left_thread, short int right_thread) {
	// thread�� ���� true�� 1, false�� 0

	struct thread_node* node = (struct thread_node*)malloc(sizeof(struct thread_node));
	node->left_thread = left_thread;
	node->left_child = NULL;
	node->data = data;
	node->right_child = NULL;
	node->right_thread = right_thread;

	return node;
}

struct node* get_sample_tree(int sample_num) {
	struct node* root = NULL;

	switch (sample_num) {
		// test data 1 : �����ڷ� 20~26 page
		// ���� : ABCDE�� /**+ ����
	case 1:
		root = new_node('+');

		root->left_child = new_node('*');
		root->right_child = new_node('E');

		root->left_child->left_child = new_node('*');
		root->left_child->right_child = new_node('D');

		root->left_child->left_child->left_child = new_node('/');
		root->left_child->left_child->right_child = new_node('C');

		root->left_child->left_child->left_child->left_child = new_node('A');
		root->left_child->left_child->left_child->right_child = new_node('B');

		return root;

		// test data 2 : �����ڷ� 29 page
		// ���� : A~J
	case 2:
		root = new_node('A');

		root->left_child = new_node('B');
		root->right_child = new_node('C');

		root->left_child->left_child = new_node('D');
		root->left_child->right_child = new_node('E');
		root->right_child->left_child = new_node('F');
		root->right_child->right_child = new_node('G');

		root->left_child->right_child->left_child = new_node('H');
		root->right_child->left_child->right_child = new_node('I');

		root->right_child->left_child->right_child->left_child = new_node('J');

		return root;

		// test data 3,4,5,6 : �����ڷ� 31 page
		// ���� : �׸��� ���� ������ 3, ���� ����� 4, ���� �������� 5, �Ʒ����� 6
	case 3:
		root = new_node(1);

		root->left_child = new_node(2);
		root->right_child = new_node(4);

		root->left_child->right_child = new_node(3);
		root->right_child->left_child = new_node(5);
		root->right_child->right_child = new_node(6);

		return root;
	case 4:
		root = new_node(1);

		root->left_child = new_node(2);
		root->right_child = new_node(4);

		root->left_child->right_child = new_node(3);
		root->right_child->left_child = new_node(5);

		return root;
	case 5:
		root = new_node(7);

		root->left_child = new_node(2);
		root->right_child = new_node(4);

		root->left_child->right_child = new_node(3);
		root->right_child->left_child = new_node(5);
		root->right_child->right_child = new_node(6);

		return root;
	case 6:
		root = new_node(1);

		root->left_child = new_node(4);
		root->right_child = new_node(2);

		root->left_child->right_child = new_node(3);
		root->right_child->left_child = new_node(5);
		root->right_child->right_child = new_node(6);

		return root;
	}
}

struct logical_node* get_sample_logical_tree(int sample_num) {
	logical X1, X2, X3; // logical root�� ���Ǵ� ���� ��.
	struct logical_node* root = NULL;

	switch (sample_num) {
		// test data 0 : �����ڷ� 36 page
		// ���� : ���� Ʈ��
	case 0:
		// X1, X2, X3 ���� ����(true �ƴϸ� false)
		// ���� : true, true, true�� ������ ����� false, ������ ����� ����� true
		X1 = false;
		X2 = true;
		X3 = true;

		root = new_logical_node(or );

		root->left_child = new_logical_node(or );
		root->right_child = new_logical_node(not);

		root->left_child->left_child = new_logical_node(and);
		root->left_child->right_child = new_logical_node(and);
		root->right_child->right_child = new_logical_node(X3);

		root->left_child->left_child->left_child = new_logical_node(X1);
		root->left_child->left_child->right_child = new_logical_node(not);
		root->left_child->right_child->left_child = new_logical_node(not);
		root->left_child->right_child->right_child = new_logical_node(X3);

		root->left_child->left_child->right_child->right_child = new_logical_node(X2);
		root->left_child->right_child->left_child->right_child = new_logical_node(X1);

		return root;
	}
}

struct thread_node* get_sample_thread_tree(int sample_num) {
	struct thread_node* root = NULL;
	struct thread_node* A, * B, * C, * D, * E, * F, * G, * H, * I, * X;

	switch (sample_num) {
		// test data 0 : �����ڷ� 40~42 page
		// ���� : ������ȸ H D I B E A F C G
	case 0:
		root = new_thread_node(NULL, 0, 0);
		A = new_thread_node('A', 0, 0);
		B = new_thread_node('B', 0, 0);
		C = new_thread_node('C', 0, 0);
		D = new_thread_node('D', 0, 0);
		E = new_thread_node('E', 1, 1);
		F = new_thread_node('F', 1, 1);
		G = new_thread_node('G', 1, 1);
		H = new_thread_node('H', 1, 1);
		I = new_thread_node('I', 1, 1);

		root->left_child = A;
		root->right_child = root;

		A->left_child = B;
		A->right_child = C;

		B->left_child = D;
		B->right_child = E;
		C->left_child = F;
		C->right_child = G;

		D->left_child = H;
		D->right_child = I;
		E->left_child = B;
		E->right_child = A;
		F->left_child = A;
		F->right_child = C;
		G->left_child = C;
		G->right_child = root;

		H->left_child = root;
		H->right_child = D;
		I->left_child = D;
		I->right_child = B;

		return root;

		// test data 1 : �����ڷ� 46 page
		// ���� : ABC + D(�Լ����� D�� ���� �߰�)
	case 1:
		root = new_thread_node(NULL, 0, 0);
		A = new_thread_node('A', 1, 0);
		B = new_thread_node('B', 0, 1);
		C = new_thread_node('C', 1, 1);

		root->left_child = A;
		root->right_child = root;

		A->left_child = root;
		A->right_child = B;

		B->left_child = C;
		B->right_child = root;

		C->left_child = A;
		C->right_child = B;

		return root;

		// test data 2 : �����ڷ� 47 page
		// ���� : ABCDEF + X(�Լ����� X�� ���� �߰�)
	case 2:
		root = new_thread_node(NULL, 0, 0);
		A = new_thread_node('A', 1, 0);
		B = new_thread_node('B', 0, 0);
		C = new_thread_node('C', 1, 1);
		D = new_thread_node('D', 0, 0);
		E = new_thread_node('E', 1, 1);
		F = new_thread_node('F', 1, 1);

		root->left_child = A;
		root->right_child = root;

		A->left_child = root;
		A->right_child = B;

		B->left_child = C;
		B->right_child = D;

		C->left_child = A;
		C->right_child = B;

		D->left_child = E;
		D->right_child = F;

		E->left_child = B;
		E->right_child = D;

		F->left_child = D;
		F->right_child = root;

		return root;

		// test data 3 : �����ڷ� 49 page ���� �׸�
		// ���� : ABD + C(�Լ����� C�� ���� �߰�)
	case 3:
		root = new_thread_node(NULL, 0, 0);
		A = new_thread_node('A', 1, 0);
		B = new_thread_node('B', 1, 0);
		D = new_thread_node('D', 1, 1);

		root->left_child = A;
		root->right_child = root;

		A->left_child = root;
		A->right_child = B;

		B->left_child = A;
		B->right_child = D;

		D->left_child = B;
		D->right_child = root;

		return root;

		// test data 4 : �����ڷ� 49 page ������ �׸�
		// ���� : ABCDEF + X(�Լ����� X�� ���� �߰�)
	case 4:
		root = new_thread_node(NULL, 0, 0);
		A = new_thread_node('A', 1, 0);
		B = new_thread_node('B', 0, 0);
		C = new_thread_node('C', 0, 0);
		D = new_thread_node('D', 1, 1);
		E = new_thread_node('E', 1, 1);
		F = new_thread_node('F', 1, 1);

		root->left_child = A;
		root->right_child = root;

		A->left_child = root;
		A->right_child = B;

		B->left_child = C;
		B->right_child = D;

		C->left_child = E;
		C->right_child = F;

		D->left_child = B;
		D->right_child = root;

		E->left_child = A;
		E->right_child = C;

		F->left_child = C;
		F->right_child = B;

		return root;
	}

}