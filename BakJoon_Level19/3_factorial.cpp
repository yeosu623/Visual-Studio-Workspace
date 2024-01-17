#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	uint64_t b = 1;
	for (int i = 1; i <= a; i++)
		b *= i;

	cout << b;

	return 0;
}