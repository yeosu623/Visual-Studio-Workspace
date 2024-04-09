#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> que;
	que.push({ n, 0 });

	int visited[200001];
	memset(visited, 0, sizeof(visited));
	visited[n] = 1;

	while (1)
	{
		pair<int, int> temp = que.front();
		que.pop();

		int place = temp.first;
		int time = temp.second;

		if (place == k)
		{
			cout << time;
			break;
		}

		if (!visited[place - 1])
			if (place - 1 >= 0)
			{
				visited[place - 1] = 1;
				que.push({ place - 1, time + 1 });
			}
		if (!visited[place + 1])
			if (place + 1 <= 100000)
			{
				visited[place + 1] = 1;
				que.push({ place + 1, time + 1 });
			}
		if (!visited[place * 2])
			if (place * 2 <= 100000)
			{
				visited[place * 2] = 1;
				que.push({ place * 2, time + 1 });
			}
	}

	return 0;
}