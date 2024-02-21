#include <iostream>
#include <string>
using namespace std;

int image[64][64];

void recursion(int x1, int y1, int x2, int y2, int len, int quarter)
{
	int allBlack = len * len;
	int black = 0;
	for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++)
			black += image[i][j];

	if (quarter == 1) cout << '('; // recursion ½ÃÀÛ

	if (black == 0) cout << '0';
	else if (black == allBlack) cout << '1';
	else
	{
		len = len / 2;
		recursion(x1, y1, x2 - len, y2 - len, len, 1);
		recursion(x2 - len, y1, x2, y2 - len, len, 2);
		recursion(x1, y2 - len, x2 - len, y2, len, 3);
		recursion(x2 - len, y2 - len, x2, y2, len, 4);
	}

	if (quarter == 4) cout << ')'; // recursion ³¡
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			image[i][j] = s[j] - '0';
	}

	// all 0 or all 1
	int allBlack = n * n;
	int black = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			black += image[i][j];
	if (black == 0)
	{
		cout << '0';
		return 0;
	}
	else if (black == allBlack)
	{
		cout << '1';
		return 0;
	}

	// quarter
	// 0 | 1
	// -----
	// 2 | 3
	int len = n / 2;
	recursion(0, 0, n - len, n - len, len, 1);
	recursion(len, 0, n, n - len, len, 2);
	recursion(0, len, n - len, n, len, 3);
	recursion(len, len, n, n, len, 4);

	return 0;
}