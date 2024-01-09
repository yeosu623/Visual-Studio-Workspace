#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	vector<int> v(a);
	for (int i = 0; i < a; i++)
	{
		v[i] = i + 1;
	}

	int c, d;
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d;
		swap(v[c - 1], v[d - 1]);
	}

	for (const auto& n : v)
		cout << n << ' ';

	return 0;
}