#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	char input;
	char art[100][100];
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			art[i][j] = input;
		}

	int dy[4] = {1, 0, 0, -1};
	int dx[4] = { 0, 1, -1, 0 };
	int art_human_region = 0, art_cow_region = 0;
	char color;
	queue<pair<short, short>> que;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			color = art[i][j];
			if (color != 'O')
			{
				que.push({ i, j });
				art_human_region++;
			}
			while (!que.empty())
			{
				int y = que.front().first;
				int x = que.front().second;
				art[y][x] = 'O';
				que.pop();

				for (int i = 0; i < 4; i++)
				{
					int my = y + dy[i];
					if (y < 0 || y >= n) continue;
					int mx = x + dx[i];
					if (x < 0 || x >= n) continue;

					if (art[my][mx] == color)
						que.push({ my, mx });
				}
			}
		}
}