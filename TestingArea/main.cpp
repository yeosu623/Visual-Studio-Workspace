#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[1000][1000];
int answer[1000][1000];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int input;
	int sy, sx;
	memset(answer, -1, sizeof(answer));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			map[i][j] = input;
			if (input == 0) answer[i][j] = 0;
			if (input == 2)
			{
				sy = i;
				sx = j;
			}
		}

	int dy[4] = { 1, 0, 0, -1 };
	int dx[4] = { 0, 1, -1, 0 };
	queue<pair<int, int>> que;
	que.push({ sy, sx });
	answer[sy][sx] = 0;

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int my = y + dy[i];
			if (my < 0 || my >= n) continue;
			int mx = x + dx[i];
			if (mx < 0 || mx >= m) continue;

			if (map[my][mx] == 1 && answer[my][mx] == -1)
			{
				answer[my][mx] = answer[y][x] + 1;
				que.push({ my, mx });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}