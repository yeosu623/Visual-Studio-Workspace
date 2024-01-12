#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	vector<vector<int>> v(a, vector<int>(b));
	vector<vector<int>> w(a, vector<int>(b));
	vector<vector<int>> x(a, vector<int>(b));

	int c;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> c;
			v[i][j] = c;
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> c;
			w[i][j] = c;
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			x[i][j] = v[i][j] + w[i][j];
			cout << x[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}