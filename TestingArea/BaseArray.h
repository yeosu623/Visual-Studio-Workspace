#pragma once
#define ERROR_VAL -999
#include <iostream>
using namespace std;

class BaseArray { // �ܼ� �迭�� ��Ÿ���� BaseArray Ŭ����.
private: // ���� ���� �ܺο��� ���� ������ �� ������ private ������ �Ѵ�.
	int capacity; // �迭�� ũ��
	int* mem; // ���� �迭
protected: // �� �迭�� ���� ������� ����, �ٸ� ������ ����Ͽ� �ٸ��� ����ϵ��� protected ������ �Ѵ�.
	BaseArray(int capacity);
	~BaseArray();
	
	void put(int index, int val);
	int get(int index);
	int getCapacity();
	void doubleCapacity();
};