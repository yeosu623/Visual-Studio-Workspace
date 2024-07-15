#include "MyStack.h"

MyStack::MyStack(int capacity) : BaseArray(capacity) { top = 0; } // MyStack ������. BaseArray�� �����ڵ� ���� ȣ����Ѽ� �迭�� �������ش�. ���� ��ġ(top)�� 0�̴�.

void MyStack::push(int val) { // Stack�� ���� �ִ� �Լ�
	if (top == getCapacity()) { // ���� top�� Stack�� ũ�Ⱑ ���ٸ�
		cout << "Stack Full!! -- ���� �뷮 �ø�!" << '\n'; // Stack�� �� á�ٴ� ���� �ǹ��Ѵ�.
		doubleCapacity(); // �׷��Ƿ� Stack�� ũ�⸦ 2��� �ø���.
	}
	put(top++, val); // Stack�� ���� �־��ְ�, ���� �����͸� ���� �غ� �ϱ� ���ؼ� top�� 1 �ø���.
}
int MyStack::pop() { // Stack���� ���� ���� �Լ�
	if (top == 0) { // ���� top�� 0�̶��
		cout << "Stack Empty!!" << '\n'; // Stack�� ����ִٴ� ���� �ǹ�����.
		return ERROR_VAL; // �׷��Ƿ� �������� ��ȯ���ش�.
	}
	return get(--top); // ���������� ���۽ÿ��� Stack���� �� ���� �ִ� ���� ���ְ�, ���� �����͸� �� �غ� �ϱ� ���ؼ� top�� 1 ������.
}
int MyStack::capacity() { return getCapacity(); } // Stack�� �뷮(�ִ� ũ��)�� ��ȯ�ϴ� �Լ�
int MyStack::length() { return top; } // Stack�� ��� �������� ������ ��ȯ�ϴ� �Լ�.