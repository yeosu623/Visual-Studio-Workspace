//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
//
//void perm(int* list, int i, int n)
//{/* generate all the permutations of list[i] to list[n] */
//	int j, temp;
//	if (i == n) {
//		for (j = 0; j <= n; j++)
//			printf("%d", list[j]);
//		printf(" ");
//	}
//	else {
//	/* list[i] to list[n] has more than one permutation,
//	   generate these recursively */
//		for (j = i; j <= n; j++) {
//			SWAP(list[i], list[j], temp);
//			perm(list, i + 1, n);
//			SWAP(list[i], list[j], temp);
//		}
//	}
//}
//
//int main()
//{
//	/* ���� 2.1. */
//	//char A[][10] = { "GO", "BOY", "GIRL", "GIRLS" };
//
//	//perm(A[0], 0, 1);
//	//printf("\n");
//	//perm(A[1], 0, 2);
//	//printf("\n");
//	//perm(A[2], 0, 3);
//	//printf("\n");
//	//perm(A[3], 0, 4);
//	//printf("\n\n");
//
//	/* ���� 2.2. */
//	int n;
//	double duration;
//	clock_t start;
//
//	// �迭 ����. ex) B[3] = {1,2,3};
//	printf("�Է� : ");
//	scanf_s("%d", &n);
//	int* B = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//		B[i] = i + 1;
//
//	// �迭�� ������ ������ ���� ���
//	printf("���\n");
//	printf("���� : ");
//
//	start = clock();
//	perm(B, 0, n - 1);
//	duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
//
//	printf("\n");
//	printf("���� �ð� : %.3f ��\n\n", duration);
//}