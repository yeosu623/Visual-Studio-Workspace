#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b, c;
	stack<int> st;
	for (int i = 0; i < a; i++)
	{
		cin >> b;

		if (b == 1)
		{
			cin >> c;
			st.push(c);
		}
		else if (b == 2)
		{
			if (st.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (b == 3)
		{
			cout << st.size() << '\n';
		}
		else if (b == 4)
		{
			cout << st.empty() << '\n';
		}
		else if (b == 5)
		{
			if (st.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
			}
		}
	}

	return 0;
}