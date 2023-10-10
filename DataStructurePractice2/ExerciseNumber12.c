#include <stdio.h>
#include <stdlib.h>

void perm(char* list, int i, int n, int formerIndex, char* memory)
{
	// ���� �Լ� ����ÿ��� ����
	if (formerIndex == -1)
		printf("{} ");

	int j, k;
	for (j = i; j <= n; j++) {
		if (formerIndex < j) { // ����� ���ں��� ���� ���ڸ� ���� �Ѵ�.
			printf("{");
			for (k = 0; k <= n; k++) { // �ռ� ����� ���ڸ� ��������ش�.
				if (memory[k] != 0)
					printf("%c,", memory[k]);
			}
			
			printf("%c} ", list[j]); // ���� ���ڸ� ����Ѵ�.
			memory[j] = list[j]; // ����� ���ڸ� ���� ���տ� �߰��ϱ� ���ؼ� ���� �������ش�.

			perm(list, i + 1, n, j, memory);
			memory[j] = 0; // ������ ������ ����� ��, ���������� �����ߴ� ���� �ϳ��� �����ش�.
		}
	}
}

#define MAX_SIZE 5

int main()
{
	char charList[MAX_SIZE] = {'a','b','c','d','e'};
	char memory[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		memory[i] = 0;

	perm(charList, 0, MAX_SIZE-1, -1, memory);
}