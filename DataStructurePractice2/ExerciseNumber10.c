//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//
//uint64_t A(int m, int n) {
//	if (m == 0)
//		return n + 1;
//	else if (n == 0)
//		A(m - 1, 1);
//	else
//		A(m - 1, A(m, n - 1));
//}
//
//int main() {
//	int m, n;
//	uint64_t result;
//	printf("This problem output Ackerman's function based on m, n values.\n");
//	printf("Write m : ");
//	scanf_s("%d", &m);
//	printf("Write n : ");
//	scanf_s("%d", &n);
//
//	result = A(m, n);
//	printf("result : %llu\n", result);
//}