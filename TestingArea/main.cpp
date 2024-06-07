//#include <iostream>
//using namespace std;
//
//class BaseArray {
//private:
//	int capacity;
//	int* mem;
//protected:
//	BaseArray(int capacity = 100) {
//		this->capacity = capacity;
//		mem = new int[capacity];
//	}
//	~BaseArray() { delete[] mem; }
//
//	void put(int index, int val) { mem[index] = val; }
//	int get(int index) { return mem[index]; }
//	int getCapacity() {	return capacity; }
//};
//
//class MyQueue : protected BaseArray {
//private:
//	int rear; // ������ �߻��ϴ� ��ġ
//	int front; // ������ �߻��ϴ� ��ġ
//public:
//	MyQueue(int capacity) : BaseArray(capacity) { 
//		rear = 0;
//		front = 0;
//	}
//
//	void enqueue(int val) { put(rear++, val); }
//	int dequeue() { return get(front++); }
//	int capacity() { return getCapacity(); }
//	int length() { return rear - front; }
//
//};
//
//class MyStack : protected BaseArray {
//private:
//	int top; // ����, ������ �߻��ϴ� ��ġ
//public:
//	MyStack(int capacity) : BaseArray(capacity) { top = 0; }
//
//	void push(int val) { put(top++, val); }
//	int pop() { return get(--top); }
//	int capacity() { return getCapacity(); }
//	int length() { return top; }
//};
//
//int main() {
//	MyQueue mQ(3);
//	MyStack mS(3);
//	int n;
//	cout << "5���� ������ �Է��϶�>> ";
//	for (int i = 0; i < 5; i++) {
//		cin >> n;
//		mQ.enqueue(n); // ť�� ����
//		mS.push(n);
//	}
//	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
//	cout << "������ �뷮:" << mS.capacity() << ", ������ ũ��:" << mS.length() << endl;
//	cout << "ť�� ���Ҹ� 2�� �����Ͽ� ����Ѵ�>> ";
//	cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
//	cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
//	cout << endl;
//	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
//	cout << "5���� ������ �Է��϶�>> ";
//	for (int i = 0; i < 5; i++) {
//		cin >> n;
//		mQ.enqueue(n); // ť�� ����
//		mS.push(n);
//	}
//	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
//	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
//	while (mQ.length() != 0) {
//		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
//	}
//	cout << endl;
//	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
//	cout << "������ �뷮:" << mS.capacity() << ", ������ ũ��:" << mS.length() << endl;
//	cout << "������ ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
//	while (mS.length() != 0) {
//		cout << mS.pop() << ' ';
//	}
//	cout << endl;
//	cout << "������ �뷮:" << mS.capacity() << ", ������ ũ��:" << mS.length() << endl;
//}