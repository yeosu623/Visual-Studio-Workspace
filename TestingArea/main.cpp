#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int count_digits_for_n(int n)
{
	if (n == 0) return 1;

	int digits = 0;
	while (n)
	{
		digits++;
		n /= 10;
	}

	return digits;
}

bool cannot_goto_channel(vector<int> &v, int n)
{
	if (n == 0)
	{
		if (find(v.begin(), v.end(), 0) != v.end()) return true;
	}

	while (n)
	{
		int digit = n % 10;
		n /= 10;

		if (find(v.begin(), v.end(), digit) != v.end()) return true;
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int m;
	cin >> m;

	int input;
	vector<int> v;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	int n_digits = count_digits_for_n(n);
	int answer = INT_MAX;
	int diff;
	for (int i = 0; i <= 999999; i++)
	{
		if (cannot_goto_channel(v, i)) continue;

		diff = abs(i - n) + n_digits;
		if (diff < answer) answer = diff;
	}

	// ��� ���� ��ư�� ���峵�� ���
	// 100���� �����ϴ� ���� �� ���� ���.
	diff = abs(100 - n);
	if (diff < answer) answer = diff;

	cout << answer;

	return 0;
}