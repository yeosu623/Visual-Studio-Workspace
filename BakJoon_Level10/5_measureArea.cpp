#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	a--;
	int x, y;
	cin >> x >> y;
	int minX = x, minY = y, maxX = x, maxY = y;

	while (a--)
	{
		cin >> x >> y;
		if (x < minX) minX = x;
		if (y < minY) minY = y;
		if (x > maxX) maxX = x;
		if (y > maxY) maxY = y;
	}

	cout << (maxX - minX) * (maxY - minY);

	return 0;
}