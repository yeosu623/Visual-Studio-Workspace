#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	vector<int> v;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b); // 0이면 큐, 1이면 스택
	}

	int c;
	deque<int> deq;
	for (int i = 0; i < a; i++)
	{
		cin >> c;
		if (!v[i])
		{
			deq.push_front(c);
		}
	}

	int d;
	cin >> d;

	int e;
	for (int i = 0; i < d; i++)
	{
		cin >> e;

		if (deq.empty()) // ALL stack
		{
			cout << e << ' ';
			continue;
		}

		deq.push_back(e);

		cout << deq.front() << ' ';
		deq.pop_front();
	}

	return 0;
}