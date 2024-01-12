#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<int>> v(9, vector<int>(9));
	int a;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> a;
			v[i][j] = a;
		}
	}

	int max = -1;
	int row;
	int column;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (v[i][j] > max)
			{
				max = v[i][j];
				row = i + 1;
				column = j + 1;
			}
		}
	}

	cout << max << '\n';
	cout << row << ' ' << column;

	return 0;
}