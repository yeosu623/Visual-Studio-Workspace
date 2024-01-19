#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<uint64_t> v;
	uint64_t a;
	uint64_t b;

	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}

	if (v.size() == 1)
	{
		cout << v[0] * v[0];
		return 0;
	}

	sort(v.begin(), v.end());
	cout << v[0] * v[v.size() - 1];

	return 0;
}