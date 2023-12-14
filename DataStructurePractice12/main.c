#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define RANDOM 0
#define ASCENDING 1
#define DESCENDING 2
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert_data(float* arr, int n, int tag);
int is_sorted(float* arr, int n);
void selection_sort(float* arr, int n);
void insertion_sort(float* arr, int n);
void quick_sort(float* arr, int left, int right);
void print_12(int tag);

int main() {
	printf("12.1. 랜덤 생성 데이터의 정렬\n");
	print_12(RANDOM);

	printf("12.2. 정렬된 데이터의 정렬\n");
	printf("12.2.1. 오름차순 정렬된 데이터의 정렬\n");
	print_12(ASCENDING);

	printf("12.2.2. 내림차순 정렬된 데이터의 정렬\n");
	print_12(DESCENDING);
}

void insert_data(float* arr, int n, int tag) {
	for (int i = 0; i < n; i++)
		arr[i] = (rand() / (0x7fff * 1.0)) * 100000000;

	switch (tag) {
	case RANDOM: break; // 문제 12.1 랜덤 생성 데이터
	case ASCENDING: quick_sort(arr, 0, n - 1); break; // 문제 12.2.1. 오름차순 정렬된 데이터
	case DESCENDING: quick_sort(arr, 0, n - 1); // 문제 12.2.2. 내림차순 정렬된 데이터
		float* temp = (float*)malloc(sizeof(float) * n);
		for (int i = 0; i < n; i++)
			temp[i] = arr[n - i - 1];

		memcpy(arr, temp, sizeof(float) * n);
		free(temp);
	}
}

int is_sorted(float* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if ( !(arr[i] <= arr[i + 1]) )
			return FALSE;
	}
	return TRUE;
}

void selection_sort(float* arr, int n) {

	int i, j;
	int minValue;
	float temp;

	for (i = 0; i < n - 1; i++) {
		minValue = i;

		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minValue])
				minValue = j;

		SWAP(arr[i], arr[minValue], temp);
	}
}

void insertion_sort(float* arr, int n) {

	int i, j;
	float next;
	for (i = 1; i < n; i++) {
		next = arr[i];

		for (j = i - 1; j >= 0 && next < arr[j]; j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = next;
	}
}

// 출처 : https://code-lab1.tistory.com/23
void quick_sort(float* arr, int L, int R) {
	int left = L, right = R;
	float pivot = arr[(L + R) / 2];
	float temp;

	do {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			left++;
			right--;
		}
	} while (left <= right);

	if (L < right) quick_sort(arr, L, right);
	if (left < R) quick_sort(arr, left, R);
}

void print_12(int tag) {
	float* A, * B; // 데이터가 들어갈 배열
	clock_t start, stop;
	double duration;

	for (int n = 1000; n <= 1000000; n *= 10) {

		// 원소 수(n) 출력
		printf("  원소 수 : %d\n", n);

		// 배열 A, B 준비
		A = (float*)malloc(sizeof(float) * n);
		B = (float*)malloc(sizeof(float) * n);
		insert_data(A, n, tag);

		// 배열 B를 정렬하고 시간을 출력하는 부분
		for (int select = 0; select < 3; select++) {

			// A->B 내용 복사
			memcpy(B, A, sizeof(float) * n);

			// 시간 측정
			start = clock();
			switch (select) {
			case 0: selection_sort(B, n); break;
			case 1: insertion_sort(B, n); break;
			case 2: quick_sort(B, 0, n - 1);
			}
			stop = clock();
			duration = ((double)(stop - start)) / CLOCKS_PER_SEC;

			// 시간 출력
			if (is_sorted(B, n)) {
				switch (select) {
				case 0: printf("  selection sort time: %.6f\n", duration); break;
				case 1: printf("  insertion sort time: %.6f\n", duration); break;
				case 2: printf("      quick sort time: %.6f\n", duration);
				}
			}
			else {
				printf("ERROR : Array B is not sorted.\n");
				exit(1);
			}
		}
		printf("\n");

		// 메모리 할당 해제
		free(A);
		free(B);
	}
}