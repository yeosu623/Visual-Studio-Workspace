//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//int googoo_printed = 0;
//int rows_window;
//int rows_print = 0;
//CONSOLE_SCREEN_BUFFER_INFO csbi;
//
//void error_print(char*);
//int diff(int);
//void googoo(int, int, int);
//void check_terminal_window_is_full();
//void println();
//
//int main(int argc, char* argv[])
//{
//	int i, ch, temp[3];
//	if (argc != 4)
//	{
//		printf("사용법 : %s [시작 단] [끝 단] [출력라인수]\n", argv[0]);
//		printf("주의 : - 시작, 끝 단, 출력라인수는 1~99까지의 숫자만 넣으세요\n");
//		printf("       - 시작 단이 끝 단 보다 크면 안됩니다\n");
//		printf("예) %s 3 90 4\n", argv[0]);
//		exit(1);
//	}
//	for (i = 1; i < 3; i++) //시작, 끝단의 제한 
//	{
//		ch = atoi(argv[i]);
//		temp[i] = ch;
//		if (diff(ch) == 0) // limit, start, end가 1~99 사이의 숫자인가를 묻는다.
//			error_print("1 ~ 99까지의 숫자만 넣으세요");
//	}
//	if (temp[1] > temp[2]) //시작 단이 끝 단 보다 크지 않도록 제한. start > end
//		error_print("시작 단이 끝 단 보다 크면 안됩니다");
//	temp[0] = atoi(argv[3]);
//	if (diff(temp[0]) == 0) //컬럼의 제한. diff(limit) == 0. limit가 1~99 사이의 숫자인가를 묻는다.
//		error_print("1~99까지의 숫자만 넣으세요");
//	googoo(temp[1], temp[2], temp[0]); //구구단. start, end, limit 매개변수 순.
//	return 0;
//}
//
//void error_print(char* msg) {
//	printf("%s\n", msg);
//	exit(1);
//}
//
//int diff(int cmp) {
//	if (1 <= cmp && cmp <= 99) return 1;
//	else return 0;
//}
//
//void googoo(int start, int end, int limit) {
//	int i, j;
//	int limit_remain = limit;
//	int print_start;
//	int print_end;
//
//	while (start <= end) {
//		if (limit_remain > 4) {
//			print_start = start;
//			start += 4;
//
//			print_end = print_start + 4;
//
//			limit_remain -= 4;
//		}
//		else {
//			print_start = start;
//			start += limit_remain;
//
//			print_end = print_start + limit_remain;
//
//			limit_remain = limit;
//		}
//		if (print_end > end + 1) print_end = end + 1;
//
//
//		for (i = 1; i < 10; i++) {
//			for (j = print_start; j < print_end; j++) {
//				printf("%d * %d = %-7d", j, i, j * i);
//				googoo_printed = 1;
//			}
//			check_terminal_window_is_full();
//			println();
//		}
//		println();
//	}
//}
//
//void check_terminal_window_is_full() {
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//	rows_window = csbi.srWindow.Bottom - csbi.srWindow.Top - 1;
//
//	if (rows_print >= rows_window) {
//		printf("press any key");
//		getch();
//
//		system("cls");
//		rows_print = 0;
//		googoo_printed = 0;
//	}
//}
//
//void println() {
//	if (googoo_printed) {
//		printf("\n");
//		rows_print++;
//	}
//}
