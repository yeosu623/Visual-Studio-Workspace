#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int cache[101][10];
	for (int i = 0; i < 10; i++)
		cache[1][i] = 1;

	for (int i = 2; i < 101; i++)
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				cache[i][0] = cache[i - 1][1];
			else if (j == 9)
				cache[i][9] = cache[i - 1][8];
			else
				cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j + 1];

			cache[i][j] %= 1000000000;
		}

	int n;
	cin >> n;

	uint64_t answer = 0;
	for (int i = 1; i < 10; i++)
		answer += cache[n][i];

	answer %= 1000000000;
	cout << answer;

	return 0;
}