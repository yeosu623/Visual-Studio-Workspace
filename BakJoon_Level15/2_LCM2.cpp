#include <iostream>
using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
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

	uint64_t a, b;
	cin >> a >> b;

	cout << (a * b) / gcd(a, b);

	return 0;
}