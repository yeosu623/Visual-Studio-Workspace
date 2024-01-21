#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void deleteStar(vector<vector<char>>& v, int x, int y, int len, int remain)
{
	if (remain == 0) return;

	int hlen = len / 2;
	for (int i = x - hlen; i <= x + hlen; i++)
		for (int j = y - hlen; j <= y + hlen; j++)
			v[i][j] = ' ';

	deleteStar(v, x - len, y - len, len / 3, remain - 1);
	deleteStar(v, x - len, y, len / 3, remain - 1);
	deleteStar(v, x - len, y + len, len / 3, remain - 1);
	deleteStar(v, x, y - len, len / 3, remain - 1);
	deleteStar(v, x, y + len, len / 3, remain - 1);
	deleteStar(v, x + len, y - len, len / 3, remain - 1);
	deleteStar(v, x + len, y, len / 3, remain - 1);
	deleteStar(v, x + len, y + len, len / 3, remain - 1);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	vector<vector<char>> v(a, vector<char>(a, '*'));
	int x = v.size() / 2;
	int y = v.size() / 2;
	int len = v.size() / 3;
	int remain = (int)pow(a, 1.0 / 3);
	deleteStar(v, x, y, len, remain);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
			cout << v[i][j];
		cout << '\n';
	}

	return 0;
}