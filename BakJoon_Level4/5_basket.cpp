#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	vector<int> v(a);
	int c, d, e;
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d >> e;

		for (int j = c; j <= d; j++)
		{
			v[j - 1] = e;
		}
	}

	for (const auto& n : v)
	{
		cout << n << ' ';
	}

	return 0;
}