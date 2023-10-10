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
	/* 문제 (1.1.)
	main() 함수에서 무작위로 100,000개의 정수를 생성한 다음,
	int A[100000] 배열에 저장한 후, sort 함수 호출
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

	/* 문제 (1.2.)
	n의 크기를 100부터 1,000,000까지 바꾸면서 sort 함수의 실행 시간을 측정하여 관찰지에 기록
	*/
	//int N_SIZE[13] = { 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000 };
	//int n;
	//double duration;
	//clock_t start;

	//for (int i = 0; i < (sizeof(N_SIZE) / sizeof(int)); i++) {
	//	n = N_SIZE[i];

	//	int* B = (int*)malloc(sizeof(int) * n); // 동적 배열 B 생성
	//	// 역순 정렬된 배열
	//	for (int j = 0; j < n; j++)
	//		B[j] = n - j;

	//	start = clock();
	//	sort(B, n);
	//	duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

	//	printf("n = %7d, duration = %.3f\n", n, duration);
	//	free(B);
	//}

	//printf("\n");

	/* 문제 1.3.
	main() 함수에서 100,000개의 정수를 무작위로 생성하여 A 배열에 저장한 후, sort() 함수를 호출하여 오름차순으로 정렬한다.
	무작위 정수의 범위는 1 ~ 100000 이다.

	이후, binsearch(A, 검색 데이터) 함수를 호출하여 return된 곳에 검색 데이터가 존재하는지 확인한다.
	binsearch 함수에서 int 변수 counter를 0으로 초기화하고, while문을 돌 때마다 1씩 증가. return할 때, counter의 값이 얼마인지를 출력.
	*/
	//printf("problem 1.3.\n");

	//int A[MAX_SIZE];

	//srand(time(NULL));

	//for (int i = 0; i < MAX_SIZE; i++)
	//	A[i] = (largerRand() % RANDOM_RANGE) + 1;

	//sort(A, MAX_SIZE);
	//int answer = is_sorted(A, MAX_SIZE);
	//printf("정렬이 잘 되었는가? : %d (1 = true, 0 = false)\n\n", answer);

	//int targetIndex = largerRand() % MAX_SIZE;
	//int targetValue = A[targetIndex];
	//int resultIndex = binsearch(A, targetValue, 0, MAX_SIZE-1);

	//printf("target index = %d\n", targetIndex);
	//printf("binsearch result index = %d\n", resultIndex);
	//printf("참고 : 배열에 중복된 값이 있어서 결과가 +-3정도의 오차가 있을 수 있음.");

	/* 문제 1.4.
	배열의 크기를 변화시키면서 counter의 값을 관찰
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