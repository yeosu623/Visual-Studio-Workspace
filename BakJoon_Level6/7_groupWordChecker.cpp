#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int sum = 0;
	char b;
	string s;
	vector<int> v(26);
	for (int i = 0; i < a; i++)
	{
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			b = s[j];
			v[b - 'a']++;
			while (b == s[j + 1]) j++;
		}

		if (*max_element(v.begin(), v.end()) == 1) sum++;

		v.clear();
		v.resize(26);
	}

	cout << sum;

	return 0;
}