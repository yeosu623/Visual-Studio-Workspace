#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int printed_line = 0;
CONSOLE_SCREEN_BUFFER_INFO csbi;

void error_print(char*);
int diff(int);
void googoo(int, int, int); // start, end, limit�� �޾Ƽ� �̹��� ����� start, end�� ������ �Լ�
void googoo_print(int, int); // �̹��� ����� start, end�� �޾Ƽ� �������� ����ϴ� �Լ�.
void handle_terminal(); // �͹̳� ���¸� Ȯ���� ��, ������ ������ �ٹٲ��� �ϰ� ������ ������ �͹̳� �ʱ�ȭ�� �ϴ� �Լ�.

int main(int argc, char* argv[])
{
	int i, ch, temp[3];
	if (argc != 4)
	{
		printf("���� : %s [���� ��] [�� ��] [��¶��μ�]\n", argv[0]);
		printf("���� : - ����, �� ��, ��¶��μ��� 1~99������ ���ڸ� ��������\n");
		printf("       - ���� ���� �� �� ���� ũ�� �ȵ˴ϴ�\n");
		printf("��) %s 3 90 4\n", argv[0]);
		exit(1);
	}
	for (i = 1; i < 3; i++) //����, ������ ���� 
	{
		ch = atoi(argv[i]);
		temp[i] = ch;
		if (diff(ch) == 0) // limit, start, end�� 1~99 ������ �����ΰ��� ���´�.
			error_print("1 ~ 99������ ���ڸ� ��������");
	}
	if (temp[1] > temp[2]) //���� ���� �� �� ���� ũ�� �ʵ��� ����. start > end
		error_print("���� ���� �� �� ���� ũ�� �ȵ˴ϴ�");
	temp[0] = atoi(argv[3]);
	if (diff(temp[0]) == 0) //�÷��� ����. diff(limit) == 0. limit�� 1~99 ������ �����ΰ��� ���´�.
		error_print("1~99������ ���ڸ� ��������");
	googoo(temp[1], temp[2], temp[0]); //������. start, end, limit �Ű����� ��.
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
			if (start + 4 > end) { googoo_print(start, end + 1); break; } // ����� ������ �Ѿ ���, end������ ����ϰ� ����
			googoo_print(start, start + 4);
			start += 4;

			limit_remain -= 4;
		}
		else {
			if (start + limit_remain > end) { googoo_print(start, end + 1); break; } // ����� ������ �Ѿ ���, end������ ����ϰ� ����
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