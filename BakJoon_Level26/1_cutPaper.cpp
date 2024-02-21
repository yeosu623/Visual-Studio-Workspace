#include <iostream>
using namespace std;

int paper[128][128];
int answer_white = 0;
int answer_blue = 0;
void recursion(int x1, int y1, int x2, int y2, int len)
{
	int allBlue = len * len;
	int countBlue = 0;
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			countBlue += paper[i][j];

	if (countBlue == 0) answer_white++;
	else if (countBlue == allBlue) answer_blue++;
	else
	{
		len = len / 2;
		recursion(x1, y1, x2 - len, y2 - len, len);
		recursion(x1 + len, y1, x2, y2 - len, len);
		recursion(x1, y1 + len, x2 - len, y2, len);
		recursion(x1 + len, y1 + len, x2, y2, len);
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
	cout << answer_white << '\n' << answer_blue;

	return 0;
}