#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int c;
	while (a != 0)
	{
		c = a % b;
		a = a / b;

		if (c < 10)
			cout << c;
		else
			cout << (char)('A' - 10 + c);
	}

	return 0;
}