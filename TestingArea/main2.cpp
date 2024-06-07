#define ERROR_VAL -999 // ���� ��ȯ��
#include <iostream> // ����� ���� ������� ��Ŭ��� ���ֱ�
using namespace std; // "std" namespace �ۼ� ����

class BaseArray { // �ܼ� �迭�� ��Ÿ���� BaseArray Ŭ����.
private: // ���� ���� �ܺο��� ���� ������ �� ������ private ������ �Ѵ�.
	int capacity; // �迭�� ũ��
	int* mem; // ���� �迭
protected: // �� �迭�� ���� ������� ����, �ٸ� ������ ����Ͽ� �ٸ��� ����ϵ��� protected ������ �Ѵ�.
	BaseArray(int capacity = 100) { // BaseArray ������. ���� ���� ������ �迭�� ũ�⸦ 100���� �����Ѵ�.
		this->capacity = capacity; // �迭�� ũ�� ����
		mem = new int[capacity]; // ���� �迭�� �޸� �Ҵ�
	}
	~BaseArray() { delete[] mem; } // BaseArray �Ҹ���. BaseArray ��ü�� �Ҹ�� �� �ڵ����� ȣ��Ǹ�, �� �� ���� �迭�� �Ҵ�� �޸𸮸� ������Ų��.

	void put(int index, int val) { mem[index] = val; } // put() : �迭���� ������ �ε����� ���� �ִ´�.
	int get(int index) { return mem[index]; } // get() : �迭���� ������ �ε����� ���� ������.
	int getCapacity() { return capacity; } // getCapacity() : �迭�� ũ�⸦ ��ȯ�Ѵ�.
	void doubleCapacity() { // doubleCapacity() : �迭�� ũ�⸦ 2��� �ø���.
		capacity *= 2; // �迭�� ũ�⸦ 2��� �����Ѵ�.

		// �� �� ������ �迭���� Ȯ��� �迭�� ���� �ϳ��� �Ű��־�� �Ѵ�.
		int* extend_mem = new int[capacity]; // Ȯ��� �迭�� �޸𸮸� �������ְ�,
		for (int i = 0; i < capacity / 2; i++) // ������ �迭�� �ִ� ���� Ȯ��� �迭�� �ϳ��� �ű��.
			extend_mem[i] = mem[i];

		delete[] mem; // �� �� ������ �迭�� �Ҵ�� �޸𸮸� ���� �� ����,
		mem = extend_mem; // ������ �迭�� Ȯ��� �迭�� �����Ų��.
	}
};

class MyQueue : protected BaseArray { // MyQueue : BaseArray�� ��ӹ޾Ƽ� Queue�� ���۽�Ų Ŭ����
private: // ���� ���� �ܺο��� ���� ������ �� ������ private ������ �Ѵ�.
	int rear; // ������ �߻��ϴ� ��ġ
	int front; // ������ �߻��ϴ� ��ġ
public: // Queue�� ��𿡼��� ����� �� �ֵ��� public ������ �Ѵ�.
	MyQueue(int capacity) : BaseArray(capacity) { // MyQueue ������. BaseArray�� �����ڵ� ���� ȣ����Ѽ� �迭�� �������ش�.
		rear = 0; // ���� ��ġ�� 0���� ����
		front = 0; // ���� ��ġ�� 0���� ����
	}

	void enqueue(int val) { // Queue�� ���� �ִ� �Լ�
		if (rear == getCapacity()) { // ���� ���� ��ġ�� Queue�� ũ��� ���ٸ�,
			cout << "Queue Full!!-- ť �뷮 �ø�!" << '\n'; // Queue�� �� �� ���� �ǹ��Ѵ�.
			doubleCapacity(); // �׷��Ƿ� Queue�� ũ�⸦ 2��� �ø���.
		}
		put(rear++, val); // Queue�� ���� �־��ְ�, ���� �����͸� ���� �غ� �ϱ� ���ؼ� rear�� 1 �ø���.
	}
	int dequeue() { // Queue���� ���� ���� �Լ�
		if (front == rear) { // ���� ���� ��ġ�� ���� ��ġ�� ���ٸ�,
			cout << "Queue Empty!!" << '\n'; // Queue�� �� ���� �ǹ��Ѵ�.
			return ERROR_VAL; // �׷ιǷ� ���� ���� ��ȯ���ش�.
		}
		return get(front++); // ���������� ���۽ÿ��� �� ���� ���� ��ȯ�ϰ�, ���� �����͸� �� �غ� �ϱ� ���ؼ� front�� 1 �ø���.
	}
	int capacity() { return getCapacity(); } // Queue�� �뷮(�ִ� ũ��)�� ��ȯ�ϴ� �Լ�
	int length() { return rear - front; } // Queue�� ��� �������� ������ ��ȯ�ϴ� �Լ�

};

class MyStack : protected BaseArray { // MyStack : BaseArray�� Stack���� ���۽�Ű�� ���� ����� Ŭ����
private: // ���� ���� �ܺο��� ���� ������ �� ������ private ������ �Ѵ�.
	int top; // ����, ������ �߻��ϴ� ��ġ
public: // Stack�� ��𿡼��� ����� �� �ֵ��� public ������ �Ѵ�.
	MyStack(int capacity) : BaseArray(capacity) { top = 0; } // MyStack ������. BaseArray�� �����ڵ� ���� ȣ����Ѽ� �迭�� �������ش�. ���� ��ġ(top)�� 0�̴�.

	void push(int val) { // Stack�� ���� �ִ� �Լ�
		if (top == getCapacity()) { // ���� top�� Stack�� ũ�Ⱑ ���ٸ�
			cout << "Stack Full!! -- ���� �뷮 �ø�!" << '\n'; // Stack�� �� á�ٴ� ���� �ǹ��Ѵ�.
			doubleCapacity(); // �׷��Ƿ� Stack�� ũ�⸦ 2��� �ø���.
		}
		put(top++, val); // Stack�� ���� �־��ְ�, ���� �����͸� ���� �غ� �ϱ� ���ؼ� top�� 1 �ø���.
	}
	int pop() { // Stack���� ���� ���� �Լ�
		if (top == 0) { // ���� top�� 0�̶��
			cout << "Stack Empty!!" << '\n'; // Stack�� ����ִٴ� ���� �ǹ�����.
			return ERROR_VAL; // �׷��Ƿ� �������� ��ȯ���ش�.
		}
		return get(--top); // ���������� ���۽ÿ��� Stack���� �� ���� �ִ� ���� ���ְ�, ���� �����͸� �� �غ� �ϱ� ���ؼ� top�� 1 ������.
	}
	int capacity() { return getCapacity(); } // Stack�� �뷮(�ִ� ũ��)�� ��ȯ�ϴ� �Լ�
	int length() { return top; } // Stack�� ��� �������� ������ ��ȯ�ϴ� �Լ�.
};

int main() {
	MyQueue mQ(3);
	MyStack mS(3);
	int n;
	cout << "5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
		mS.push(n);
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "������ �뷮:" << mS.capacity() << ", ������ ũ��:" << mS.length() << endl;
	cout << "ť�� ���Ҹ� 2�� �����Ͽ� ����Ѵ�>> ";
	cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	cout << endl;
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
		mS.push(n);
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl;
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "������ �뷮:" << mS.capacity() << ", ������ ũ��:" << mS.length() << endl;
	cout << "������ ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mS.length() != 0) {
		cout << mS.pop() << ' ';
	}
	cout << endl;
	cout << "������ �뷮:" << mS.capacity() << ", ������ ũ��:" << mS.length() << endl;
}