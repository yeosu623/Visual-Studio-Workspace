#include <iostream>
using namespace std;

uint64_t fact(uint64_t a)
{
	if (a <= 1) return 1;
	else return a * fact(a-1);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	uint64_t a;
	cin >> a;

	uint64_t b = fact(a);
	cout << b;

	return 0;
}