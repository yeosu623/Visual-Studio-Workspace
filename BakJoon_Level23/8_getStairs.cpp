#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input;
	int v[300];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v[i] = input;
	}

	int cache[300];
	cache[0] = v[0];
	cache[1] = v[0] + v[1];
	cache[2] = max(v[0] + v[2], v[1] + v[2]);
	for (int i = 3; i < n; i++)
		cache[i] = max(cache[i - 3] + v[i - 1] + v[i], cache[i - 2] + v[i]);

	if (n != 0) cout << cache[n - 1];
	else cout << 0;

	return 0;
}