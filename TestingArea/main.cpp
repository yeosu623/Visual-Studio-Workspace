#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> cache(1000001);
	cache[1] = 0;
	cache[2] = 1;
	cache[3] = 1;
	for (int i = 4; i <= 1000000; i++)
	{
		int temp = INT_MAX;
		if (i % 3 == 0) temp = min(temp, cache[i / 3] + 1);
		if (i % 2 == 0) temp = min(temp, cache[i / 2] + 1);
		temp = min(temp, cache[i - 1] + 1);

		cache[i] = temp;
	}

	int n;
	cin >> n;

	cout << cache[n];

	return 0;
}