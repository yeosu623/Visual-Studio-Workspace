#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int cache[50001];
	cache[0] = 0;
	for (int i = 1; i <= 50000; i++)
	{
		int answer = INT_MAX;
		for (int j = 1; j <= sqrt(i); j++)
			answer = min(answer, cache[i - j*j] + 1);
		cache[i] = answer;
	}

	int n;
	cin >> n;
	cout << cache[n];
	return 0;
}