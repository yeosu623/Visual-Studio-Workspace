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

	int a;
	cin >> a;

	int b, c;
	for (int i = 0; i < a; i++)
	{
		cin >> b >> c;
		cout << (b * c) / gcd(b, c) << '\n';
	}

	return 0;
}