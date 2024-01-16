#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	string s;
	queue<int> que;
	for (int i = 0; i < a; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> b;
			que.push(b);
		}
		else if (s == "pop")
		{
			if (que.empty()) cout << -1 << '\n';
			else
			{
				cout << que.front() << '\n';
				que.pop();
			}
		}
		else if (s == "size")
		{
			cout << que.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << que.empty() << '\n';
		}
		else if (s == "front")
		{
			if (que.empty()) cout << -1 << '\n';
			else cout << que.front() << '\n';
		}
		else if (s == "back")
		{
			if (que.empty()) cout << -1 << '\n';
			else cout << que.back() << '\n';
		}
	}

	return 0;
}