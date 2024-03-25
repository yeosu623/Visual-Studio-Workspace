#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int G = gcd(a, b);
	int L = a * b / G;

	cout << G << ' ' << L;

	return 0;
}