#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	string temp;
	int answer = 0;

	// 첫 숫자가 -일 경우, 모든 숫자를 빼면 답이 나온다.
	if (s[0] == '-')
	{
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '+' || s[i] == '-')
			{
				answer -= stoi(temp);
				temp = "";
			}
			else temp += s[i];
		}

		answer -= stoi(temp);
		cout << answer;
		return 0;
	}

	int minus_begin = INT_MAX;
	// 첫 숫자가 +일 경우, 처음 -가 나올떄까지 더한 다음
	// -가 나오는 순간부터는 모든 숫자를 뺸다.
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+')
		{
			answer += stoi(temp);
			temp = "";
		}
		else if (s[i] == '-')
		{
			answer += stoi(temp);
			temp = "";

			minus_begin = i;
			break;
		}
		else temp += s[i];
	}

	for (int i = minus_begin + 1; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			answer -= stoi(temp);
			temp = "";
		}
		else temp += s[i];
	}

	if (minus_begin == INT_MAX) answer += stoi(temp); // 전부 양수
	else answer -= stoi(temp); // 뒤에 음수가 있음.

	cout << answer;
	return 0;
}