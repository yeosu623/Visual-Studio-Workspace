#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input;
	int v[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v[i] = input;
	}

	int increasing[1000];
	increasing[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int max_length = 1;
		for (int j = 0; j < i; j++)
			if (v[j] < v[i])
				max_length = max(max_length, increasing[j] + 1);

		increasing[i] = max_length;
	}

	int decreasing[1000];
	decreasing[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		int max_length = 1;
		for (int j = n - 1; i < j; j--)
			if (v[j] < v[i])
				max_length = max(max_length, decreasing[j] + 1);

		decreasing[i] = max_length;
	}

	int answer[1000];
	for (int i = 0; i < n; i++)
		answer[i] = increasing[i] + decreasing[i] - 1;

	cout << *max_element(answer, answer + n);

	return 0;
}