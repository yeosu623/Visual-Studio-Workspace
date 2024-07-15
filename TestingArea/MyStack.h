#define ERROR_VAL -999
#include <iostream>
#include "BaseArray.h"
using namespace std;

class MyStack : protected BaseArray { // MyStack : BaseArray을 Stack으로 동작시키기 위해 상속한 클래스
private: // 설정 값은 외부에서 직접 조작할 수 없도록 private 선언을 한다.
	int top; // 삽입, 삭제가 발생하는 위치
public: // Stack은 어디에서나 사용할 수 있도록 public 선언을 한다.
	MyStack(int capacity);

	void push(int val);
	int pop();
	int capacity();
	int length();
};