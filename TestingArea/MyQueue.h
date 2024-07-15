#define ERROR_VAL -999
#include <iostream>
#include "BaseArray.h"
using namespace std;

class MyQueue : protected BaseArray { // MyQueue : BaseArray�� ��ӹ޾Ƽ� Queue�� ���۽�Ų Ŭ����
private: // ���� ���� �ܺο��� ���� ������ �� ������ private ������ �Ѵ�.
	int rear; // ������ �߻��ϴ� ��ġ
	int front; // ������ �߻��ϴ� ��ġ
public: // Queue�� ��𿡼��� ����� �� �ֵ��� public ������ �Ѵ�.
	MyQueue(int capacity);

	void enqueue(int val);
	int dequeue();
	int capacity();
	int length();
};