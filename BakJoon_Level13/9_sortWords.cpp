#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string s, string t)
{
	if (s.length() == t.length())
		return s < t;
	else
		return s.length() < t.length();
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<string> v;
	string s;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for (const auto& n : v)
		cout << n << '\n';

	return 0;
}