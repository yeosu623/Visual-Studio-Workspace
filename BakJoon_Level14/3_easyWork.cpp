#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	set<string, greater<string>> set;
	string s, t;

	for (int i = 0; i < a; i++)
	{
		cin >> s >> t;
		if (t == "enter")
			set.insert(s);
		else
			set.erase(s);
	}

	for (const auto& n : set)
		cout << n << '\n';

	return 0;
}