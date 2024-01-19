#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

bool cmp_value(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length()) return a.first < b.first;
		else return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	string s;
	map<string, int> m;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		if (s.length() >= b)
		{
			if (m.find(s) != m.end()) m[s]++;
			else m.insert({ s, 1 });
		}
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp_value);

	for (const auto& n : v)
		cout << n.first << '\n';

	return 0;
}