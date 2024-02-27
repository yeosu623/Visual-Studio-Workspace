#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int m, n;
int map[500][500][2]; // height, dp
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };
int dfs(int y, int x)
{
	if (map[y][x][1] != -1) return map[y][x][1];

	map[y][x][1] = 0;
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		if (mx < 0 || mx >= n) continue;
		int my = y + dy[i];
		if (my < 0 || my >= m) continue;

		if (map[y][x][0] > map[my][mx][0])
			map[y][x][1] += dfs(my, mx);
	}
	return map[y][x][1];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	int input;
	memset(map, -1, sizeof(map));
	map[m - 1][n - 1][1] = 1; // 끝점 표시
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			map[i][j][0] = input;
		}

	cout << dfs(0, 0);
	return 0;
}
