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
void quick_sort(float* arr, int left, int right);

int main() {
	int count = 0;
	int n = 10000;
	while (1) {
		float* arr = (float*)malloc(sizeof(float) * n);

		insert_data(arr, n, ASCENDING);
		quick_sort(arr, 0, n - 1);

		if (is_sorted(arr, n)) printf("quick sorted %d\n", count++);
		else exit(1);

		free(arr);
	}
}

void insert_data(float* arr, int n, int tag) {
	int i;
	for (i = 0; i < n; i++)
		arr[i] = (rand() / (0x7fff * 1.0)) * 100000000;

	quick_sort(arr, 0, n - 1);
}

int is_sorted(float* arr, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (!(arr[i] <= arr[i + 1]))
			return FALSE;
	}
	return TRUE;
}
 
// ÃâÃ³ : https://code-lab1.tistory.com/23
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