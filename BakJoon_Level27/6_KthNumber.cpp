#include <iostream>
#include <algorithm>
using namespace std;

bool condition(uint64_t m, uint64_t n, uint64_t k)
{
	uint64_t sum = 0;
	uint64_t temp;
	int max_range = m < n ? m : n;
	for (int i = 1; i <= max_range; i++)
	{
		temp = m / i;
		if (temp > n) temp = n;

		sum += temp;
	}

	if (k <= sum) return true;
	else return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	uint64_t n, k;
	cin >> n >> k;

	uint64_t l = 1;
	uint64_t r = n * n;
	uint64_t m;
	while (l < r) // parametric search - find min
	{
		m = (l + r) / 2;
		if (condition(m, n, k)) r = m;
		else l = m + 1;
	}

	cout << l;
	return 0;
}