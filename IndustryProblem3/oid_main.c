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
//		printf("���� : %s [���� ��] [�� ��] [��¶��μ�]\n", argv[0]);
//		printf("���� : - ����, �� ��, ��¶��μ��� 1~99������ ���ڸ� ��������\n");
//		printf("       - ���� ���� �� �� ���� ũ�� �ȵ˴ϴ�\n");
//		printf("��) %s 3 90 4\n", argv[0]);
//		exit(1);
//	}
//	for (i = 1; i < 3; i++) //����, ������ ���� 
//	{
//		ch = atoi(argv[i]);
//		temp[i] = ch;
//		if (diff(ch) == 0) // limit, start, end�� 1~99 ������ �����ΰ��� ���´�.
//			error_print("1 ~ 99������ ���ڸ� ��������");
//	}
//	if (temp[1] > temp[2]) //���� ���� �� �� ���� ũ�� �ʵ��� ����. start > end
//		error_print("���� ���� �� �� ���� ũ�� �ȵ˴ϴ�");
//	temp[0] = atoi(argv[3]);
//	if (diff(temp[0]) == 0) //�÷��� ����. diff(limit) == 0. limit�� 1~99 ������ �����ΰ��� ���´�.
//		error_print("1~99������ ���ڸ� ��������");
//	googoo(temp[1], temp[2], temp[0]); //������. start, end, limit �Ű����� ��.
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
