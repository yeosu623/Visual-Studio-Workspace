#include <iostream>
#include <deque>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b, c;
	deque<int> deq;
	for (int i = 0; i < a; i++)
	{
		cin >> b;

		if (b == 1)
		{
			cin >> c;
			deq.push_front(c);
		}
		else if (b == 2)
		{
			cin >> c;
			deq.push_back(c);
		}
		else if (b == 3)
		{
			if (deq.empty()) cout << -1 << '\n';
			else
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		else if (b == 4)
		{
			if (deq.empty()) cout << -1 << '\n';
			else
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		else if (b == 5)
		{
			cout << deq.size() << '\n';
		}
		else if (b == 6)
		{
			cout << deq.empty() << '\n';
		}
		else if (b == 7)
		{
			if (deq.empty()) cout << -1 << '\n';
			else cout << deq.front() << '\n';
		}
		else if (b == 8)
		{
			if (deq.empty()) cout << -1 << '\n';
			else cout << deq.back() << '\n';
		}
	}

	return 0;
}