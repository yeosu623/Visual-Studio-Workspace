#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int x = 1;
	int y = 1;
	int upLeft = 1;

	while (--a)
	{
		if (y == 1 && upLeft == 1)
		{
			x++;
			upLeft = 0;
		}
		else if (x == 1 && upLeft == 0)
		{
			y++;
			upLeft = 1;

		}
		else if (upLeft == 1)
		{
			x++;
			y--;
		}
		else
		{
			x--;
			y++;
		}
	}

	cout << y << '/' << x;

	return 0;
}