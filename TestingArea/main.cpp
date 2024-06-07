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
//	int rear; // 삽입이 발생하는 위치
//	int front; // 삭제가 발생하는 위치
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
//	int top; // 삽입, 삭제가 발생하는 위치
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
//	cout << "5개의 정수를 입력하라>> ";
//	for (int i = 0; i < 5; i++) {
//		cin >> n;
//		mQ.enqueue(n); // 큐에 삽입
//		mS.push(n);
//	}
//	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
//	cout << "스택의 용량:" << mS.capacity() << ", 스택의 크기:" << mS.length() << endl;
//	cout << "큐의 원소를 2개 제거하여 출력한다>> ";
//	cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
//	cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
//	cout << endl;
//	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
//	cout << "5개의 정수를 입력하라>> ";
//	for (int i = 0; i < 5; i++) {
//		cin >> n;
//		mQ.enqueue(n); // 큐에 삽입
//		mS.push(n);
//	}
//	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
//	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
//	while (mQ.length() != 0) {
//		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
//	}
//	cout << endl;
//	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
//	cout << "스택의 용량:" << mS.capacity() << ", 스택의 크기:" << mS.length() << endl;
//	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
//	while (mS.length() != 0) {
//		cout << mS.pop() << ' ';
//	}
//	cout << endl;
//	cout << "스택의 용량:" << mS.capacity() << ", 스택의 크기:" << mS.length() << endl;
//}