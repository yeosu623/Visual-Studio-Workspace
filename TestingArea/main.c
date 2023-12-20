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
			push(ptr);

		ptr = pop();
		if (!ptr) break;

		printf("%d", ptr->data);
		ptr = ptr->rchild;
	}
}

void level_order(struct node* ptr) {
	int front = 0, rear = 0;
	struct node* queue[1000];

	if (!ptr) return;

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
	return ((!first && !second) ||
		(first && second && (first->data && second->data) &&
			equal(first->lchild, second->lchild) &&
			equal(first->rchild, second->rchild)));
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
		if (ptr->lchild == NULL && ptr->rchild == NULL)
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
	int i;

	if (*n == MAX_HEAP - 1) {
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

	if (!(*n)) {
		fprintf(stderr, "The heap is empty.\n");
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