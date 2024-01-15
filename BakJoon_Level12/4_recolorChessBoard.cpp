#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	vector<vector<char>> v(a, vector<char>(b));
	char c;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> c;
			v[i][j] = c;
		}
	}

	int min = 32;
	int replace;
	// B부터 시작
	for (int i = 0; i < a - 7; i++)
	{
		for (int j = 0; j < b - 7; j++)
		{
			replace = 0;

			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2 == 0)
					{
						if (v[k][l] != 'B') replace++;
					}
					else {
						if (v[k][l] != 'W') replace++;
					}
				}
			}

			if (replace < min) min = replace;
		}
	}

	// W부터 시작
	for (int i = 0; i < a - 7; i++)
	{
		for (int j = 0; j < b - 7; j++)
		{
			replace = 0;

			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2 == 0)
					{
						if (v[k][l] != 'W') replace++;
					}
					else {
						if (v[k][l] != 'B') replace++;
					}
				}
			}

			if (replace < min) min = replace;
		}
	}

	cout << min;

	return 0;
}