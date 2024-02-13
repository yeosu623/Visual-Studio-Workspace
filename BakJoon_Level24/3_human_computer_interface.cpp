#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int sum[26][200001];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (s[i] == 'a' + j)
				sum[j][i + 1] = sum[j][i] + 1;
			else
				sum[j][i + 1] = sum[j][i];
		}
	}

	int q;
	cin >> q;

	while (q--)
	{
		char a;
		cin >> a;
		int idx = a - 'a';

		int l, r;
		cin >> l >> r;

		cout << sum[idx][r + 1] - sum[idx][l] << '\n';
	}

	return 0;
}