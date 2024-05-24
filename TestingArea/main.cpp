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

	int b;
	int c = 1;
	stack<int> st;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		st.push(b);

		while (st.top() == c)
		{
			st.pop();
			c++;

			if (st.empty()) break;
		}
	}

	if (a == c - 1) cout << "Nice";
	else cout << "Sad";

	return 0;
}