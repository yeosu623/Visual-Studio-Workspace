#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool condition(vector<int>& v, int m, int c)
{
	int batched = 0;
	int distance = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		distance += v[i + 1] - v[i];
		if (distance >= m)
		{
			batched++;
			distance = 0;

			if (batched == c - 1) return true;
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;

	int input;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int l = 1;
	int r = 1000000000;
	int m;
	while (l < r) // parametric search
	{
		m = (l + r + 1) / 2;

		if (condition(v, m, c)) l = m;
		else r = m - 1;
	}

	cout << l;

	return 0;
}