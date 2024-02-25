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

	int input;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--)
	{
		cin >> input;
		if (input > 0) pq.push(input);
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