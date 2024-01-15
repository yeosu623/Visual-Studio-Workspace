#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b = 0;
	for (int i = 0; i < a; i++)
	{
		int c = i;
		int sum = i;
		while (c != 0)
		{
			sum += (c % 10);
			c /= 10;
		}
		if (sum == a)
		{
			b = i;
			break;
		}
	}

	cout << b;

	return 0;
}