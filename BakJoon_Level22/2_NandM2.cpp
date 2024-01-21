#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited(9, false);
vector<int> arr(9);
int n, m;

void dfs(int cnt, int before)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (int i = 1 + before; i <= n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				arr[cnt] = i;
				dfs(cnt + 1, i);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	dfs(0, 0);
}