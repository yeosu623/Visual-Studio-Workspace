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

	vector<int> v;
	for (int i = 1; i <= a; i++)
	{
		v.push_back(i);
	}

	int c, d;
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d;
		reverse(v.begin() + c - 1, v.begin() + d);
	}

	for (const auto& n : v)
	{
		cout << n << ' ';
	}

	return 0;
}