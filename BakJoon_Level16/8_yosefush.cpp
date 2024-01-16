#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	vector<int> v;
	queue<int> que;
	for (int i = 1; i <= a; i++)
	{
		que.push(i);
	}

	int c = 0;
	int d;
	while (!que.empty())
	{
		c++;
		d = que.front();
		que.pop();

		if (c == b) 
		{
			v.push_back(d);
			c = 0;
		}
		else que.push(d);
	}

	cout << '<';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << '>';

	return 0;
}