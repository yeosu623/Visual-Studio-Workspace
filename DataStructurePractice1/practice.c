#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_SIZE 100000
#define RANDOM_RANGE 100000

void swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void sort(int list[], int n) {
	// Bubble sort
	int i, j;
	for (i = 0; i < n - 1; i++) { // i index means the base index.
		for (j = i + 1; j < n; j++) { // j index means the comparion index.
			if (list[i] > list[j]) // ascending order
				swap(&list[i], &list[j]);
		}
	}
}

int is_sorted(int A[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (A[i] <= A[i + 1])
			continue;
		else {
			return 0;
		}
	}

	return 1;
}

int largerRand() {
	/* The random values range is 0 ~ 1,073,741,823 
	
		This method is referenced by stack overflow.
		link : https://stackoverflow.com/questions/9775313/extend-rand-max-range
	*/
	int a = rand();
	int b = rand();
	return a * (RAND_MAX + 1) + b;
}

int compare(int x, int y) {
	/* compare x and y, return -1 for less than, 0 for equal, 1 for greater*/
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int binsearch(int list[], int searchnum, int left, int right)
{/* serach list[0] <= list[1] <= ... <= list[n-1] for searchnum.
    Return its position if found. Otherwise return -1
	*/
	int middle;
	int counter = 0;

	while (left <= right) {
		counter++;

		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum)) {
			case -1: left = middle + 1;
					 break;
			case 0: printf("counter : %d\n", counter);
					return middle;
			case 1: right = middle - 1;
		}
	}
	printf("counter : %d\n", counter);
	return -1; // cannot found
}

int main() {
	/* ���� (1.1.)
	main() �Լ����� �������� 100,000���� ������ ������ ����,
	int A[100000] �迭�� ������ ��, sort �Լ� ȣ��
	*/
	//printf("Problem 1.1. \n");

	//int A[MAX_SIZE];

	//srand(time(NULL));

	//for (int i = 0; i < MAX_SIZE; i++)
	//	A[i] = (largerRand() % MAX_SIZE) + 1;

	//sort(A, MAX_SIZE);
	//int answer = is_sorted(A, MAX_SIZE);
	//
	//printf("The first six values of array : %d %d %d %d %d %d\n", A[0], A[1], A[2], A[3], A[4], A[5]);
	//printf("The final six values of array : %d %d %d %d %d %d\n", A[MAX_SIZE - 6], A[MAX_SIZE - 5], A[MAX_SIZE - 4], A[MAX_SIZE - 3], A[MAX_SIZE - 2], A[MAX_SIZE - 1]);
	//printf("Is it sorted? Answer : %d (1 = true, 0 = false)\n\n", answer);

	/* ���� (1.2.)
	n�� ũ�⸦ 100���� 1,000,000���� �ٲٸ鼭 sort �Լ��� ���� �ð��� �����Ͽ� �������� ���
	*/
	//int N_SIZE[13] = { 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000 };
	//int n;
	//double duration;
	//clock_t start;

	//for (int i = 0; i < (sizeof(N_SIZE) / sizeof(int)); i++) {
	//	n = N_SIZE[i];

	//	int* B = (int*)malloc(sizeof(int) * n); // ���� �迭 B ����
	//	// ���� ���ĵ� �迭
	//	for (int j = 0; j < n; j++)
	//		B[j] = n - j;

	//	start = clock();
	//	sort(B, n);
	//	duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

	//	printf("n = %7d, duration = %.3f\n", n, duration);
	//	free(B);
	//}

	//printf("\n");

	/* ���� 1.3.
	main() �Լ����� 100,000���� ������ �������� �����Ͽ� A �迭�� ������ ��, sort() �Լ��� ȣ���Ͽ� ������������ �����Ѵ�.
	������ ������ ������ 1 ~ 100000 �̴�.

	����, binsearch(A, �˻� ������) �Լ��� ȣ���Ͽ� return�� ���� �˻� �����Ͱ� �����ϴ��� Ȯ���Ѵ�.
	binsearch �Լ����� int ���� counter�� 0���� �ʱ�ȭ�ϰ�, while���� �� ������ 1�� ����. return�� ��, counter�� ���� �������� ���.
	*/
	//printf("problem 1.3.\n");

	//int A[MAX_SIZE];

	//srand(time(NULL));

	//for (int i = 0; i < MAX_SIZE; i++)
	//	A[i] = (largerRand() % RANDOM_RANGE) + 1;

	//sort(A, MAX_SIZE);
	//int answer = is_sorted(A, MAX_SIZE);
	//printf("������ �� �Ǿ��°�? : %d (1 = true, 0 = false)\n\n", answer);

	//int targetIndex = largerRand() % MAX_SIZE;
	//int targetValue = A[targetIndex];
	//int resultIndex = binsearch(A, targetValue, 0, MAX_SIZE-1);

	//printf("target index = %d\n", targetIndex);
	//printf("binsearch result index = %d\n", resultIndex);
	//printf("���� : �迭�� �ߺ��� ���� �־ ����� +-3������ ������ ���� �� ����.");

	/* ���� 1.4.
	�迭�� ũ�⸦ ��ȭ��Ű�鼭 counter�� ���� ����
	*/

	int N_SIZE[20] = { 50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000, 550000, 600000, 650000, 700000, 750000, 800000, 850000, 900000, 950000, 1000000 };
	int n;
	int* C; // Dynamic array

	for (int i = 0; i < 20; i++) {
		n = N_SIZE[i];
		printf("n = %d\n", n);

		C = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			C[j] = n - j;

		sort(C, n);
		int isSorted = is_sorted(C, n);
		if (isSorted == 1)
			printf("sorted : true\n");
		else
			printf("sorted : false\n");

		int targetIndex = largerRand() % n;
		int targetValue = C[targetIndex];
		int resultIndex = binsearch(C, targetValue, 0, n - 1);

		printf("targetIndex = %d\n", targetIndex);
		printf("resultIndex = %d\n", resultIndex);
		if (targetIndex == resultIndex)
			printf("binsearch worked good.\n");
		else
			printf("binsearch worked bad.\n");
		printf("------------------------\n");
	}
}