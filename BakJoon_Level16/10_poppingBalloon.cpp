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
	
	int b;
	deque<pair<int, int>> deq;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		deq.push_back({ i + 1, b });
	}

	pair<int, int> target = deq.front();
	deq.pop_front();

	pair<int, int> temp;
	int move;
	while (!deq.empty())
	{
		cout << target.first << ' ';
		move = target.second;

		if (move > 0)
		{
			while (--move)
			{
				temp = deq.front();
				deq.pop_front();

				deq.push_back(temp);
			}
			target = deq.front();
			deq.pop_front();
		}
		else if (move < 0)
		{
			while (++move)
			{
				temp = deq.back();
				deq.pop_back();

				deq.push_front(temp);
			}
			target = deq.back();
			deq.pop_back();
		}
	}

	cout << target.first << ' ';

	return 0;
}