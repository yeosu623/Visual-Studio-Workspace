#include "SJF_Preemptive_experiment.h"

int SJF_Preemptive_experiment::random_int(int min, int max) {
	random_device dev;
	mt19937 seed(dev());
	uniform_int_distribution<mt19937::result_type> random_range(min, max);

	return random_range(seed);
}

SJF_Preemptive_experiment::SJF_Preemptive_experiment() {
	system("cls");

	cout << "테스트 횟수 : ";
	cin >> tries;
	n_arr = new int[tries];
	arrival_time_arr = new int[tries];
	burst_time_arr = new int[tries];

	cout << "테스트 마다 프로세스 개수 : ";
	for (int i = 0; i < tries; i++) {
		cin >> input;
		n_arr[i] = input;
	}
	cout << "테스트 마다 arrival_time" << '\n';
	cout << "(0 : 0으로 고정, 1~ : [1, input]의 난숫값 생성) : ";
	for (int i = 0; i < tries; i++) {
		cin >> input;
		arrival_time_arr[i] = input;
	}
	cout << "테스트 마다 burst_time" << '\n';
	cout << "(0 : 10으로 고정, 1~ : [1, input]의 난숫값 생성) : ";
	for (int i = 0; i < tries; i++) {
		cin >> input;
		burst_time_arr[i] = input;
	}

	cout << "##Result##" << '\n';
	printf("\tn\telapsed\tCPU\tthrough\tavgwait\tavgturn\tavgresp\n");
	while (test_number != tries) {
		n = n_arr[test_number];
		printf("TEST%d\t", test_number + 1);
		insert();
		process();
		result();

		test_number++;
	}

	cin.get();
	cout << "Press enter key..";
	while (cin.get() != '\n');
	system("cls");

	delete[] n_arr;
	delete[] arrival_time_arr;
	delete[] burst_time_arr;
}

void SJF_Preemptive_experiment::sort_process() {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arrival_time[i] > arrival_time[j]) {
				swap(process_number[i], process_number[j]);
				swap(arrival_time[i], arrival_time[j]);
				swap(burst_time[i], burst_time[j]);
			}
}

void SJF_Preemptive_experiment::sort_result() {
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

void SJF_Preemptive_experiment::sort_wait() {
	for (int i = idx_wait; i < idx_none - 1; i++)
		for (int j = i + 1; j < idx_none; j++)
			if (burst_time[i] > burst_time[j]) {
				swap(process_number[i], process_number[j]);
				swap(arrival_time[i], arrival_time[j]);
				swap(burst_time[i], burst_time[j]);
				swap(turnaround_time[i], turnaround_time[j]);
				swap(waiting_time[i], waiting_time[j]);
				swap(response_time[i], response_time[j]);
			}
}

void SJF_Preemptive_experiment::sort_run() {
	for (int i = idx_run; i < idx_none - 1; i++)
		for (int j = i + 1; j < idx_none; j++)
			if (burst_time[i] > burst_time[j]) {
				swap(process_number[i], process_number[j]);
				swap(arrival_time[i], arrival_time[j]);
				swap(burst_time[i], burst_time[j]);
				swap(turnaround_time[i], turnaround_time[j]);
				swap(waiting_time[i], waiting_time[j]);
				swap(response_time[i], response_time[j]);
			}
}

void SJF_Preemptive_experiment::insert() {
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

	for (int i = 0; i < n; i++) {
		if (arrival_time_arr[test_number] == 0) arrival_time[i] = 0;
		else arrival_time[i] = random_int(1, arrival_time_arr[test_number]);
	}

	for (int i = 0; i < n; i++) {
		if (burst_time_arr[test_number] == 0) burst_time[i] = 10;
		else burst_time[i] = random_int(1, burst_time_arr[test_number]);
	}

	for (int i = 0; i < n; i++) {
		waiting_time[i] = 0;
		response_time[i] = EMPTY;
		turnaround_time[i] = EMPTY;
	}
}

void SJF_Preemptive_experiment::process() {
	idx_none = 0;
	idx_wait = 0;
	idx_run = EMPTY;
	elapsed_time = 0;
	working_time = 0;
	sort_process();

	while (1) {

		if (idx_none != n)
			while (arrival_time[idx_none] == elapsed_time) {
				status[idx_none] = WAIT;
				idx_none++;

				if (elapsed_time == 0) sort_wait();
				if (idx_none == n) break;
			}

		if (idx_wait != n)
			if (idx_run == EMPTY && status[idx_wait] == WAIT) {
				status[idx_wait] = RUN;
				idx_run = idx_wait;
				idx_wait++;
			}

		if (idx_run != EMPTY) {
			status[idx_run] = WAIT;
			sort_run();
			status[idx_run] = RUN;
		}

		if (idx_run != n)
			if (idx_run != EMPTY) {
				if (burst_time[idx_run] == 0) {
					status[idx_run] = END;
					idx_run = EMPTY;
					sort_wait();
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

void SJF_Preemptive_experiment::result() {
	printf("%d\t%d\t%.1f\t%.4f\t%.1f\t%.1f\t%.1f\n",
		n,
		elapsed_time,
		cpu_utilization,
		throughput,
		average_waiting_time,
		average_turnaround_time,
		average_response_time);

	delete[] process_number;
	delete[] status;
	delete[] arrival_time;
	delete[] burst_time;
	delete[] turnaround_time;
	delete[] waiting_time;
	delete[] response_time;
}