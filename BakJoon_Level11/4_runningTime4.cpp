#include <iostream>
using namespace std;

int main()
{
	long n;
	cin >> n;

	long sum = 0;
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			sum++;

	cout << sum << '\n' << 2;
}