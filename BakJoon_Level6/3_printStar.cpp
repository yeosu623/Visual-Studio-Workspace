#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b, c;
	for (int i = 0; i < a - 1; i++)
	{
		b = a - 1 - i;
		c = 1 + (i * 2);

		for (int j = 0; j < b; j++)
			cout << ' ';
		for (int j = 0; j < c; j++)
			cout << '*';

		cout << '\n';
	}

	for (int i = 0; i < (2 * a - 1); i++)
	{
		cout << '*';
	}
	cout << '\n';

	for (int i = 0; i < a - 1; i++)
	{
		b = i + 1;
		c = (2 * a - 1) - (2 * (i + 1));

		for (int j = 0; j < b; j++)
			cout << ' ';
		for (int j = 0; j < c; j++)
			cout << '*';

		cout << '\n';
	}

	return 0;
}