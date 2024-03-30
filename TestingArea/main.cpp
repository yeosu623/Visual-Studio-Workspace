#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		string cmd;
		int n;
		string data;
		deque<int> deq;

		cin >> cmd;
		cin >> n;
		cin >> data;
		string num = "";
		for (int i = 1; i < data.length(); i++)
		{
			if (data[1] == ']') break;
			if (data[i] == ',' || data[i] == ']')
			{
				deq.push_back(stoi(num));
				num = "";
			}
			else num += data[i];
		}

		bool error = false;
		bool reversed = false;
		for (int i = 0; i < cmd.length(); i++)
		{
			if (deq.empty())
			{
				if (cmd[i] == 'D')
				{
					cout << "error";
					error = true;
					break;
				}
			}
			else if (cmd[i] == 'R')
			{
				reversed = !reversed;
			}
			else if (cmd[i] == 'D')
			{
				if (reversed) deq.pop_back();
				else deq.pop_front();
			}
		}

		if (!error)
		{
			cout << '[';
			while (!deq.empty())
			{
				if (reversed)
				{
					cout << deq.back();
					deq.pop_back();
				}
				else
				{
					cout << deq.front();
					deq.pop_front();
				}
				if (!deq.empty()) cout << ',';
			}
			cout << ']';
		}
		cout << '\n';
	}
}