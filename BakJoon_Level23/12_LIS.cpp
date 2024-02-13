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
	int v[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v[i] = input;
	}

	int cache[1000];
	cache[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int max_length = 1;
		for (int j = 0; j < i; j++)
			if (v[j] < v[i])
				max_length = max(max_length, cache[j] + 1);

		cache[i] = max_length;
	}

	cout << *max_element(cache, cache + n);
}