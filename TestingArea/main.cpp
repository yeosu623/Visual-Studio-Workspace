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

	// ù ���ڰ� -�� ���, ��� ���ڸ� ���� ���� ���´�.
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
	// ù ���ڰ� +�� ���, ó�� -�� ���Ë����� ���� ����
	// -�� ������ �������ʹ� ��� ���ڸ� �A��.
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

	if (minus_begin == INT_MAX) answer += stoi(temp); // ���� ���
	else answer -= stoi(temp); // �ڿ� ������ ����.

	cout << answer;
	return 0;
}