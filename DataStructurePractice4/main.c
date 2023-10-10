#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Stack
int max_stack_size = 3; // 초기값
int* stack, top = -1;
void printStack();
void push(int);
int pop();

// Queue
int max_queue_size = 3; // 초기값
int* queue, front = -1, rear = -1;
void printQueue();
void add_q(int);
int delete_q();

// Circular Queue
int max_cqueue_size = 3; // 초기값
int* cqueue, cfront = 0, crear = 0;
void printCQueue();
void add_cq(int);
int delete_cq();

int main() {
	stack = (int*)malloc(sizeof(int) * max_stack_size);
	queue = (int*)malloc(sizeof(int) * max_queue_size);
	cqueue = (int*)malloc(sizeof(int) * max_cqueue_size);
}

void printStack() {
	int i;

	printf("stack = ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("\n");
}

void push(int item) {
	if (top >= max_stack_size - 1) {
		max_stack_size *= 2;
		stack = (int*)realloc(stack, sizeof(int) * max_stack_size);
		printf("stack extended. now stack size : %d\n", max_stack_size);
	}
	stack[++top] = item;
}

int pop() {
	if (top == -1) {
		printf("stack is empty! pop doesn't be operated.\n");
		return;
	}
	return stack[top--];
}

void printQueue() {
	int i;

	printf("queue = ");
	for (i = front + 1; i <= rear; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");
}

void add_q(int item) {
	if (rear >= max_queue_size - 1) {
		max_queue_size *= 2;
		queue = (int*)realloc(queue, sizeof(int) * max_queue_size);
		printf("queue extended. now queue size : %d\n", max_queue_size);
	}
	queue[++rear] = item;
}

int delete_q() {
	if (front == rear) {
		printf("queue is empty! delete_q doesn't be operated.\n");
		return;
	}
	return queue[++front];
}

void printCQueue() {
	int i;

	printf("cqueue = ");
	if (cfront <= crear) {
		for (i = cfront + 1; i <= crear; i++) {
			printf("%d ", cqueue[i]);
		}
	}
	else {
		for (i = cfront + 1; i <= crear + max_cqueue_size; i++) {
			printf("%d ", cqueue[i % max_cqueue_size]);
		}
	}
	printf("\n");
}

void add_cq(int item) {
	int i;
	int past_cqueue_size;

	crear = (crear + 1) % max_cqueue_size;
	if (crear == cfront) {
		past_cqueue_size = max_cqueue_size;

		max_cqueue_size *= 2;
		cqueue = (int*)realloc(cqueue, sizeof(int) * max_cqueue_size);

		for (i = crear; i < past_cqueue_size; i++) {
			cqueue[i + past_cqueue_size] = cqueue[i];
		}
		cfront += past_cqueue_size;
		
		printf("cqueue extended. now cqueue size : %d\n", max_cqueue_size);
	}
	cqueue[crear] = item;
}

int delete_cq() {
	if (cfront == crear) {
		printf("cqueue is empty! delete_cq doesn't be operated.\n");
		return;
	}
	cfront = (cfront + 1) % max_cqueue_size;
	return cqueue[cfront];
}