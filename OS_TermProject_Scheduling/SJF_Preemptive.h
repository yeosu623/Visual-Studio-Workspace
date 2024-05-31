#include <windows.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <random>
#include "main.h"
using namespace std;

class SJF_Preemptive {
private:
	int input;
	int n;
	int* process_number;
	Status* status;
	int* arrival_time;
	int* burst_time;

	float cpu_utilization;
	float throughput;
	int* turnaround_time;
	int* waiting_time;
	int* response_time;

	int preemptive_count = 0;
	int before_process_number;
	int after_process_number;
	int idx_none = 0;
	int idx_wait = 0;
	int idx_run = EMPTY;
	int elapsed_time = 0;
	int working_time = 0;
	float average_waiting_time;
	float average_turnaround_time;
	float average_response_time;
	string working_log = "";
public:
	SJF_Preemptive();
	int random_int(int, int);
	void sort_process();
	void sort_result();
	void sort_wait();
	void sort_run();
	void insert();
	void process();
	void result();
};