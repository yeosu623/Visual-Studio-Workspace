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
// 참고 : 강의자료에서 이름은 thread_tree이나, 이름의 통일성을 위해 임의로 이름을 thread_node로 바꾸었다.
struct thread_node {
	short int left_thread; // true or false
	struct thread_node* left_child; // left_thread = true : thread
	// left_thread = false: left child
	char data;
	struct thread_node* right_child; // right_thread에 따라 결정
	short int right_thread; // true or false
};

// (max) heap (Page 59~65)
typedef struct _element {
	int key;
	int data;
}element;
element heap[MAX_ELEMENTS];
int n = 0;

// 기능 함수
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
void tpreorder(struct thread_node*); // 구현 안됨. Page 51
void tpostorder(struct thread_node*); // 구현 안됨. Page 52
struct thread_node* find_parent(struct thread_node*); // 구현 안됨. Page 53
void insert_right(struct thread_node* parent, struct thread_node* child);
void insert_left(struct thread_node* parent, struct thread_node* child);
void insert_max_heap(int, int*);
void delete_max_heap(int*);

// 여기서부터는 유틸리티 함수
int MAX(int a, int b);
struct node* new_node(int);
struct logical_node* new_logical_node(logical, short int);
struct thread_node* new_thread_node(char, short int, short int);
struct node* get_sample_tree(int);
struct logical_node* get_sample_logical_tree(int);
struct thread_node* get_sample_thread_tree(int);

// main 함수
int main() {
	struct node* A = get_sample_tree(0);
	inorder(A);
}

/******************************/
// 기능 함수
/******************************/
void push(struct node* item)
{ // 스택에 새로운 항목을 추가
	if (top >= MAX_STACK_SIZE - 1) {
		printf("ERROR : stack is full!!");
		return;
	}
	stack[++top] = item;
}

struct node* pop()
{ // 스택 top의 항목을 return
	if (top == -1) {
		printf("ERROR : stack is empty!!");
		return NULL;
	}
	return stack[top--];
}

void addq(struct node* item)
{ // Queue에 새로운 항목을 추가
	if (rear >= MAX_QUEUE_SIZE - 1) {
		printf("ERROR : queue is full!!");
		return;
	}
	queue[++rear] = item;
}

struct node* deleteq()
{ // Queue의 항목을 return
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
	// 스택을 이용하여 비순환적으로 inorder traversal 구현
	top = -1; // 스택 초기화

	for (;;) {
		for (; node; node = node->left_child)
			push(node); // 왼쪽 끝으로
		node = pop();
		if (!node) break; // 스택이 빌 경우 종료
		printf("%c ", node->data);
		node = node->right_child;
	}
}

void level_order(struct node* ptr) {
	// 큐를 이용하여 level 순서대로 이진 트리 순회
	front = 0, rear = 0; // 큐 초기화

	if (!ptr) return; // empty tree
	addq(ptr); // add root node
	for (;;) {
		ptr = deleteq(); // get the current level nodes sequencely
		if (ptr == NULL) break;  // queue empty
		printf("%c ", ptr->data); // 현재 노드의 data 출력
		if (ptr->left_child)
			addq(ptr->left_child);
		if (ptr->right_child)
			addq(ptr->right_child);
	}
}

tree_pointer copy(struct node* original) {
	// original 트리를 복사한 새로운 이진 트리를 반환
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
	// original 트리에서 root를 기준으로 왼쪽과 오른쪽을 서로 바꾼 트리를 복사해서 반환한다.
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
	/* first와 second 트리가 다를 경우 FALSE를 반환,
	   트리가 동일할 경우, TRUE를 반환 */

	return
		// 다음의 두 조건 중 하나가 true라면 true이다.
		(!first && !second) // 1. 두 트리가 전부 비어있는 트리인 경우.
		|| // OR
		(first && // 2. first 트리가 있고
			second && // second 트리가 있고
			(first->data == second->data) && // 두 트리의 root의 data가 같고
			equal(first->left_child, second->left_child) && // 두 트리의 root->left_child 노드로 다시 확인해보고
			equal(first->right_child, second->right_child)); // 두 트리의 root->right_child 노드로 다시 확인해본다.
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
			ptr->right_child == NULL) // 단말 노드
			return 1;
		else count = get_leaf_count(ptr->left_child) + get_leaf_count(ptr->right_child);
	}
	return count;
}

void post_order_eval(struct logical_node* node, int set_this_parameter_to_one_to_print_result) {
	// 논리식 트리를 계산하기 위한 postorder()의 변형
	if (node) {
		post_order_eval(node->left_child, 0);
		post_order_eval(node->right_child, 0);
		switch (node->data) {
		case not: node->value = !node->right_child->value; break;
		case and : node->value = node->left_child->value && node->right_child->value; break;
		case or : node->value = node->left_child->value || node->right_child->value; break;
		case true: node->value = 1; break; // 단말 노드
		case false: node->value = 0; // 단말 노드
		}
	}

	if (set_this_parameter_to_one_to_print_result == 1)
		printf("logical calculation result = %d\n", node->value);
}

struct thread_node* insucc(struct thread_node* ptr) {
	/* Threaded bianry tree에서 ptr이 가리키는 노드의 inorder successor를 리턴 */
	/* 동작 원리
	1. ptr에 root가 들어갈 경우, 가장 왼쪽 단말 노드를 리턴한다. (root)
	2. ptr에 단말 노드가 들어갈 경우, if() 문이 동작하지 않아서 inorder successor를 리턴한다. (Page 42의 예제의 경우, H가 해당)
	3. ptr에 일반 노드가 들어갈 경우, if() 문이 동작하고 ptr->right_child 에서부터 다시 시작하여 가장 왼쪽 단말 노드까지 간다.
	(Page 42의 예제의 경우, D가 해당)

	4. tinorder()를 실행했을 경우, 2,3번이 반복되면서 중위 순회가 일어난다.
	*/
	struct thread_node* temp = ptr->right_child;

	if (!ptr->right_thread) // right_child가 child pointer
		while (!temp->left_thread) // 왼쪽 끝까지 가자
			temp = temp->left_child;
	return temp;
}

struct thread_node* inpred(struct thread_node* ptr) {
	// Threaded bianry tree에서 ptr이 가리키는 노드의 inorder predecessor를 리턴
	struct thread_node* temp = ptr->left_child;
	if (!ptr->left_thread) {
		while (!temp->right_thread)
			temp = temp->right_child;
	}
	return temp;
}

void tinorder(struct thread_node* node) {
	// Threaded binary tree를 inorder traversal
	struct thread_node* temp = node;

	for (;;) {
		temp = insucc(temp);
		if (temp == node)
			break;
		printf("%c ", temp->data);
	}
}

void tpreorder(struct thread_node* node) {
	// Threaded binary tree를 preorder traversal
	printf("구현되지 않은 함수입니다.\n");
}

void tpostorder(struct thread_node* node) {
	// Threaded binary tree를 postorder traversal
	printf("구현되지 않은 함수입니다.\n");
}

struct thread_node* find_parent(struct thread_node* node) {
	// Threaded binary tree에서 매개변수로 받은 node의 parent를 반환합니다.
	printf("구현되지 않은 함수입니다.\n");
	return NULL;
}

void insert_right(struct thread_node* parent, struct thread_node* child) {
	// Threaded binary tree에서 parent의 오른쪽에 child 추가
	struct thread_node* temp;

	// child의 정보부터 변경하자.
	// child의 오른쪽은 parent 정보와 동일
	child->right_child = parent->right_child;
	child->right_thread = parent->right_thread;
	// child의 왼쪽은 반드시 parnet를 thread로 가리킨다.
	child->left_child = parent;
	child->left_thread = 1;

	// parent 정보 변경
	// parent의 오른쪽은 반드시 child를 가리킨다.
	parent->right_child = child;
	parent->right_thread = 0;
	// parent의 왼쪽은 그대로 유지한다.
	;

	// 기존에 parent에 연결되었던 쓰레드를 child로 연결시키도록 변경
	// 본래의 parent->right_thread가 없는 경우에는, 본래의 parent의 오른쪽에 노드가 연결되어있다는 의미이다.
	// 따라서 child의 오른쪽에 노드가 연결되어 있다는 말이 된다.
	if (!child->right_thread) {
		temp = insucc(child); // ptr에 일반 노드가 들어갈 경우, if() 문이 동작하고 ptr->right_child 에서부터 다시 시작하여 가장 왼쪽 단말 노드까지 간다.
		temp->left_child = child; // 기존에 parent에 연결되었던 쓰레드를 child로 변경한다.
	}
}

void insert_left(struct thread_node* parent, struct thread_node* child) {
	// Threaded binary tree에서 parent의 왼쪽에 child 추가
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
	// 노드 수가 *n인 max heap에 item 값을 추가
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full. \n");
		exit(1);
	}
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2]; // parent의 값을 아래로 이동
		i /= 2;
	}
	heap[i] = item;
}

void delete_max_heap(int* n) {

}

/***********************/
// 유틸리티 함수 모음
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
	// thread의 값은 true는 1, false는 0

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
		// test data 1 : 강의자료 20~26 page
		// 내용 : ABCDE와 /**+ 수식
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

		// test data 2 : 강의자료 29 page
		// 내용 : A~J
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

		// test data 3,4,5,6 : 강의자료 31 page
		// 내용 : 그림의 윗쪽 왼쪽이 3, 윗쪽 가운데가 4, 윗쪽 오른쪽이 5, 아랫쪽이 6
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
	logical X1, X2, X3; // logical root에 사용되는 변수 값.
	struct logical_node* root = NULL;

	switch (sample_num) {
		// test data 0 : 강의자료 36 page
		// 내용 : 논리식 트리
	case 0:
		// X1, X2, X3 값을 설정(true 아니면 false)
		// 참고 : true, true, true를 넣으면 결과는 false, 나머지 경우의 결과는 true
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
		// test data 0 : 강의자료 40~42 page
		// 내용 : 중위순회 H D I B E A F C G
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

		// test data 1 : 강의자료 46 page
		// 내용 : ABC + D(함수에서 D는 직접 추가)
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

		// test data 2 : 강의자료 47 page
		// 내용 : ABCDEF + X(함수에서 X는 직접 추가)
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

		// test data 3 : 강의자료 49 page 왼쪽 그림
		// 내용 : ABD + C(함수에서 C는 직접 추가)
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

		// test data 4 : 강의자료 49 page 오른쪽 그림
		// 내용 : ABCDEF + X(함수에서 X는 직접 추가)
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