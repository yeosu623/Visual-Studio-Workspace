#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	while (a != 1)
	{
		for (int i = 2; i <= a; i++)
		{
			if (a % i == 0)
			{
				cout << i << '\n';
				a /= i;
				break;
			}
		}
	}

	return 0;
}