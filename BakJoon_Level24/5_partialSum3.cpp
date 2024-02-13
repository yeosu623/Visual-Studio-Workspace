#include <iostream>
#include <cstring>
using namespace std;

int v[1025][1025];
int sum[1025][1025];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int input;
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> input;
			v[i][j] = input;
			sum[i][j] = sum[i][j - 1] + v[i][j];
		}

	int x1, y1, x2, y2;
	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		uint64_t answer = 0;
		for (int i = x1; i <= x2; i++)
			answer += sum[i][y2] - sum[i][y1 - 1];

		cout << answer << '\n';
	}

	return 0;
}