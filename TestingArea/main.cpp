#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int m, n;
int map[500][500][2]; // height, already_visited
int dx[4] = {0, 1, -1, 0};
int dy[4] = { 1, 0, 0, -1 };
int answer = 0;
void dfs(int y, int x)
{
	if (map[y][x][1] != -1) // 이미 갔던 길
	{
		answer++;
		return;
	}
	else map[y][x][1] == 1; // 안갔으면 직접 표시

	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		if (mx < 0 || mx >= n) continue;
		int my = y + dy[i];
		if (my < 0 || my >= m) continue;

		if (map[y][x][0] > map[my][mx][0]) dfs(my, mx);
	}
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
	//for(int i = 0; i < m; i++)
	//	for (int j = 0; j < n; j++)
	//	{
	//		cin >> input;
	//		map[i][j][0] = input;
	//	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			map[i][j][0] = 30000 - i - j;
		}
	cout << "calculating..." << '\n';
	
	dfs(0, 0);

	cout << answer;
	return 0;
}
