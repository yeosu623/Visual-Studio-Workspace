#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	int max;
	if (a > b && a > c) max = a;
	else if (b > a && b > c) max = b;
	else max = c;

	if (max == a)
		while (a >= b + c) a--;
	else if (max == b)
		while (b >= a + c) b--;
	else
		while (c >= a + b) c--;

	cout << a + b + c;

	return 0;
}