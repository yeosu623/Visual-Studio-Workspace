#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cache[100001][101];
int weight[101];
int value[101];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int input1;
	int input2;
	for (int i = 1; i <= n; i++)
	{
		cin >> input1 >> input2;
		weight[i] = input1;
		value[i] = input2;
	}

	memset(cache, 0, sizeof(cache));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
		{
			if (weight[i] > j)
				cache[j][i] = cache[j][i - 1];
			else
				cache[j][i] = max(cache[j][i - 1], value[i] + cache[j - weight[i]][i - 1]);
		}

	cout << cache[k][n];

	return 0;
}