#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	int min = 99999;
	for (int i = 0; i <= 1667; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			b = 3 * i + 5 * j;
			if (b == a)
			{
				if (i + j < min) min = i + j;
			}
		}
	}

	if (min == 99999) cout << -1;
	else cout << min;

	return 0;
}