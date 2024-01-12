#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int b, c;
	vector<vector<int>> v(100, vector<int>(100));
	for (int i = 0; i < a; i++)
	{
		cin >> b >> c;

		for (int j = b; j < b + 10; j++)
		{
			for (int k = c; k < c + 10; k++)
			{
				v[j][k] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			sum += v[i][j];
		}
	}

	cout << sum;

	return 0;
}