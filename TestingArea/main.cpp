#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int cache[1000][3];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		cache[i][0] = a;
		cache[i][1] = b;
		cache[i][2] = c;
	}

	for (int i = 1; i < n; i++)
	{
		cache[i][0] += min(cache[i - 1][1], cache[i - 1][2]);
		cache[i][1] += min(cache[i - 1][0], cache[i - 1][2]);
		cache[i][2] += min(cache[i - 1][0], cache[i - 1][1]);
	}

	int answer;
	answer = min(cache[n - 1][0], cache[n - 1][1]);
	answer = min(answer, cache[n - 1][2]);

	cout << answer;

	return 0;
}