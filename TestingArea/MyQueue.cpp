#include "MyQueue.h"

MyQueue::MyQueue(int capacity) : BaseArray(capacity) { // MyQueue ������. BaseArray�� �����ڵ� ���� ȣ����Ѽ� �迭�� �������ش�.
	rear = 0; // ���� ��ġ�� 0���� ����
	front = 0; // ���� ��ġ�� 0���� ����
}

void MyQueue::enqueue(int val) { // Queue�� ���� �ִ� �Լ�
	if (rear == getCapacity()) { // ���� ���� ��ġ�� Queue�� ũ��� ���ٸ�,
		cout << "Queue Full!!-- ť �뷮 �ø�!" << '\n'; // Queue�� �� �� ���� �ǹ��Ѵ�.
		doubleCapacity(); // �׷��Ƿ� Queue�� ũ�⸦ 2��� �ø���.
	}
	put(rear++, val); // Queue�� ���� �־��ְ�, ���� �����͸� ���� �غ� �ϱ� ���ؼ� rear�� 1 �ø���.
}
int MyQueue::dequeue() { // Queue���� ���� ���� �Լ�
	if (front == rear) { // ���� ���� ��ġ�� ���� ��ġ�� ���ٸ�,
		cout << "Queue Empty!!" << '\n'; // Queue�� �� ���� �ǹ��Ѵ�.
		return ERROR_VAL; // �׷ιǷ� ���� ���� ��ȯ���ش�.
	}
	return get(front++); // ���������� ���۽ÿ��� �� ���� ���� ��ȯ�ϰ�, ���� �����͸� �� �غ� �ϱ� ���ؼ� front�� 1 �ø���.
}
int MyQueue::capacity() { return getCapacity(); } // Queue�� �뷮(�ִ� ũ��)�� ��ȯ�ϴ� �Լ�
int MyQueue::length() { return rear - front; } // Queue�� ��� �������� ������ ��ȯ�ϴ� �Լ�
