#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	// (, ), [, ] 의 아스키 코드 숫자 구분을 위해, 숫자는 음수로 표기
	int value;
	bool correct = true;
	stack<int> st;
	for (int i = 0; i < s.size(); i++) {
		value = -1;
		st.push(s[i]);

		switch (st.top()) {
		case ')':
			st.pop();
			if (!st.empty() && st.top() < 0) {	value = st.top(); st.pop();	}
			if (!st.empty() && st.top() == '(') { st.pop(); st.push(value * 2); }
			else correct = false;
			break;
		case ']':
			st.pop();
			if (!st.empty() && st.top() < 0) { value = st.top(); st.pop(); }
			if (!st.empty() && st.top() == '[') { st.pop(); st.push(value * 3); }
			else correct = false;
			break;
		}

		if (!st.empty() && st.top() < 0) {
			value = st.top(); st.pop();
			if (!st.empty() && st.top() < 0) { value += st.top(); st.pop(); st.push(value); }
			else st.push(value);
		}

		if (!correct) break;
		//cout << "stack : ";

		//stack<int> st2(st);
		//stack<int> st3;
		//while (!st2.empty()) {
		//	st3.push(st2.top());
		//	st2.pop();
		//}
		//while (!st3.empty()) {
		//	cout << st3.top() << ' ';
		//	st3.pop();
		//}
		//cout << '\n';
	}

	int answer = 0;
	while (!st.empty()) {
		answer -= st.top();
		st.pop();
	}

	if (correct) cout << answer;
	else cout << 0;
} 