#include <iostream>
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
	int cache[500][500];

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			cin >> input;
			cache[i][j] = input;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1 - i; j++)
			cache[n - 2 - i][j] += max(cache[n - 1 - i][j], cache[n - 1 - i][j + 1]);

	cout << cache[0][0];

	return 0;
}