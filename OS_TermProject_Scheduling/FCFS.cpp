#include "FCFS.h"

int FCFS::random_int(int min, int max) {
	random_device dev;
	mt19937 seed(dev());
	uniform_int_distribution<mt19937::result_type> random_range(min, max);

	return random_range(seed);
}

FCFS::FCFS() {
	system("cls");
	insert();
	process();
	result();
}

void FCFS::sort_process() {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arrival_time[i] > arrival_time[j]) {
				swap(process_number[i], process_number[j]);
				swap(arrival_time[i], arrival_time[j]);
				swap(burst_time[i], burst_time[j]);
			}
}

void FCFS::sort_result() {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (process_number[i] > process_number[j]) {
				swap(process_number[i], process_number[j]);
				swap(arrival_time[i], arrival_time[j]);
				swap(burst_time[i], burst_time[j]);
				swap(turnaround_time[i], turnaround_time[j]);
				swap(waiting_time[i], waiting_time[j]);
				swap(response_time[i], response_time[j]);
			}
}

void FCFS::insert() {
	cout << "프로세스 개수 : ";
	cin >> n;
	process_number = new int[n];
	status = new Status[n];
	arrival_time = new int[n];
	burst_time = new int[n];
	turnaround_time = new int[n];
	waiting_time = new int[n];
	response_time = new int[n];

	for (int i = 0; i < n; i++) {
		process_number[i] = i + 1;
		status[i] = NONE;
	}

	cout << "P1 ~ P" << n << "의 Arrival Time : ";
	for (int i = 0; i < n; i++) {
		cin >> input;
		arrival_time[i] = input;
	}

	cout << "P1 ~ P" << n << "의 Burst Time : ";
	for (int i = 0; i < n; i++) {
		cin >> input;
		burst_time[i] = input;
	}

	for (int i = 0; i < n; i++) {
		waiting_time[i] = 0;
		response_time[i] = EMPTY;
		turnaround_time[i] = EMPTY;
	}
}

void FCFS::process() {
	sort_process();

	while (1) {

		if (idx_none != n)
			while (arrival_time[idx_none] == elapsed_time) {
				status[idx_none] = WAIT;
				idx_none++;

				if (idx_none == n) break;
			}

		if (idx_wait != n)
			if (idx_run == EMPTY && status[idx_wait] == WAIT) {
				status[idx_wait] = RUN;
				idx_run = idx_wait;
				idx_wait++;
			}

		if (idx_run != n)
			if (idx_run != EMPTY) {
				if (burst_time[idx_run] == 0) {
					status[idx_run] = END;
					idx_run = EMPTY;
					continue; // 해당 작업이 끝나면, WAIT 상태인 다음 작업을 바로 실행하기 위해서.
				}
				burst_time[idx_run]--;
			}

		for (int i = 0; i < n; i++) {
			if (status[i] == WAIT) waiting_time[i]++;
			if (status[i] == RUN && response_time[i] == EMPTY) response_time[i] = elapsed_time - arrival_time[i];
			if (status[i] == END && turnaround_time[i] == EMPTY) turnaround_time[i] = elapsed_time - arrival_time[i];
		}

		if (status[n - 1] == END) break;

		elapsed_time++;
		if (idx_run != EMPTY) working_time++;

		if (idx_run == EMPTY) working_log += ".";
		else working_log += to_string(process_number[idx_run]);
	}

	cpu_utilization = (float)working_time / elapsed_time * 100;
	throughput = (float)n / elapsed_time;

	int total_waiting_time = 0;
	int total_turnaround_time = 0;
	int total_response_time = 0;
	for (int i = 0; i < n; i++) {
		total_waiting_time += waiting_time[i];
		total_turnaround_time += turnaround_time[i];
		total_response_time += response_time[i];
	}
	average_waiting_time = (float)total_waiting_time / n;
	average_turnaround_time = (float)total_turnaround_time / n;
	average_response_time = (float)total_response_time / n;
}

void FCFS::result() {
	sort_result();

	cout << '\n' << '\n';
	cout << "## Result ##" << '\n';
	cout << "Gantt Chart : " << working_log << '\n' << '\n';

	cout << "elasped time : " << elapsed_time << '\n';
	cout << "working time : " << working_time << '\n';
	printf("CPU utilization : %.1f%%\n", cpu_utilization);
	printf("throughput : %.4f Jobs/sec\n", throughput);
	printf("average waiting time : %.1fs\n", average_waiting_time);
	printf("average response time : %.1fs\n", average_response_time);
	printf("average turnaround time : %.1fs\n\n", average_turnaround_time);

	cout << "process         : ";
	for (int i = 0; i < n; i++) printf("P%-3d", process_number[i]);
	cout << '\n';

	cout << "waiting_time    : ";
	for (int i = 0; i < n; i++) printf("%-4d", waiting_time[i]);
	cout << '\n';

	cout << "response_time   : ";
	for (int i = 0; i < n; i++) printf("%-4d", response_time[i]);
	cout << '\n';

	cout << "turnaround_time : ";
	for (int i = 0; i < n; i++) printf("%-4d", turnaround_time[i]);
	cout << '\n' << '\n';

	cin.get();
	cout << "Press enter key..";
	while (cin.get() != '\n');
	system("cls");

	delete[] process_number;
	delete[] status;
	delete[] arrival_time;
	delete[] burst_time;
	delete[] turnaround_time;
	delete[] waiting_time;
	delete[] response_time;
}