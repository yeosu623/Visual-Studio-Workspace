#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int coin;
	int cache[10001];
	memset(cache, 0, sizeof(cache));
	cache[0] = 1;
	while (n--)
	{
		cin >> coin;
		for (int i = coin; i <= k; i++)
			cache[i] += cache[i - coin];
	}

	cout << cache[k];
	return 0;
}
