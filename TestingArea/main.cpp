#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	char a;
	string s;
	stack<char> st;
	while (true)
	{
		getline(cin, s);
		if (s == ".") break;

		for (int i = 0; i < s.length(); i++)
		{
			a = s[i];

			if (a == '(')
			{
				st.push(a);
			}
			if (a == ')')
			{
				if (st.empty()) st.push(a);
				else
				{
					if (st.top() == '(')
					{
						st.push(a);
						st.pop();
						st.pop();
					}
					else
					{
						st.push(a);
					}
				}
			}

			if (a == '[')
			{
				st.push(a);
			}
			if (a == ']')
			{
				if (st.empty()) st.push(a);
				else
				{
					if (st.top() == '[')
					{
						st.push(a);
						st.pop();
						st.pop();
					}
					else
					{
						st.push(a);
					}
				}
			}
		}

		if (st.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';

		while (!st.empty()) st.pop();
	}

	return 0;
}