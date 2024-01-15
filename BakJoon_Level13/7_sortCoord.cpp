#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<pair<int, int>> v;
	int x, y;
	for (int i = 0; i < a; i++)
	{
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < a; i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}