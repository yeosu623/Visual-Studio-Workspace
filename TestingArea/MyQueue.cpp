#include "MyQueue.h"

MyQueue::MyQueue(int capacity) : BaseArray(capacity) { // MyQueue 생성자. BaseArray의 생성자도 같이 호출시켜서 배열을 생성해준다.
	rear = 0; // 삽입 위치는 0에서 시작
	front = 0; // 삭제 위치는 0에서 시작
}

void MyQueue::enqueue(int val) { // Queue에 값을 넣는 함수
	if (rear == getCapacity()) { // 만약 삽입 위치와 Queue의 크기와 같다면,
		cout << "Queue Full!!-- 큐 용량 늘림!" << '\n'; // Queue가 꽉 찬 것을 의미한다.
		doubleCapacity(); // 그러므로 Queue의 크기를 2배로 늘린다.
	}
	put(rear++, val); // Queue에 값을 넣어주고, 다음 데이터를 받을 준비를 하기 위해서 rear를 1 올린다.
}
int MyQueue::dequeue() { // Queue에서 값을 빼는 함수
	if (front == rear) { // 만약 삽입 위치와 삭제 위치가 같다면,
		cout << "Queue Empty!!" << '\n'; // Queue가 빈 것을 의미한다.
		return ERROR_VAL; // 그로므로 에러 값을 반환해준다.
	}
	return get(front++); // 정상적으로 동작시에는 맨 앞의 값을 반환하고, 다음 데이터를 뺄 준비를 하기 위해서 front를 1 올린다.
}
int MyQueue::capacity() { return getCapacity(); } // Queue의 용량(최대 크기)를 반환하는 함수
int MyQueue::length() { return rear - front; } // Queue에 담긴 데이터의 개수를 반환하는 함수
