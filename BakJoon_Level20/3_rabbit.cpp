#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	string s, t;
	map<string, int> m;
	for (int i = 0; i < a; i++)
	{
		cin >> s >> t;
		if (s == "ChongChong")
		{
			m.insert({ "ChongChong", 1 });
			if (m.find(t) != m.end()) m[t] = 1;
			else m.insert({ t, 1 });
		}
		else if (t == "ChongChong")
		{
			if (m.find(s) != m.end()) m[s] = 1;
			else m.insert({ s, 1 });
			m.insert({ "ChongChong" , 1 });
		}
		else
		{
			m.insert({ s, 0 });
			m.insert({ t, 0 });
			if (m[s]) m[t] = 1;
			if (m[t]) m[s] = 1;
		}
	}

	int count = 0;
	for (const auto& n : m)
		if (n.second) count++;

	cout << count;

	return 0;
}