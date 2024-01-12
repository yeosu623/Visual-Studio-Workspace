#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<char>> v(5, vector<char>(15));

	string s;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			v[i][j] = s[j];
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(v[j][i] != 0)
				cout << v[j][i];
		}
	}

	return 0;
}