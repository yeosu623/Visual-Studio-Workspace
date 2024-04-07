#include <iostream>
#include <windows.h>
#include "scheduler_algorithm.h"
using namespace std;

int main()
{
	int scheduler;
	int number_of_process;

	while (true)
	{
		cout << "스케쥴링 정책 선택" << '\n';
		cout << "1. First Come, First Served" << '\n';
		cout << "2. Shortest-Job-First, nonpreemptive" << '\n';
		cout << "3. Shortest-Job-First, preemptive" << '\n';
		cout << "4. Prioirty Scheduling" << '\n';
		cout << "5. Round Robin Scheduling" << '\n';
		cout << "6. (new!) ???" << '\n';
		cout << "7. (new!) ???" << '\n';
		cout << "번호 입력 후 Enter : ";
		cin >> scheduler;
		system("cls");

		switch (scheduler)
		{
			do {
				cout << "프로세스 개수 입력(1 ~ 10개) : ";
				cin >> number_of_process;
			} while (number_of_process < 1 || number_of_process > 10);
			cout << '\n';

			case 1: // First come, First served Scheduling
				input_data_FCFS(number_of_process);
				execute_FCFS(number_of_process);
				print_result_FCFS(number_of_process);
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			default:
		}
	}
}