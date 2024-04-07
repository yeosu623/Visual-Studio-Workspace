#include <iostream>
#include <string>
#include <queue>
#include <windows.h>
using namespace std;

string process_name[10];
int arrival_time[10];
int burst_time[10];

int waiting_time[10];
int end_time;

void input_data_FCFS(int n)
{
	cout << "프로세스 정보를 입력해주세요." << '\n';
	cout << "(process name, arrival time, burst time을 순서대로 입력)" << '\n';
	for (int i = 0; i < n; i++)
	{
		cin >> process_name[i];
		cin >> arrival_time[i];
		cin >> burst_time[i];
	}
	system("cls");
}

void execute_FCFS(int n)
{

}