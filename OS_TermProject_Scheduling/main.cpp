#include <windows.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <random>
#include "FCFS.h"
#include "FCFS_experiment.h"
#include "SJF_NonPreemptive.h"
#include "SJF_NonPreemptive_experiment.h"
#include "SJF_Preemptive.h"
#include "SJF_Preemptive_experiment.h"
#include "RoundRobin.h"
#include "RoundRobin_experiment.h"
using namespace std;

int main() {
	string mode;

	while (1) {
		cout << "OS Term Project - Scheduling" << '\n';
		cout << "숫자 뒤에 e를 붙일 시, 실험 모드로 진입합니다." << '\n';
		cout << "1. FCFS" << '\n';
		cout << "2. SJF(Non-Preemptive)" << '\n';
		cout << "3. SJF(Preemptive)" << '\n';
		cout << "4. Round Robin" << '\n';
		cout << "5. exit" << '\n';
		cout << "Input : ";
		cin >> mode;

		if (mode == "1")  FCFS();
		else if (mode == "1e") FCFS_experiment();
		else if (mode == "2")  SJF_NonPreemptive();
		else if (mode == "2e") SJF_NonPreemptive_experiment();
		else if (mode == "3")  SJF_Preemptive();
		else if (mode == "3e") SJF_Preemptive_experiment();
		else if (mode == "4")  RoundRobin();
		else if (mode == "4e") RoundRobin_experiment();
		else if (mode == "5")  exit(0);
		else if (mode == "5e") {
			cout << '\n';
			cout << "교수님 사랑합니다." << '\n';
			cout << "Press enter key.." << '\n';
			cin.get();
			while (cin.get() != '\n');
		}

		system("cls");
	}
}