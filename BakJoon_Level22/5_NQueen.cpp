#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int n;
int board[15];

bool promising(int cdx)
{
	for (int i = 0; i < cdx; i++)
	{
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
		{
			return false;
		}
	}

	return true;
}

void nqueen(int cdx)
{
	if (cdx == n) answer++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			board[cdx] = i;
			if (promising(cdx)) nqueen(cdx + 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	nqueen(0);

	cout << answer;

	return 0;
}