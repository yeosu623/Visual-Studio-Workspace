#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	cout << 1 - a << ' ' << 1 - b << ' ' << 2 - c << ' ' << 2 - d << ' ' << 2 - e << ' ' << 8 - f;

	return 0;
}