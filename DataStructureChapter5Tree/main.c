#define TRUE 1
#define FALSE 0
#define MAX_HEAP 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct node* tree_pointer;
struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
};

struct thread_node {
	int lthread;
	struct thread_node* lchild;
	int data;
	struct thread_node* rchild;
	int rthread;
};

typedef struct {
	int key;
	int value;
} element;
element heap[MAX_HEAP];
int n = 0;

void inorder(struct node* ptr) {
	if (ptr) {
		inorder(ptr->lchild);
		printf("%d", ptr->data);
		inorder(ptr->rchild);
	}
}

void preorder(struct node* ptr) {
	if (ptr) {
		printf("%d", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(struct node* ptr) {
	if (ptr) {
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d", ptr->data);
	}
}

void iter_inorder(struct node* ptr) {
	int top = -1;
	struct node* stack[1000];

	for (;;) {
		for (; ptr; ptr = ptr->lchild)
			push(ptr); // 왼쪽 끝으로

		ptr = pop();
		if (!ptr) break;

		printf("%d", ptr->data);
		ptr = ptr->rchild;
	}
}

void level_order(struct node* ptr) {
	int front = 0, rear = 0;
	struct node* queue[1000];

	if (!ptr) return; // empty tree

	addq(ptr);
	for (;;) {
		ptr = deleteq();

		if (ptr == NULL) break;
		printf("%d", ptr->data);

		if (ptr->lchild)
			addq(ptr->lchild);
		if (ptr->rchild)
			addq(ptr->rchild);
	}
}

struct node* copy(struct node* original) {
	struct node* temp;

	if (original) {
		temp = (struct node*)malloc(sizeof(struct node));

		temp->lchild = copy(original->lchild);
		temp->rchild = copy(original->rchild);
		temp->data = original->data;

		return temp;
	}
	return NULL;
}

int equal(struct node* first, struct node* second) {
	return ((!first && !second) || // both empty tree
		(first && second && (first->data == second->data) && // is root equal?
			equal(first->lchild, second->lchild) && // is lchilds equal?
			equal(first->rchild, second->rchild))); // is rchilds equal?
}

int get_node_count(struct node* ptr) {
	int count = 0;
	if (ptr != NULL)
		count = 1 + get_node_count(ptr->lchild) + get_node_count(ptr->rchild);

	return count;
}

int get_depth_count(struct node* ptr) {
	int count = 0;
	if (ptr != NULL)
		count = 1 + MAX(get_depth_count(ptr->lchild), get_depth_count(ptr->rchild));

	return count;
}

int get_leaf_count(struct node* ptr) {
	int count = 0;
	if (ptr != NULL) {
		if (ptr->lchild == NULL && ptr->rchild == NULL) // 단말 노드
			return 1;
		else
			count = get_leaf_count(ptr->lchild) + get_leaf_count(ptr->rchild);
	}

	return count;
}

struct thread_node* insucc(struct thread_node* ptr) {
	struct thread_node* temp = ptr->rchild;

	if (!ptr->rthread)
		while (!temp->lthread)
			temp = temp->lchild;

	return temp;
}

struct thread_node* inpred(struct thread_node* ptr) {
	struct thread_node* temp = ptr->lchild;

	if (!ptr->lthread)
		while (!temp->rthread)
			temp = temp->rchild;

	return temp;
}

void insert_right(struct thread_node* parent, struct thread_node* child) {
	struct thread_node* temp;

	child->rchild = parent->rchild;
	child->rthread = parent->rthread;
	child->lchild = parent;
	child->lthread = TRUE;

	parent->rchild = child;
	parent->rthread = FALSE;

	if (!child->rthread) {
		temp = insucc(child);
		temp->lchild = child;
	}
}

void insert_left(struct thread_node* parent, struct thread_node* child) {
	// Threaded binary tree에서 parent의 왼쪽에 child 추가
	struct thread_node* temp;

	child->lchild = parent->lchild;
	child->lthread = parent->lthread;
	child->rchild = parent;
	child->rthread = TRUE;

	parent->lchild = child;
	parent->lthread = FALSE;

	if (!child->lthread) {
		temp = inpred(child);
		temp->rchild = child;
	}
}

void thread_inorder(struct thread_node* ptr) {
	struct thread_node* temp = ptr;

	for (;;) {
		temp = insucc(temp);
		if (temp == ptr) break;

		printf("%d", temp->data);
	}
}

void insert_max_heap(element item, int* n) {
	// 노드 수가 *n인 max_heap에 item 값을 추가
	int i;
	if (*n == MAX_HEAP - 1) { // HEAP_FULL
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}

	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i = i / 2;
	}
	heap[i] = item;
}

element delete_max_heap(int* n) {
	int parent, child;
	element item, temp;

	if (!(*n)) { // heap empty
		fprintf(stderr, "The heap is empty\n");
		exit(1);
	}

	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;

	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key)
			break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = temp;
	return item;
}

struct node* search(struct node* root, int key) {
	// recursive version
	if (!root) return NULL;
	if (key == root->data) return root;
	if (key < root->data) return search(root->lchild, key);
	return search(root->rchild, key);
}

struct node* iterSearch(struct node* tree, int key) {
	// iterative version
	while (tree != NULL) {
		if (key == tree->data) return tree;
		if (key < tree->data) tree = tree->lchild;
		else tree = tree->rchild;
	}
	return NULL;
}

void insert_node(struct node** root, int num) {
	struct node* ptr, *parent = modified_search(*root, num);

	if (parent || !(*root)) { // num이 tree에 존재하지 않는다.
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = num;
		ptr->lchild = ptr->rchild = NULL;

		if (*root) {
			if (num < parent->data) parent->lchild = ptr;
			else parent->rchild = ptr;
		}
		else *root = ptr;
	}
}

struct node* modified_search(struct node* root, int key) {
	for (struct node* ptr = root; ptr != NULL;) {
		if (ptr->data == key) return NULL;
		if (key < ptr->data) {
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