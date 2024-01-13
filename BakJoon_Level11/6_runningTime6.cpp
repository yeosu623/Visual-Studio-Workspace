#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	uint64_t n;
	cin >> n;

	cout << (n-2)*(n-1)*n/6 << '\n' << 3;

	return 0;
}