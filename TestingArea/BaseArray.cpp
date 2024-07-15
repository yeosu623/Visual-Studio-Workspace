#include "BaseArray.h"

BaseArray::BaseArray(int capacity = 100) { // BaseArray ������. ���� ���� ������ �迭�� ũ�⸦ 100���� �����Ѵ�.
	this->capacity = capacity; // �迭�� ũ�� ����
	mem = new int[capacity]; // ���� �迭�� �޸� �Ҵ�
}
BaseArray::~BaseArray() { delete[] mem; } // BaseArray �Ҹ���. BaseArray ��ü�� �Ҹ�� �� �ڵ����� ȣ��Ǹ�, �� �� ���� �迭�� �Ҵ�� �޸𸮸� ������Ų��.

void BaseArray::put(int index, int val) { mem[index] = val; } // put() : �迭���� ������ �ε����� ���� �ִ´�.
int BaseArray::get(int index) { return mem[index]; } // get() : �迭���� ������ �ε����� ���� ������.
int BaseArray::getCapacity() { return capacity; } // getCapacity() : �迭�� ũ�⸦ ��ȯ�Ѵ�.
void BaseArray::doubleCapacity() { // doubleCapacity() : �迭�� ũ�⸦ 2��� �ø���.
	capacity *= 2; // �迭�� ũ�⸦ 2��� �����Ѵ�.

	// �� �� ������ �迭���� Ȯ��� �迭�� ���� �ϳ��� �Ű��־�� �Ѵ�.
	int* extend_mem = new int[capacity]; // Ȯ��� �迭�� �޸𸮸� �������ְ�,
	for (int i = 0; i < capacity / 2; i++) // ������ �迭�� �ִ� ���� Ȯ��� �迭�� �ϳ��� �ű��.
		extend_mem[i] = mem[i];

	delete[] mem; // �� �� ������ �迭�� �Ҵ�� �޸𸮸� ���� �� ����,
	mem = extend_mem; // ������ �迭�� Ȯ��� �迭�� �����Ų��.
}