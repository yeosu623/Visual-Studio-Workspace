#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}

	vector<int> v(26);
	for (int i = 0; i < s.length(); i++)
	{
		v[s[i] - 'a']++;
	}

	int max = *max_element(v.begin(), v.end());
	int idx = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == max && idx == -1)
		{
			idx = i;
			continue;
		}

		if (v[i] == max && idx != -1)
		{
			idx = -1;
			break;
		}
	}

	if (idx == -1) cout << '?';
	else cout << (char)('A' + idx);

	return 0;
}