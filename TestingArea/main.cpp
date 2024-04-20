#include <iostream>
#include <string>
#define ZERO_RANGE 0.000000001
#define MAX_SIZE 100
using namespace std;

void printError(string msg) {
	cout << msg << '\n';
	exit(0);
}

bool isZero(double n) {
	if (-ZERO_RANGE < n && n < ZERO_RANGE) return true;
	else return false;
}

int main() {
	string s;
	cout << "������ �Է��ϼ���(+, -, *, / �� ���, ������ �Է�)" << endl;
	cout << "�Է½� : ";
	getline(cin, s, '\n');

	/* Step 1. �ǿ�����(num), ������(op) �з� �۾� */
	double num[MAX_SIZE];
	int numIndex = 0;
	char op[MAX_SIZE];
	int opIndex = 0;

	int startIndex = 0;
	while (true) {

		// ������ �ε��� �˻� �� ����
		int fIndex = -1;
		for (int i = startIndex; i < s.length(); i++) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				op[opIndex++] = s[i];
				fIndex = i;
				break;
			}
			else if (s[i] < '0' || s[i] > '9') {
				printError("��� : �˼� ���� �����ڰ� ���Ǿ����ϴ�.");
			}
		}

		// �����ڰ� �ڿ� ���� ���. ��, ������ ������ ���.
		if (fIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "") break; 

			num[numIndex++] = (double)stoi(part); 
			break;
		}

		// ���� ����
		int count = fIndex - startIndex; 
		string part = s.substr(startIndex, count);

		num[numIndex++] = (double)stoi(part);
		startIndex = fIndex + 1;
	}

	/* Step 2. *�� / ����ϱ� */
	if (numIndex <= opIndex) printError("��� : �Է½��� �߸��Ǿ����ϴ�.");
	
	for (int i = 0; i < opIndex; i++) {
		if (op[i] == '*') {
			num[i + 1] = num[i] * num[i + 1];
			num[i] = 0;
			op[i] = '+';
		}
		if (op[i] == '/') {
			if (isZero(num[i + 1])) printError("��� : 0���� ���� �� �����ϴ�.");
			num[i + 1] = num[i] / num[i + 1];
			num[i] = 0;
			op[i] = '+';
		}
	}

	/* Step 3. +�� - ����ϱ� */
	double answer = num[0];

	for (int i = 0; i < opIndex; i++) {
		if (op[i] == '+') answer += num[i + 1];
		else if (op[i] == '-') answer -= num[i + 1];
	}

	cout << "��� : " << answer;
	return 0;
}