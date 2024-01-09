#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	vector<int> v;
	int c;
	for (int i = 0; i < a; i++)
	{
		cin >> c;
		v.push_back(c);
	}

	for (const auto& n : v)
	{
		if (n < b) cout << n << ' ';
	}

	return 0;
}