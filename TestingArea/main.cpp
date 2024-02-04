#include <iostream>
#include <cstring>
using namespace std;

int farm[50][50];
int answer = 0;
int first_dfs = 1;
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { 1, 0, 0, -1 };
void dfs(int, int);
void moving(int, int);
void printArea();

void dfs(int x, int y)
{
	if (!farm[x][y]) return;
	else
	{
		farm[x][y] = 0;

		if (first_dfs)
		{
			answer++;

			first_dfs = 0;
			moving(x, y);
			first_dfs = 1;

			//printArea();
		}
		else
		{
			moving(x, y);
		}
	}
}

void moving(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] == -1 || x + dx[i] == 50) continue;
		if (y + dy[i] == -1 || y + dy[i] == 50) continue;

		dfs(x + dx[i], y + dy[i]);
	}
}

void printArea()
{
	cout << "answer : " << answer << '\n';
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (farm[i][j]) cout << 'O';
			else cout << '.';
		}
		cout << '\n';
	}
	cout << '\n' << '\n';
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int x, y;
	while (t--)
	{
		int m, n, k;
		cin >> m >> n >> k;

		memset(farm, 0, sizeof(farm));
		while (k--)
		{
			cin >> x >> y;
			farm[x][y] = 1;
		}

		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				dfs(i, j);

		cout << answer << '\n';
		answer = 0;
	}

	return 0;
}