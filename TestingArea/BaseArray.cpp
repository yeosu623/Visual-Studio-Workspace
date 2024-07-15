#include "BaseArray.h"

BaseArray::BaseArray(int capacity = 100) { // BaseArray 생성자. 설정 값이 없으면 배열의 크기를 100으로 설정한다.
	this->capacity = capacity; // 배열의 크기 삽입
	mem = new int[capacity]; // 실제 배열에 메모리 할당
}
BaseArray::~BaseArray() { delete[] mem; } // BaseArray 소멸자. BaseArray 객체가 소멸될 때 자동으로 호출되며, 이 때 실제 배열에 할당된 메모리를 해제시킨다.

void BaseArray::put(int index, int val) { mem[index] = val; } // put() : 배열에서 지정한 인덱스에 값을 넣는다.
int BaseArray::get(int index) { return mem[index]; } // get() : 배열에서 지정한 인덱스에 값을 꺼낸다.
int BaseArray::getCapacity() { return capacity; } // getCapacity() : 배열의 크기를 반환한다.
void BaseArray::doubleCapacity() { // doubleCapacity() : 배열의 크기를 2배로 늘린다.
	capacity *= 2; // 배열의 크기를 2배로 설정한다.

	// 그 후 기존의 배열에서 확장된 배열로 값을 하나씩 옮겨주어야 한다.
	int* extend_mem = new int[capacity]; // 확장된 배열에 메모리를 선언해주고,
	for (int i = 0; i < capacity / 2; i++) // 기존의 배열에 있는 값을 확장된 배열에 하나씩 옮긴다.
		extend_mem[i] = mem[i];

	delete[] mem; // 그 후 기존의 배열에 할당된 메모리를 해제 한 다음,
	mem = extend_mem; // 기존의 배열은 확장된 배열에 연결시킨다.
}