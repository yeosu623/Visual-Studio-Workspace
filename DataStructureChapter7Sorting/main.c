#include <stdio.h>
#include <stdlib.h>

/* ������ ���� ���� ������ �ð� ���⵵�� �ľ��ص� ��. (Page 7.37)
��� : Selection Sort, Insertion Sort, Quick Sort, Merge Sort, Heap Sort
*/
void insertion_sort(int list[], int n) {
	int i, j;
	int next;

	for (i = 1; i < n; i++) {
		next = list[i];
		
		for (j = i - 1; j >= 0 && next < list[j]; j--)
			list[j + 1] = list[j];

		list[j + 1] = next;
	}
}

// ���� : quicksort�� stable ���� �ʴ�.
// ���� : 56612 32821
// -----> 21212 35866
// �ذ� : �ߺ��� ���� quicksort�� ��쿡��, pivot = median(left, (left + right) / 2, right)
void quicksort(int list[], int left, int right) {
	int pivot, i, j;
	int temp;

	if (left < right) {
		i = left;
		j = right + 1;
		pivot = list[left];

		do {
			do i++; while (list[i] < pivot);
			do j--; while (list[j] > pivot);
			if (i < j) SWAP(list[i], list[j], temp);
		} while (i < j);

		SWAP(list[left], list[j], temp);
		quicksort(list, left, j - 1);
		quicksort(list, j + 1, right);
	}
}

// ���ĵ� �ΰ��� ����Ʈ�� �պ�
void merge(int list[], int sorted[], int i, int m, int n) {
	int j = m + 1; // i : ù ��° ����Ʈ ����, j = �� ���� ����Ʈ ����
	int k = i; // k : sorted[]�� ����

	while (i <= m && j <= n) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}

	if (i > m)
		for (; j <= n; j++)
			sorted[k++] = list[j];
	else
		for (; i <= m; i++)
			sorted[k++] = list[i];
}

// Merge sort(Iterative)
#define MAX_SIZE 1000

void merge_pass(int list[], int sorted[], int n, int length) {
	int i, j;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
		merge(list, sorted, i, i + length - 1, i + 2 * length - 1);

	if (i + length < n)
		merge(list, sorted, i, i + length - 1, n - 1);
	else
		for (j = i; j < n; j++)
			sorted[j] = list[j];
}

void merge_sort(int list[], int n) {
	int length = 1;
	int extra[MAX_SIZE];

	while (length < n) {
		merge_pass(list, extra, n, length);
		length *= 2;
		merge_pass(extra, list, n, length);
		length *= 2;
	}
}

// heap sort
void adjust(int list[], int root, int n) {
	int rootkey = list[root];
	int child = 2 * root;

	while (child <= n) {
		if ((child < n) && (list[child] < list[child + 1]))
			child++;
		if (rootkey > list[child]) break;
		else {
			list[child / 2] = list[child];
			child *= 2;
		}
	}
	list[child / 2] = rootkey;
}

void heapsort(int list[], int n) {
	int i, j;
	int temp;

	for (i = n / 2; i > 0; i--)
		adjust(list, i, n);
	for (i = n - 1; i > 0; i--) {
		SWAP(list[1], list[i + 1], temp);
		adjust(list, 1, i);
	}
}