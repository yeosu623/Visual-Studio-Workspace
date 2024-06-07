#define ERROR_VAL -999 // 에러 반환값
#include <iostream> // 출력을 위한 헤더파일 인클루드 해주기
using namespace std; // "std" namespace 작성 생략

class BaseArray { // 단순 배열을 나타내는 BaseArray 클래스.
private: // 설정 값은 외부에서 직접 조작할 수 없도록 private 선언을 한다.
	int capacity; // 배열의 크기
	int* mem; // 실제 배열
protected: // 본 배열을 직접 사용하지 말고, 다른 곳에서 상속하여 다르게 사용하도록 protected 선언을 한다.
	BaseArray(int capacity = 100) { // BaseArray 생성자. 설정 값이 없으면 배열의 크기를 100으로 설정한다.
		this->capacity = capacity; // 배열의 크기 삽입
		mem = new int[capacity]; // 실제 배열에 메모리 할당
	}
	~BaseArray() { delete[] mem; } // BaseArray 소멸자. BaseArray 객체가 소멸될 때 자동으로 호출되며, 이 때 실제 배열에 할당된 메모리를 해제시킨다.

	void put(int index, int val) { mem[index] = val; } // put() : 배열에서 지정한 인덱스에 값을 넣는다.
	int get(int index) { return mem[index]; } // get() : 배열에서 지정한 인덱스에 값을 꺼낸다.
	int getCapacity() { return capacity; } // getCapacity() : 배열의 크기를 반환한다.
	void doubleCapacity() { // doubleCapacity() : 배열의 크기를 2배로 늘린다.
		capacity *= 2; // 배열의 크기를 2배로 설정한다.

		// 그 후 기존의 배열에서 확장된 배열로 값을 하나씩 옮겨주어야 한다.
		int* extend_mem = new int[capacity]; // 확장된 배열에 메모리를 선언해주고,
		for (int i = 0; i < capacity / 2; i++) // 기존의 배열에 있는 값을 확장된 배열에 하나씩 옮긴다.
			extend_mem[i] = mem[i];

		delete[] mem; // 그 후 기존의 배열에 할당된 메모리를 해제 한 다음,
		mem = extend_mem; // 기존의 배열은 확장된 배열에 연결시킨다.
	}
};

class MyQueue : protected BaseArray { // MyQueue : BaseArray를 상속받아서 Queue로 동작시킨 클래스
private: // 설정 값은 외부에서 직접 조작할 수 없도록 private 선언을 한다.
	int rear; // 삽입이 발생하는 위치
	int front; // 삭제가 발생하는 위치
public: // Queue는 어디에서나 사용할 수 있도록 public 선언을 한다.
	MyQueue(int capacity) : BaseArray(capacity) { // MyQueue 생성자. BaseArray의 생성자도 같이 호출시켜서 배열을 생성해준다.
		rear = 0; // 삽입 위치는 0에서 시작
		front = 0; // 삭제 위치는 0에서 시작
	}

	void enqueue(int val) { // Queue에 값을 넣는 함수
		if (rear == getCapacity()) { // 만약 삽입 위치와 Queue의 크기와 같다면,
			cout << "Queue Full!!-- 큐 용량 늘림!" << '\n'; // Queue가 꽉 찬 것을 의미한다.
			doubleCapacity(); // 그러므로 Queue의 크기를 2배로 늘린다.
		}
		put(rear++, val); // Queue에 값을 넣어주고, 다음 데이터를 받을 준비를 하기 위해서 rear를 1 올린다.
	}
	int dequeue() { // Queue에서 값을 빼는 함수
		if (front == rear) { // 만약 삽입 위치와 삭제 위치가 같다면,
			cout << "Queue Empty!!" << '\n'; // Queue가 빈 것을 의미한다.
			return ERROR_VAL; // 그로므로 에러 값을 반환해준다.
		}
		return get(front++); // 정상적으로 동작시에는 맨 앞의 값을 반환하고, 다음 데이터를 뺄 준비를 하기 위해서 front를 1 올린다.
	}
	int capacity() { return getCapacity(); } // Queue의 용량(최대 크기)를 반환하는 함수
	int length() { return rear - front; } // Queue에 담긴 데이터의 개수를 반환하는 함수

};

class MyStack : protected BaseArray { // MyStack : BaseArray을 Stack으로 동작시키기 위해 상속한 클래스
private: // 설정 값은 외부에서 직접 조작할 수 없도록 private 선언을 한다.
	int top; // 삽입, 삭제가 발생하는 위치
public: // Stack은 어디에서나 사용할 수 있도록 public 선언을 한다.
	MyStack(int capacity) : BaseArray(capacity) { top = 0; } // MyStack 생성자. BaseArray의 생성자도 같이 호출시켜서 배열을 생성해준다. 시작 위치(top)은 0이다.

	void push(int val) { // Stack에 값을 넣는 함수
		if (top == getCapacity()) { // 만약 top과 Stack의 크기가 같다면
			cout << "Stack Full!! -- 스택 용량 늘림!" << '\n'; // Stack이 꽉 찼다는 것을 의미한다.
			doubleCapacity(); // 그러므로 Stack의 크기를 2배로 늘린다.
		}
		put(top++, val); // Stack에 값을 넣어주고, 다음 데이터를 넣을 준비를 하기 위해서 top을 1 올린다.
	}
	int pop() { // Stack에서 값을 빼는 함수
		if (top == 0) { // 만약 top이 0이라면
			cout << "Stack Empty!!" << '\n'; // Stack이 비어있다는 것을 의미힌다.
			return ERROR_VAL; // 그러므로 에러값을 반환해준다.
		}
		return get(--top); // 정상적으로 동작시에는 Stack에서 맨 위에 있는 값을 빼주고, 다음 데이터를 뺄 준비를 하기 위해서 top을 1 내린다.
	}
	int capacity() { return getCapacity(); } // Stack의 용량(최대 크기)를 반환하는 함수
	int length() { return top; } // Stack에 담긴 데이터의 개수를 반환하는 함수.
};

int main() {
	MyQueue mQ(3);
	MyStack mS(3);
	int n;
	cout << "5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
		mS.push(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "스택의 용량:" << mS.capacity() << ", 스택의 크기:" << mS.length() << endl;
	cout << "큐의 원소를 2개 제거하여 출력한다>> ";
	cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	cout << endl;
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
		mS.push(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl;
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "스택의 용량:" << mS.capacity() << ", 스택의 크기:" << mS.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mS.length() != 0) {
		cout << mS.pop() << ' ';
	}
	cout << endl;
	cout << "스택의 용량:" << mS.capacity() << ", 스택의 크기:" << mS.length() << endl;
}