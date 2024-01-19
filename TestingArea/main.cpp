#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<vector<char>> v(a, vector<char>(a, '*'));

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}
}