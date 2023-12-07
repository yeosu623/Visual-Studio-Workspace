#include <stdio.h>
#include <stdlib.h>
int duplicateRemove(int*, int*);

int main() {
	int answer[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int question[10] = { 6,7,8,6,4,5,8,9,3,1 };
	int count = duplicateRemove(question, answer);

	for (int i = 0; i < 10; i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
	printf("count = %d", count);
}

int duplicateRemove(int* question, int* answer) {
	int count = 0;
	int value;
	int flag = 0;

	for (int i = 0; i < 10; i++) {
		value = question[i];

		for (int j = 0; j < 10; j++) {
			if (value == answer[j]) flag = 1;
		}
		if (flag == 1);
		else if (flag == 0) answer[count++] = value;

		flag = 0;
	}

	return count;
} 