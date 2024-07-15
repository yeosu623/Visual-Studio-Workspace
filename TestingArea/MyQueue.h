#define ERROR_VAL -999
#include <iostream>
#include "BaseArray.h"
using namespace std;

class MyQueue : protected BaseArray { // MyQueue : BaseArray를 상속받아서 Queue로 동작시킨 클래스
private: // 설정 값은 외부에서 직접 조작할 수 없도록 private 선언을 한다.
	int rear; // 삽입이 발생하는 위치
	int front; // 삭제가 발생하는 위치
public: // Queue는 어디에서나 사용할 수 있도록 public 선언을 한다.
	MyQueue(int capacity);

	void enqueue(int val);
	int dequeue();
	int capacity();
	int length();
};