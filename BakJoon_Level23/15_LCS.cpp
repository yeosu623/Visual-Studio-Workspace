#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cache[1001][1001];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;

	memset(cache, 0, sizeof(cache));

	for (int i = 0; i < s1.length(); i++)
		for (int j = 0; j < s2.length(); j++)
		{
			if (s1[i] == s2[j]) cache[i + 1][j + 1] = cache[i][j] + 1;
			else cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
		}

	cout << cache[s1.length()][s2.length()];

	return 0;
}