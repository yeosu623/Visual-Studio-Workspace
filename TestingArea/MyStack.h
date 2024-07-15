#define ERROR_VAL -999
#include <iostream>
#include "BaseArray.h"
using namespace std;

class MyStack : protected BaseArray { // MyStack : BaseArray�� Stack���� ���۽�Ű�� ���� ����� Ŭ����
private: // ���� ���� �ܺο��� ���� ������ �� ������ private ������ �Ѵ�.
	int top; // ����, ������ �߻��ϴ� ��ġ
public: // Stack�� ��𿡼��� ����� �� �ֵ��� public ������ �Ѵ�.
	MyStack(int capacity);

	void push(int val);
	int pop();
	int capacity();
	int length();
};