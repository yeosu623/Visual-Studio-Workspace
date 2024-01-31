#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	string s;
	int b;
	deque<int> deq;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		if (s == "push_front")
		{
			cin >> b;
			deq.push_front(b);
		}
		else if (s == "push_back")
		{
			cin >> b;
			deq.push_back(b);
		}
		else if (s == "pop_front")
		{
			if (deq.empty()) cout << -1 << '\n';
			else
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		else if (s == "pop_back")
		{
			if (deq.empty()) cout << -1 << '\n';
			else
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		else if (s == "size")
		{
			cout << deq.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << deq.empty() << '\n';
		}
		else if (s == "front")
		{
			if (deq.empty()) cout << -1 << '\n';
			else cout << deq.front() << '\n';
		}
		else if (s == "back")
		{
			if (deq.empty()) cout << -1 << '\n';
			else cout << deq.back() << '\n';
		}
	}

	return 0;
}