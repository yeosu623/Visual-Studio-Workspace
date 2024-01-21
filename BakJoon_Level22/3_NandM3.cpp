#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(8);

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			arr[cnt] = i;
			dfs(cnt + 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	dfs(0);
}