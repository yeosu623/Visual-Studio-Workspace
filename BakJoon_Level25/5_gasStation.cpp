#include <iostream>
using namespace std;

uint64_t dist[99999];
uint64_t oil[100000];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	uint64_t input;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> input;
		dist[i] = input;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		oil[i] = input;
	}

	int start = 0;
	uint64_t answer = 0;
	for (int end = 1; end < n; end++)
	{
		if (oil[start] > oil[end] || end == n - 1)
		{
			uint64_t move = 0;
			for (int i = start; i < end; i++)
				move += dist[i];
			answer += move * oil[start];

			start = end;
		}
	}

	cout << answer;

	return 0;
}