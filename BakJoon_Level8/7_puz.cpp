#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	c -= a;

	int d = a - b;
	int e;
	if (c % d == 0) e = c / d + 1;
	else e = c / d + 2;

	cout << e;

	return 0;
}