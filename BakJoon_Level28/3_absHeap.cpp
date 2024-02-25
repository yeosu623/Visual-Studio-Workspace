#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input;
	priority_queue<int, vector<int>, cmp> pq;
	while (n--)
	{
		cin >> input;
		if (input != 0) pq.push(input);
		else
		{
			if (pq.empty()) cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return 0;
}
