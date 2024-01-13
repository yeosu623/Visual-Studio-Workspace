#include <iostream>
#include <cmath>
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

	for (int i = 1; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			v.push_back(i);
			v.push_back(a / i);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if (b > v.size()) cout << 0;
	else cout << v[b - 1];

	return 0;
}