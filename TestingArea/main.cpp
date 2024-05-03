#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	int c, d, e, f;
	for (int i = 0; i < a; i++)
	{
		cin >> b;

		c = d = e = f = 0;
		while (b >= 25)
		{
			b -= 25; c++;
		}
		while (b >= 10)
		{
			b -= 10; d++;
		}
		while (b >= 5)
		{
			b -= 5; e++;
		}
		while (b >= 1)
		{
			b -= 1; f++;
		}

		cout << c << ' ' << d << ' ' << e << ' ' << f << '\n';
	}

	return 0;
}