#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> v, pair<int, string> w)
{
	return v.first < w.first;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b;
	string s;
	vector<pair<int, string>> v;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		cin >> s;

		v.push_back({ b, s });
	}

	stable_sort(v.begin(), v.end(), compare);

	for (const auto& n : v)
		cout << n.first << ' ' << n.second << '\n';

	return 0;
}