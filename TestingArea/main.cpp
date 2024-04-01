#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int cache[500][500][3]; // r, c, dp

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	// layer0
	int input1, input2;
	memset(cache, 0, sizeof(cache));
	for (int i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		cache[0][i][0] = input1;
		cache[0][i][1] = input2;
	}

	// layer1 ~
	int y1, x1, y2, x2;
	for (int y = 1; y < n; y++)
		for (int x = 0; x < n - y; x++)
		{
			cache[y][x][0] = cache[y - 1][x][0];
			cache[y][x][1] = cache[y - 1][x + 1][1];

			int dp_min = INT_MAX;
			for (int i = 0; i < y; i++)
			{
				y1 = y - 1 - i;
				x1 = x;
				y2 = i;
				x2 = y + x - i;

				int matrix = cache[y1][x1][0] * cache[y2][x2][0] * cache[y2][x2][1];
				int dp = cache[y1][x1][2] + cache[y2][x2][2] + matrix;
				dp_min = min(dp_min, dp);
			}
			cache[y][x][2] = dp_min;
		}

	cout << cache[n - 1][0][2];
	return 0;
}
