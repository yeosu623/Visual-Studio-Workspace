#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<int> v;
	int b;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}

	sort(v.begin(), v.end());

	for (const auto& n : v)
		cout << n << '\n';

	return 0;
}