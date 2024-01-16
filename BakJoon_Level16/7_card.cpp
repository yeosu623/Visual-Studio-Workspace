#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;
	
	queue<int> que;
	for (int i = 1; i <= a; i++)
	{
		que.push(i);
	}

	int b;
	while (que.size() != 1)
	{
		que.pop();
		b = que.front();
		que.pop();
		que.push(b);
	}

	cout << que.front();

	return 0;
}