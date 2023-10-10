#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Stack {
private:
	T* stack;
	int top;
	int max_size;

public:
	Stack(int size) {
		stack = new T[size];
		top = -1;
		max_size = size;
	}

	void printStack() {
		int i;

		printf("stack = ");
		for (i = 0; i <= top; i++)
			cout << stack[i] << " ";
		printf("\n");
	}

	void push(T item) {
		if (top >= max_size - 1) {
			max_size *= 2;
			T* new_stack = new T[max_size];
			copy(stack, stack + (max_size / 2), new_stack);
			delete[] stack;
			stack = new_stack;
			new_stack = NULL;
			
			printf("stack extended. now stack size : %d\n", max_size);
		}
		stack[++top] = item;
	}

	T pop() {
		if (top == -1) {
			printf("stack is empty! pop doesn't be operated.\n");
			return -2147483648;
		}
		return stack[top--];
	}
};

template <typename T>
class Queue {
private :
	T* queue;
	int max_size;
	int front;
	int rear;
	
public :
	Queue(int size) {
		queue = new T[size];
		max_size = size;
		front = -1;
		rear = -1;
	}

	void printQueue() {
		int i;

		printf("queue = ");
		for (i = front + 1; i <= rear; i++) {
			cout << queue[i] << " ";
		}
		printf("\n");
	}

	void add_q(T item) {
		if (rear >= max_size - 1) {
			max_size *= 2;
			T* new_queue = new T[max_size];
			copy(queue, queue + (max_size / 2), new_queue);
			delete[] queue;
			queue = new_queue;
			new_queue = NULL;
			
			printf("queue extended. now queue size : %d\n", max_size);
		}
		queue[++rear] = item;
	}

	T delete_q() {
		if (front == rear) {
			printf("queue is empty! delete_q doesn't be operated.\n");
			return -2147483648;
		}
		return queue[++front];
	}
};

template <typename T>
class CQueue {
private:
	T* cqueue;
	int max_size;
	int cfront;
	int crear;

public:
	CQueue(int size) {
		cqueue = new T[size];
		max_size = size;
		cfront = 0;
		crear = 0;
	}

	void printCQueue() {
		int i;

		printf("cqueue = ");
		if (cfront <= crear) {
			for (i = cfront + 1; i <= crear; i++) {
				cout << cqueue[i] << " ";
			}
		}
		else {
			for (i = cfront + 1; i <= crear + max_size; i++) {
				cout << cqueue[i % max_size] << " ";
			}
		}
		printf("\n");
	}

	void add_cq(T item) {
		int i;
		int past_cqueue_size;

		crear = (crear + 1) % max_size;
		if (crear == cfront) {
			past_cqueue_size = max_size;

			max_size *= 2;
			T* new_cqueue = new T[max_size];
			copy(cqueue, cqueue + (max_size / 2), new_cqueue);
			delete[] cqueue;
			cqueue = new_cqueue;
			new_cqueue = NULL;

			for (i = crear; i < past_cqueue_size; i++) {
				cqueue[i + past_cqueue_size] = cqueue[i];
			}
			cfront += past_cqueue_size;

			printf("cqueue extended. now cqueue size : %d\n", max_size);
		}
		cqueue[crear] = item;
	}

	T delete_cq() {
		if (cfront == crear) {
			printf("cqueue is empty! delete_cq doesn't be operated.\n");
			return -2147483648;
		}
		cfront = (cfront + 1) % max_size;
		return cqueue[cfront];
	}
};

int main() {
	int i;
	Stack<char> stack = Stack<char>(3);
	Queue<char> queue = Queue<char>(3);
	CQueue<char> cqueue = CQueue<char>(3);

	for (i = 0; i < 1000; i++) {
		stack.push('a');
		queue.add_q('b');
		cqueue.add_cq('c');
	}

	for (i = 0; i < 998; i++) {
		stack.pop();
		queue.delete_q();
		cqueue.delete_cq();
	}

	stack.printStack();
	queue.printQueue();
	cqueue.printCQueue();
}