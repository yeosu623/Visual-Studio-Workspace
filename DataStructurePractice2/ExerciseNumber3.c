//#include <stdio.h>
//#include <stdlib.h>
//
//void perm(int* list, int i, int n)
//{/* input only 0 in list*/
//	int j;
//	if (i == (n + 1)) {
//		printf("<");
//		for (j = 0; j <= n; j++) {
//			if (list[j] == 0)
//				printf("false");
//			else
//				printf("true");
//
//			if (j != n)
//				printf(",");
//		}
//		printf(">\n");
//	}
//	else {
//		for (j = 0; j <= 1; j++) {
//			if (j == 0) {
//				list[i] = 1;
//				perm(list, i + 1, n);
//			}
//			else {
//				list[i] = 0;
//				perm(list, i + 1, n);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	printf("input size of array : ");
//	scanf_s("%d", &n);
//
//	int* A = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//		A[i] = 0;
//
//	perm(A, 0, n - 1);
//}