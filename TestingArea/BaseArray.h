#pragma once
#define ERROR_VAL -999
#include <iostream>
using namespace std;

class BaseArray { // 단순 배열을 나타내는 BaseArray 클래스.
private: // 설정 값은 외부에서 직접 조작할 수 없도록 private 선언을 한다.
	int capacity; // 배열의 크기
	int* mem; // 실제 배열
protected: // 본 배열을 직접 사용하지 말고, 다른 곳에서 상속하여 다르게 사용하도록 protected 선언을 한다.
	BaseArray(int capacity);
	~BaseArray();
	
	void put(int index, int val);
	int get(int index);
	int getCapacity();
	void doubleCapacity();
};