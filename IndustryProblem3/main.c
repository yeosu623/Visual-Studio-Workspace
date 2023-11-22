#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int printed_line = 0;
CONSOLE_SCREEN_BUFFER_INFO csbi;

void error_print(char*);
int diff(int);
void googoo(int, int, int); // start, end, limit를 받아서 이번에 출력할 start, end를 만들어내는 함수
void googoo_print(int, int); // 이번에 출력할 start, end를 받아서 구구단을 출력하는 함수.
void handle_terminal(); // 터미널 상태를 확인한 후, 공간이 있으면 줄바꿈을 하고 공간이 없으면 터미널 초기화를 하는 함수.

int main(int argc, char* argv[])
{
	int i, ch, temp[3];
	if (argc != 4)
	{
		printf("사용법 : %s [시작 단] [끝 단] [출력라인수]\n", argv[0]);
		printf("주의 : - 시작, 끝 단, 출력라인수는 1~99까지의 숫자만 넣으세요\n");
		printf("       - 시작 단이 끝 단 보다 크면 안됩니다\n");
		printf("예) %s 3 90 4\n", argv[0]);
		exit(1);
	}
	for (i = 1; i < 3; i++) //시작, 끝단의 제한 
	{
		ch = atoi(argv[i]);
		temp[i] = ch;
		if (diff(ch) == 0) // limit, start, end가 1~99 사이의 숫자인가를 묻는다.
			error_print("1 ~ 99까지의 숫자만 넣으세요");
	}
	if (temp[1] > temp[2]) //시작 단이 끝 단 보다 크지 않도록 제한. start > end
		error_print("시작 단이 끝 단 보다 크면 안됩니다");
	temp[0] = atoi(argv[3]);
	if (diff(temp[0]) == 0) //컬럼의 제한. diff(limit) == 0. limit가 1~99 사이의 숫자인가를 묻는다.
		error_print("1~99까지의 숫자만 넣으세요");
	googoo(temp[1], temp[2], temp[0]); //구구단. start, end, limit 매개변수 순.
	return 0;
}

void error_print(char* msg) {
	printf("%s\n", msg);
	exit(1);
}

int diff(int cmp) {
	if (1 <= cmp && cmp <= 99) return 1;
	else return 0;
}

void googoo(int start, int end, int limit) {
	int limit_remain = limit;

	while (start <= end) {
		if (limit_remain > 4) {
			if (start + 4 > end) { googoo_print(start, end + 1); break; } // 출력할 범위가 넘어갈 경우, end까지만 출력하고 종료
			googoo_print(start, start + 4);
			start += 4;

			limit_remain -= 4;
		}
		else {
			if (start + limit_remain > end) { googoo_print(start, end + 1); break; } // 출력할 범위가 넘어갈 경우, end까지만 출력하고 종료
			googoo_print(start, start + limit_remain);
			start += limit_remain;

			limit_remain = limit;
		}
	}
}

void googoo_print(int print_start, int print_end) {
	int cleared = 0;

	for (int i = 1; i <= 9; i++) {
		for (int j = print_start; j < print_end; j++) {
			printf("%d * %d = %-7d", j, i, j * i);
		}
		handle_terminal();
	}
	handle_terminal();
}

void handle_terminal() {
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int windowRowSize = csbi.srWindow.Bottom - csbi.srWindow.Top - 1;

	if (printed_line < windowRowSize) {
		printf("\n");
		printed_line++;
	}
	else {
		printf("press any key");
		getch();

		system("cls");
		printed_line = 0;
	}
}