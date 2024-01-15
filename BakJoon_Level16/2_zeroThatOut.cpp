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
	stack<int> st;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		if (b == 0) st.pop();
		else st.push(b);
	}

	int size = st.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += st.top();
		st.pop();
	}

	cout << sum;

	return 0;
}