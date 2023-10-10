#include <stdio.h>
#include <stdlib.h>

void perm(char* list, int i, int n, int formerIndex, char* memory)
{
	// 최초 함수 시행시에만 동작
	if (formerIndex == -1)
		printf("{} ");

	int j, k;
	for (j = i; j <= n; j++) {
		if (formerIndex < j) { // 출력한 문자보다 뒤의 문자만 오게 한다.
			printf("{");
			for (k = 0; k <= n; k++) { // 앞서 출력한 문자를 재출력해준다.
				if (memory[k] != 0)
					printf("%c,", memory[k]);
			}
			
			printf("%c} ", list[j]); // 현재 문자를 출력한다.
			memory[j] = list[j]; // 출력한 문자를 뒤의 집합에 추가하기 위해서 값을 저장해준다.

			perm(list, i + 1, n, j, memory);
			memory[j] = 0; // 집합을 끝까지 출력한 후, 끝에서부터 저장했던 값을 하나씩 지워준다.
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