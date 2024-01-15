#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if (a * x + b * y == c)
			{
				if (d * x + e * y == f)
				{
					cout << x << ' ' << y;
					break;
				}
			}
		}
	}

	return 0;
}