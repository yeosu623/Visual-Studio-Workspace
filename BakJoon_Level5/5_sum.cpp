#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < a; i++)
	{
		sum = sum + (int)s[i] - '0';
	}

	cout << sum;

	return 0;
}