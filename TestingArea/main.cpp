#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s, bomb;
	cin >> s >> bomb;
	reverse(bomb.begin(), bomb.end());

	char bomb_begin = bomb[0];
	stack<char> st;
	stack<char> buffer;
	for (int i = 0; i < s.length(); i++)
	{
		st.push(s[i]);
		if (st.top() == bomb_begin && st.size() >= bomb.length())
		{
			bool isBomb = true;
			for (int i = 0; i < bomb.length(); i++)
			{
				if (st.top() == bomb[i])
				{
					buffer.push(st.top());
					st.pop();
				}
				else
				{
					isBomb = false;
					break;
				}
			}

			while (!buffer.empty())
			{
				if (!isBomb) st.push(buffer.top());
				buffer.pop();
			}
		}
	}

	if (st.empty()) cout << "FRULA";
	else
	{
		string answer;
		while (!st.empty())
		{
			answer += st.top();
			st.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << answer;
	}
	return 0;
}