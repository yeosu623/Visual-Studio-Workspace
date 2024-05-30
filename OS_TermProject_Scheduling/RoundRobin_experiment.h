#include <windows.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <random>
#include "main.h"
using namespace std;

class RoundRobin_experiment {
private:
	int input;
	int n;
	int* n_arr;
	int* arrival_time_arr;
	int* burst_time_arr;
	int* time_quantum_arr;
	int tries;
	int test_number = 0;
	int* process_number;
	Status* status;
	int* arrival_time;
	int* burst_time;
	int time_quantum;
	int time_count = 0;
	int round_robin_count = 0;

	float cpu_utilization;
	float throughput;
	int* turnaround_time;
	int* waiting_time;
	int* response_time;

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
	RoundRobin_experiment();
	int random_int(int, int);
	void sort_process();
	void sort_result();
	void next_run();
	void insert();
	void process();
	void result();
};