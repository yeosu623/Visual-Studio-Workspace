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
	cout << "수식을 입력하세요(+, -, *, / 만 사용, 정수만 입력)" << endl;
	cout << "입력식 : ";
	getline(cin, s, '\n');

	/* Step 1. 피연산자(num), 연산자(op) 분류 작업 */
	double num[MAX_SIZE];
	int numIndex = 0;
	char op[MAX_SIZE];
	int opIndex = 0;

	int startIndex = 0;
	while (true) {

		// 연산자 인덱스 검색 및 저장
		int fIndex = -1;
		for (int i = startIndex; i < s.length(); i++) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				op[opIndex++] = s[i];
				fIndex = i;
				break;
			}
			else if (s[i] < '0' || s[i] > '9') {
				printError("결과 : 알수 없는 연산자가 사용되었습니다.");
			}
		}

		// 연산자가 뒤에 없는 경우. 즉, 마지막 숫자인 경우.
		if (fIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "") break; 

			num[numIndex++] = (double)stoi(part); 
			break;
		}

		// 숫자 저장
		int count = fIndex - startIndex; 
		string part = s.substr(startIndex, count);

		num[numIndex++] = (double)stoi(part);
		startIndex = fIndex + 1;
	}

	/* Step 2. *와 / 계산하기 */
	if (numIndex <= opIndex) printError("결과 : 입력식이 잘못되었습니다.");
	
	for (int i = 0; i < opIndex; i++) {
		if (op[i] == '*') {
			num[i + 1] = num[i] * num[i + 1];
			num[i] = 0;
			op[i] = '+';
		}
		if (op[i] == '/') {
			if (isZero(num[i + 1])) printError("결과 : 0으로 나눌 수 없습니다.");
			num[i + 1] = num[i] / num[i + 1];
			num[i] = 0;
			op[i] = '+';
		}
	}

	/* Step 3. +와 - 계산하기 */
	double answer = num[0];

	for (int i = 0; i < opIndex; i++) {
		if (op[i] == '+') answer += num[i + 1];
		else if (op[i] == '-') answer -= num[i + 1];
	}

	cout << "결과 : " << answer;
	return 0;
}