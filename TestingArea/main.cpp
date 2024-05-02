#include <iostream>
using namespace std;

int paper[2187][2187];
int aa = 0; // -1 識 偃熱
int bb = 0; // 0 識 偃熱
int cc = 0; // 1 識 偃熱
void recursion(int x1, int y1, int x2, int y2, int len)
{
	int a = 0; // -1 偃熱
	int b = 0; // 0 偃熱
	int c = 0; // 1 偃熱
	int allSame = len * len;

	for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++)
		{
			int get = paper[i][j];
			if (get == -1) a++;
			else if (get == 0) b++;
			else if (get == 1) c++;
		}

	if (a == allSame) aa++;
	else if (b == allSame) bb++;
	else if (c == allSame) cc++;
	else
	{
		len = len / 3;
		int x10 = x1;
		int x11 = x1 + len;
		int x12 = x1 + len + len;
		int x13 = x2;
		int y10 = y1;
		int y11 = y1 + len;
		int y12 = y1 + len + len;
		int y13 = y2;

		recursion(x10, y10, x11, y11, len);
		recursion(x10, y11, x11, y12, len);
		recursion(x10, y12, x11, y13, len);

		recursion(x11, y10, x12, y11, len);
		recursion(x11, y11, x12, y12, len);
		recursion(x11, y12, x12, y13, len);

		recursion(x12, y10, x13, y11, len);
		recursion(x12, y11, x13, y12, len);
		recursion(x12, y12, x13, y13, len);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int input;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			paper[i][j] = input;
		}

	recursion(0, 0, n, n, n);
	cout << aa << '\n' << bb << '\n' << cc;

	return 0;
}