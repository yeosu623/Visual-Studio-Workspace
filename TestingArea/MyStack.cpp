#include "MyStack.h"

MyStack::MyStack(int capacity) : BaseArray(capacity) { top = 0; } // MyStack 생성자. BaseArray의 생성자도 같이 호출시켜서 배열을 생성해준다. 시작 위치(top)은 0이다.

void MyStack::push(int val) { // Stack에 값을 넣는 함수
	if (top == getCapacity()) { // 만약 top과 Stack의 크기가 같다면
		cout << "Stack Full!! -- 스택 용량 늘림!" << '\n'; // Stack이 꽉 찼다는 것을 의미한다.
		doubleCapacity(); // 그러므로 Stack의 크기를 2배로 늘린다.
	}
	put(top++, val); // Stack에 값을 넣어주고, 다음 데이터를 넣을 준비를 하기 위해서 top을 1 올린다.
}
int MyStack::pop() { // Stack에서 값을 빼는 함수
	if (top == 0) { // 만약 top이 0이라면
		cout << "Stack Empty!!" << '\n'; // Stack이 비어있다는 것을 의미힌다.
		return ERROR_VAL; // 그러므로 에러값을 반환해준다.
	}
	return get(--top); // 정상적으로 동작시에는 Stack에서 맨 위에 있는 값을 빼주고, 다음 데이터를 뺄 준비를 하기 위해서 top을 1 내린다.
}
int MyStack::capacity() { return getCapacity(); } // Stack의 용량(최대 크기)를 반환하는 함수
int MyStack::length() { return top; } // Stack에 담긴 데이터의 개수를 반환하는 함수.