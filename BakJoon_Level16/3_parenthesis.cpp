#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	string s;
	stack<char> st;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		char c;
		for (int j = 0; j < s.length(); j++)
		{
			if (!st.empty()) c = st.top();
			else c = '?';

			st.push(s[j]);

			if (c == '(' && s[j] == ')')
			{
				st.pop();
				st.pop();
			}
		}

		if (st.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		while (!st.empty()) st.pop();
	}

	return 0;
}