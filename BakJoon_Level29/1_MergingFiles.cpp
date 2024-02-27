#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int input;
	int t, k;
	int cache[500][500];

	cin >> t;
	while (t--)
	{
		cin >> k;

		// layer1
		memset(cache, 0, sizeof(cache));
		for (int i = 0; i < k; i++)
		{
			cin >> input;
			cache[0][i] = input;
		}

		// layer2
		for (int i = 0; i < k - 1; i++)
			cache[1][i] = cache[0][i] + cache[0][i + 1];

		// layer3 ~
		for (int y = 2; y < k; y++)
			for (int x = 0; x < k - y; x++)
			{
				int layer0_sum = 0;
				for (int i = x; i <= y + x; i++)
					layer0_sum += cache[0][i];

				int dp_min = INT_MAX;
				int dp;
				for (int i = 0; i < y; i++)
				{
					dp = cache[y - 1 - i][x] + cache[i][y + x - i];
					if (i == 0) dp -= cache[i][y + x - i];
					else if (y - 1 - i == 0) dp -= cache[y - 1 - i][x];

					dp_min = min(dp_min, dp);
				}

				cache[y][x] = layer0_sum + dp_min;
			}

		cout << cache[k - 1][0] << '\n';
	}

	return 0;
}
